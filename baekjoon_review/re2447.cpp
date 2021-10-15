//https://www.acmicpc.net/probblem/2447
// recursion
// 조금 꼬인 형태의 recursion 인데, 현재의 star가 다음의 basis가 되서 재귀되는 구조

#include <iostream>
#include <vector>

class prob_2447{
public:
    prob_2447(){
        std::cin >> N;
    }

    void solver(){
        int idx = 3;
        recursion(idx, N);
    }

    void recursion(int count, int N){
        if (count > N){
            print_star();
            return;
        }
        else if (count==3){
            for(int row = 0 ; row< count ; ++row){
                std::vector<char> temp;
                for(int col =0 ; col < count/3 ; ++col)
                    temp.insert(temp.end(), basis[row].begin(), basis[row].end());
                    
                star.push_back(temp);

                if ( row >= count/3 && row < 2*count/3){
                    for(int col = count/3 ; col < (2*count/3); ++col){
                        star[row][col] = ' ';                       
                    }
                }
            }
            basis = star;
        }
        else{
            star.clear();
            for(int row = 0 ; row< (count) ; ++row){
                std::vector<char> temp;
                for(int col =0 ; col < 3 ; ++col){
                    temp.insert(temp.end(), basis[row%(count/3)].begin(), basis[row%(count/3)].end());
                }

                star.push_back(temp);

                if ( row >= count/3 && row < 2*count/3){
                    for(int col = count/3 ; col < (2*count/3); ++col){
                        star[row][col] = ' ';                       
                    }
                }
            }
            basis = star;
        }
        recursion(count*3, N);
    }

    void print_star(){
        for(auto row: star){
            for(auto col: row)
                std::cout << col ;
            std::cout << std::endl;
        }
    }

private:
    int N;
    std::vector<std::vector<char>> star;
    std::vector<std::vector<char>> basis
                    = {{'*','*','*'},
                    {'*',' ','*'},
                    {'*','*','*'}};
};

int main(){
    prob_2447 solver;
    solver.solver();


    return 0;
}