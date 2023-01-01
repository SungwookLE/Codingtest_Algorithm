#include <iostream>
#include <vector>

// 팩토리얼
// 대표적인 recursion 형태 (재귀)


class prob_10872{

public:
    prob_10872(){
        std::cin >> N;
    }
    void solver(int n){
        if( n == 0){
            answer *= 1;
            std::cout << answer << std::endl;
        }
        else{
            answer*=n;
            solver(n-1);
        }
    }

    // 대표적인 recursion 형태 (재귀)
    int N;

private:
    int answer = 1;
    
};


int main(){
    prob_10872 solver;
    solver.solver(solver.N);

    return 0;
}