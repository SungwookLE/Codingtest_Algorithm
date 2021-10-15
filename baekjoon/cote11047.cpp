#include <iostream>
#include <vector>


class solver_11047{

    public:
    solver_11047(int N_in, int K_in): N(N_in), K(K_in){DP.resize(N,1);}
    void insert_array(){
        int res;
        for(int i =0 ; i < N ; ++i){
            std::cin >> res;
            arr.push_back(res);
        }
        return;
    }

    int solver(){

        int answer=K;
        for (int i = 0 ; i < N ; ++i){

            int temp_value =0;
            for (int j = i ; j >= 0 ; --j){
                temp_value += arr[j];

                if (temp_value < K){
                    DP[i] +=1;
                    ++j;
                } 
                else if (temp_value > K){
                    temp_value -= arr[j];
                }
            }
            if (temp_value != K)
                    DP[i] = N;
                
            answer = std::min(DP[i], answer);
        }
        return answer;
    }

    void debugger(){
        std::cout << "DEBUG: \n";

        for (auto a : DP)
            std::cout << a << " ";
        
        std::cout<<std::endl;
    }

    private:
    int N, K;
    std::vector<int> arr;
    std::vector<int> DP;
};


int main(){
    int N, K;
    std::cin >> N >> K;

    solver_11047 solver(N,K);
    solver.insert_array();
    int answer = solver.solver();
    //solver.debugger();
    std::cout << answer << std::endl;

    return 0;
}

/*
CATEGORY: GREEDY ALGORITHM
>> ('21.6/7) 맞긴 맞았는데 그리디로 풀진 않았음,, 이건 뭐 DP도 아니기도하고;;; 그리디가 뭔지부터좀 찾아보자 #11047

문제>>
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력>>
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

출력>>
첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.


*/