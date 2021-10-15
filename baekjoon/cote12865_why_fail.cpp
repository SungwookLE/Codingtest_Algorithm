#include <iostream>
#include <vector>
// 이거 왜 틀렸다는 거지 #12865

class solver_12865{
    public:
        solver_12865(std::vector<std::vector<int>> cand, int N_in, int K_in): tray(cand), N(N_in), K(K_in) {DP.resize(N,0);}

        int solver(){
            int answer = 0;
            for (int i = 0 ; i < N ; ++i){

                int temp_weight =0, temp_value =0;
                for (int j = i ; j >= 0 ; --j){
                    temp_weight += tray[j][0];
                    temp_value  += tray[j][1];

                    if (temp_weight <= K){
                        if (DP[i] < temp_value){
                            DP[i] = temp_value;
                        }

                    }
                    else{
                        temp_weight-=tray[j][0];
                        temp_value -= tray[j][1];
                    }

                }

                answer = std::max(answer, DP[i]);
            }

            return answer;
        }

        void debugger(){
            std::cout << "DEBUG: \n";
            for (auto ele: DP){
                std::cout << ele << " ";
            std::cout << std::endl << std::endl;
            }
        }


    private:
        std::vector<std::vector<int>> tray;
        std::vector<int> DP;
        int N, K;

};

int main(){

    int N ,K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> tray;

    for(int i = 0 ; i < N ; ++i){
        std::vector<int> res(2);
        std::cin >> res[0] >> res[1];
        tray.push_back(res);
    }

    int answer;
    solver_12865 solver(tray, N, K);
    answer= solver.solver();
    solver.debugger();

    std::cout << answer <<std::endl;

    return 0;
}
