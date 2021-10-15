#include <iostream>
#include <vector>

class bitonic{
    public:
        bitonic(int ea, std::vector<int> given_arr){
            std::vector<int> res(ea+1, 0);
            DP_up=res;
            DP_down=res;
            arr = given_arr;
            N=ea;
        }
        //증가수열
        int solver_up(int cnt){
            if(DP_up[cnt] !=0)
                return DP_up[cnt];
            DP_up[cnt] = 1;
            for(int i = cnt-1; i >= 1 ; i --){
                if ( arr[i] < arr[cnt])
                    DP_up[cnt] = std::max(DP_up[cnt], bitonic::solver_up(i)+1);
            }
            return DP_up[cnt];
        }
        //감소수열
        int solver_down(int cnt){
            if(DP_down[cnt] != 0)
                return DP_down[cnt];
            DP_down[cnt] = 1;
            for (int i = cnt+1; i <= N ; i++){
                if (arr[i] < arr[cnt])
                    DP_down[cnt]= std::max(DP_down[cnt], bitonic::solver_down(i)+1);
            }
            return DP_down[cnt];
        }
        std::vector<int> DP_up;
        std::vector<int> DP_down;
    private:
        std::vector<int> arr;
        int N;
};

int main(){
    int N;
    std::cin >> N;
    std::vector<int> arr(N+1,0);
    for(int i =1 ; i <= N ; ++i)
        std::cin >> arr[i];

    bitonic bitonic_solver(N,arr);
    for(int i = N ; i >=1 ; --i)
        bitonic_solver.solver_up(i);

    for(int i = 0 ; i <= N ; ++i)
        bitonic_solver.solver_down(i);

    std::cout << "DEBUG:" <<std::endl;
    std::cout << "UP: " ;
    for(auto d : bitonic_solver.DP_up)
        std::cout << d <<  " ";
    std::cout << std::endl<<"DOWN: " ;
    for(auto d : bitonic_solver.DP_down)
        std::cout << d <<  " ";
    std::cout << std::endl;

    int max_val = 0;
    for(int i = 1; i <= N ; ++i){
        if ( max_val < (bitonic_solver.DP_up[i] + bitonic_solver.DP_down[i]) )
            max_val = (bitonic_solver.DP_up[i] + bitonic_solver.DP_down[i]);
    }
    std::cout << max_val-1;
    return 0;
}

/*
#11054: 가장 긴 바이토닉 부분 수열
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... < Sk < Sk+1 < Sn 을 만족한다면,
그 수열을 바이토닉 수열이라고 한다.

예를 들어, {10, 20, 30, 25, 20}과
{10, 20, 30, 40}, {50, 40, 25, 10}은 바이토닉 수열이지만,
{1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30}은
바이토닉 수열이 아니다.

수열 A가 주어졌을 때, 그 수열의 부분 수열 중
바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

입력>>
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다.
(1 <= ㅜ <= 1000, 1 <= Ai <= 1000)

출력>>
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

예제>>
    문제: {1 5 2 1 4 3 4 5 2 1}
    정답: 7개 {1 2 3 4 5 2 1}

풀이>>
https://coding-insider.tistory.com/entry/%EB%B0%B1%EC%A4%80-11054-%EA%B0%80%EC%9E%A5-%EA%B8%B4-%EB%B0%94%EC%9D%B4%ED%86%A0%EB%8B%89-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4-CC-%E2%98%85%E2%98%85%E2%98%85
*/


