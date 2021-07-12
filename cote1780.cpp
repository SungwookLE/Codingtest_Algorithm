#include <iostream>
#include <vector>
//쿼드트리와 비슷한데 4개 대신 9개로 나누는 문제

class solver_1780{
public:
void insert(){
    std::cin >> N;
    std::vector<int> rect_one(N);
    for(int i = 0 ; i < N ; ++i){
        for(int j =0 ; j < N ; ++j)
            std::cin >> rect_one[j];
        rect.push_back(rect_one);
    }

    ans.resize(3,0);
}

void monitor(){
    std::cout << "MONITOR: \n";
    for(auto one : rect){
        for(auto ele : one)
            std::cout << ele << " ";
        std::cout << std::endl;
    }
}

void ninethTree(int beginX, int beginY, int size){
    //std::cout << "beginX:" << beginX << " beginY:"<<beginY << " size:" <<size<<std::endl;

    int beginData = rect[beginY][beginX];
    bool isCombinable=true;

    for(int y=beginY; y<(beginY+size); ++y){
        for (int x=beginX; x<(beginX+size); ++x){
            if (beginData != rect[y][x]){
                isCombinable=false;
                break;
            }
        }
        if (isCombinable==false)
            break;
    }

    if (isCombinable==true){
        if (beginData == -1)
            ans[0]+=1;
        else if (beginData == 0)
            ans[1]+=1;
        else if (beginData == 1)
            ans[2]+=1;
    }
    else{
        int one_third_size = size / 3;
        ninethTree(beginX,                                  beginY,                                 one_third_size);
        ninethTree(beginX+one_third_size,                   beginY,                                 one_third_size);
        ninethTree(beginX+one_third_size+one_third_size,    beginY,                                 one_third_size);
        ninethTree(beginX,                                  beginY+one_third_size,                  one_third_size);
        ninethTree(beginX+one_third_size,                   beginY+one_third_size,                  one_third_size);
        ninethTree(beginX+one_third_size+one_third_size,    beginY+one_third_size,                  one_third_size);
        ninethTree(beginX,                                  beginY+one_third_size+one_third_size,   one_third_size);
        ninethTree(beginX+one_third_size,                   beginY+one_third_size+one_third_size,   one_third_size);
        ninethTree(beginX+one_third_size+one_third_size,    beginY+one_third_size+one_third_size,   one_third_size);
    }

}

void print_ans(){
    std::cout << ans[0] << "\n" << ans[1] << std::endl << ans[2] << std::endl;
}

int N;


private:
    std::vector<std::vector<int>> rect;
    std::vector<int> ans;
};

int main(){
    solver_1780 solver;
    solver.insert();
    solver.ninethTree(0,0,solver.N);
    solver.print_ans();
    return 0;
}