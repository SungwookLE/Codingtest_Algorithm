#include <iostream>
#include <vector>

/*
문제>>
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력>>
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력>>
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

예제 입력 1>> 
6
10 20 10 30 20 50
예제 출력 1>>
4
*/

class solver_11053{
    public:
        solver_11053(std::vector<int> given_arr){
            A=given_arr;
            N = A.size();
            DP.resize(N,0);
        }
        int getter_longest_incremental_set(){
            int answer= 0;
            for(int i =0 ; i < N ; ++i){
                int DP_max=0;
                for(int j =0 ; j <= i ; ++j){
                    if (A[i] > A[j]){
                        if (DP_max < DP[j])
                            DP_max = DP[j];
                    }
                }
                DP[i] = DP_max+1;
                answer = std::max(answer, DP[i]);
            }
            return answer;
        }
        void printer_DP(){
            std::cout << "DEBUG: ";
            for (auto element : DP)
                std::cout << element << " ";
            std::cout << std::endl;
        }
    private:
        std::vector<int> A;
        std::vector<int> DP;
        int N;
};

int main(){
    int N;
    std::cin >> N;

    std::vector<int> A;
    int temp;
    for(int i = 0; i <N ; ++i){
        std::cin >> temp;
        A.push_back(temp);
    }
    
    solver_11053 solver(A);
    int answer= solver.getter_longest_incremental_set();
    solver.printer_DP();
    std::cout << "ANSWER: " << answer << std::endl;

    return 0;
}