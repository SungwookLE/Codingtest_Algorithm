#include <iostream>
#include <vector>

// #11051 이항계수2, 동적프로그래밍을 쓰라는데?
/*
문제
자연수 N과 정수 K가 주어졌을 때 이항 계수 
를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력>>
첫째 줄에 과 가 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ K ≤ N)
*/
class solver_11051{
    public:
    solver_11051(){
        std::vector<int> v(1001,0);
        DP.resize(1001, v);
    }

    void insert_number(){
        std::cin >> N >> K;
    }

    void solver(){

        // 파스칼의 삼각형
        // REF: https://hevton.tistory.com/377

        for(int i =1 ; i <= N; ++i){
            for(int j =0 ; j <= i; ++j){

                if ( j == 0 | i ==j )
                    DP[i][j] = 1;
                else
                    DP[i][j] = (DP[i-1][j] + DP[i-1][j-1]) % 10007;

            }
        }

        std::cout << DP[N][K] << std::endl;
    }

    private:
    int N, K;
    std::vector<std::vector<int>> DP;
    
};

int main(){
    solver_11051 solver;
    solver.insert_number();
    solver.solver();


}

