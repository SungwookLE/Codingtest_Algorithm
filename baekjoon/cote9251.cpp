#include <iostream>
#include <vector>

class solver_9251{
    public:
    solver_9251(std::string a, std::string b): A(a), B(b){

        std::vector<int> res(A.length()+1, 0);
        DP.resize(B.length()+1,res);
        }

    void print_string(){
        std::cout << "A: \n";
        std::cout << A << std::endl;
        std::cout << "B: \n";
        std::cout << B << std::endl;
    }

    void debug_print_dp(){
        std::cout << "DEBUG: \n";
        for(auto row : DP){
            for (auto col : row)
                std::cout << col << " ";
            std::cout << std::endl;
        }
    }

    int get_logest_common_subsequence(){
        for(int i =1 ; i <= B.length() ; ++i){
            for (int j = 1 ; j <= A.length() ; ++j){
                if (B[i-1] == A[j-1]){
                    DP[i][j] = DP[i-1][j-1]+1;
                }
                else{
                    DP[i][j] = std::max(DP[i-1][j] , DP[i][j-1]);
                }
            }
        }
        return DP[B.length()][A.length()];
    }

    private:
    std::string A, B;
    std::vector<std::vector<int>> DP;
};

int main(){
    std::string A, B;
    std::cin >> A;
    std::cin >> B;

    solver_9251 solver(A, B);
    int answer= solver.get_logest_common_subsequence();
    solver.debug_print_dp();
    std::cout << answer << std::endl;

    return 0;
}

/*
문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

예제 입력 1 
ACAYKP
CAPCAK
예제 출력 1 
4

REF>>
https://far-simple.tistory.com/37

와 이건 점화식 생각을 해내기가 너무 어렵겟는데, 
*/