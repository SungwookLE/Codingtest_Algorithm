#include <iostream>
#include <vector>

class solver_1912{
    public:
    solver_1912(int ea){
        N=ea;
        subsequence.resize(N,0);
        DP.resize(N,0);
        for (int i = 0 ; i < N; ++i)
            std::cin >> subsequence[i] ;
    }
    int solver(){
        int answer =subsequence[0];
        DP[0] = subsequence[0];
        for (int i = 1 ; i < N ; ++i){
            DP[i]= std::max(DP[i-1]+subsequence[i], subsequence[i]);
            answer = std::max(answer, DP[i]);
        }
        return answer;
    }

    void debugger_DP(){
        std::cout << "DEBUG(DP): \n";
        for(auto a : DP)
            std::cout << a << " ";
        std::cout << std::endl;
    }

    private:
    int N;
    std::vector<int> subsequence;
    std::vector<int> DP;
};

int main(){
    
    int N;
    std::cin >> N;
    solver_1912 solver(N);
    int ans = solver.solver();
    solver.debugger_DP();
    std::cout << "ANSWER: \n";
    std::cout << ans << "\n";

    return 0;
}