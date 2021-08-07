#include <iostream>
#include <vector>
#include <algorithm>

class solver_12015{

public:
solver_12015(int _N, std::vector<int> _A){
    N = _N;
    A = _A;
    DP.resize(N,0);
}
int solver(){
    int answer =0 ;
    for (int i =0 ; i < N; ++i){
        int DP_max = 0;
        for (int j = 0 ; j <= i ; ++j){
            if (A[i] > A[j]){
                if (DP_max <= DP[j]){
                    DP_max = DP[j];
                }
            }
        }
        DP[i] = DP_max+1;
        debug_dp();
        answer = std::max(answer, DP[i]);
    }
    return answer;
}

void debug_dp(){
    std::cout <<"DP: \n";
    for(auto a: DP)
        std::cout << a << " " ;
    std::cout << std::endl;
}


private:
int N;
std::vector<int> DP;
std::vector<int> A;

};

int main(){
    int N;
    std::cin >> N;

    std::vector<int> A(N,0);
    for(int i =0 ; i < N ; ++i)
        std::cin >> A[i];
    
    solver_12015 solver(N, A);
    std::cout << solver.solver() <<std::endl;


    return 0;
}