#include <iostream>
#include <vector>

//백트래킹
// (9/29) 다시 풀려고 해도 역시 쉽지 않아..

class prob_15649{
    public:
    prob_15649(){
        std::cin >> N >> M;

        visited.resize(N,0);
    }

    void solver(int n, std::vector<int>& temp){

        if ( n == M){
            ans.push_back(temp);
            return;
        }

        else{
            for (int i =1 ; i <= N ; ++i){
                if (visited[i-1] ==0){
                    temp[n] = i;
                    visited[i-1] = 1;
                    solver(n+1, temp);
                    visited[i-1] = 0;
                }
            }

        }
    }

    void print_ans(){
        for(auto a: ans){
            for(auto b: a){
                std::cout << b << " ";
            }
            std::cout << std::endl;
        }
    }

    int N, M;
    
    private:
    std::vector<int> visited;
    std::vector<std::vector<int>> ans;

};

int main(){
    prob_15649 solver;

    std::vector<int> temp(solver.M,0);
    solver.solver(0, temp);
    solver.print_ans();

    return 0;
}