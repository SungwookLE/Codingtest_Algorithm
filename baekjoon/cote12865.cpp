#include <iostream>
#include <vector>

class solver_12865{
    public:
        solver_12865(std::vector<std::pair<int,int>> cand, int N_in, int K_in, int max_W): tray(cand), N(N_in), K(K_in) {DP.resize(max_W+1,0);}

        int solver(){
            for (int i = 0 ; i < N ; ++i){
                for (int j = K ; j >= 1 ; --j){

                    if ( tray[i].first <= j )
                        DP[j] = std::max(DP[j], DP[j-tray[i].first] + tray[i].second);
                        // 아 그냥 DP에다가 다 저장하고 출력할때만 커팅해서 내보내면 되는구나,

                }
            }

            return DP[K];
        }

        void debugger(){
            std::cout << "DEBUG: \n";
            for (auto ele: DP){
                std::cout << ele << " ";
            std::cout  << std::endl;
            }
        }


    private:
        std::vector<std::pair<int,int>> tray;
        std::vector<int> DP;
        int N, K;

};

int main(){

    int N ,K;
    std::cin >> N >> K;

    std::vector<std::pair<int,int>> tray;

    int max_W=0;
    for(int i = 0 ; i < N ; ++i){
        int W, V;
        std::cin >> W >> V;
        tray.push_back(std::make_pair(W,V));

        if (max_W < W)
            max_W = W;

    }

    int answer;
    solver_12865 solver(tray, N, K, max_W);
    answer= solver.solver();
    solver.debugger();

    std::cout << answer <<std::endl;

    return 0;
}
