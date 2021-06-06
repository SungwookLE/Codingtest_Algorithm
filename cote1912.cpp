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

/*
아래는 이중 포문으로 푼건데, DP가 아니다보니, 이중포문이 필요하게 되엇고 문제에서의 시간제한에 초과 O(n^2)가 되므로,
포문을 하나만 쓰려면 DP를 써야하는데, 와 역시나 쉽지가 않네 한시간 이상 시간 썻는데 ㅠ 결국 답지 참고해서 풀었다. (5/30)


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
        for (int i = 0 ; i < N ; ++i){
            int temp_answer =subsequence[i];
            int temp_sum =0;
            for (int j=i ; j >= 0 ; --j){
                temp_sum += subsequence[j];
                if (temp_answer < temp_sum)
                    temp_answer = temp_sum;
            }
            DP[i] = temp_answer;
            answer = std::max(DP[i], answer);
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
    //solver.debugger_DP();
    //std::cout << "ANSWER: \n";
    std::cout << ans+1 << "\n";

    return 0;
}

문제: #1912: 연속합
n개의 정수로 이루어진 임의의 수열이 주어진다.
우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다.
단, 수는 한 개 이상 선택해야 한다.

예를 들어서,
10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자.
여기서 정답은 12+21인 33이 정답이 된다.

입력>>
첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다.
수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.


*/