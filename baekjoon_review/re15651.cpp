#include <iostream>
#include <vector>
//백트래킹
//백트래킹은 일종의 재귀호출 구조를 이용하여 푸는 문제를 말하는데, 
//재귀에서 끝나지 않고 특별한 조건들이 재귀호출되면서 반영되게끔 하는 것을 말한다.


class prob_15651{
    public:
    prob_15651(){
        std::cin >> N >> M;
        temp.resize(M,0);
    }



    void solver(int n){
        if ( n == M){
            ans.push_back(temp);
            return;
        }
        else{


            for(int i = 0 ; i < N ; ++i){
                temp[n] = i+1;
                solver(n+1);
            }

        }
    }

    void print_ans(){
        for(auto row: ans){
            for(auto ele: row)
                std::cout << ele << " ";
            std::cout << std::endl;
        }
    }

    private:
    int N, M;
    std::vector<int> temp;
    std::vector<std::vector<int>> ans;

};

int main(){
    prob_15651 solver;
    solver.solver(0);
    solver.print_ans();

    return 0;
}