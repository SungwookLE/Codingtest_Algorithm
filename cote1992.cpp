#include <iostream>
#include <vector>

class solver_1992{
public:
public:
    void insert(){
        std::cin >> N;
        for(int j=0; j < N ; ++j){
            std::string one;
            std::cin >> one;
            std::vector<int> one_rect(N);
            for(int i=0 ; i < N ; ++i){
                one_rect[i] = (one[i]-'0');
            }
            rect.push_back(one_rect);
        }
    }

    void QuadTree(int beginX, int beginY, int size){
        int beginData = rect[beginY][beginX];
        bool isCombinable = true;

        for (int i = beginX ; i < beginX+size ; ++ i){
            for (int j = beginY; j < beginY+size; ++j){
                if (beginData != rect[j][i]){
                    isCombinable = false;
                    break;
                }
            }
            if (isCombinable==false)
                break;
        }

        if (isCombinable)
            std::cout << beginData;
        else{
            int halfSize = size/2;
            std::cout << "(";
            QuadTree(beginX, beginY, halfSize);
            QuadTree(beginX+halfSize, beginY, halfSize);
            QuadTree(beginX, beginY+halfSize, halfSize);
            QuadTree(beginX+halfSize, beginY+halfSize, halfSize);
            std::cout << ")";
        }
    }


int N;
    private:
    std::vector<std::vector<int>> rect;
    int white = 0 , blue =0;

};

int main(){
    solver_1992 solver;
    solver.insert();
    solver.QuadTree(0,0,solver.N);
    return 0;
}