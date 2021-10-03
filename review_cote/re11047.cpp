#include <iostream>
#include <vector>

//그리디 알고리즘 #1

class prob_11047{
    public:
        prob_11047(){
            std::cin >> N >> K;
            coins.resize(N,0);

            for(int i=0 ; i < N ; ++i)
                std::cin >> coins[i];
        }

        void solver(){
            while (K!=0){
                if ( K >= coins.back()){
                    K -= coins.back();
                }
                else{
                    while ( coins.back() > K ){
                        if (coins.empty()){
                            std::cout << -1 << std::endl;
                            return;
                        }
                        coins.pop_back();
                    }
                    K -= coins.back();
                }
                // std::cout << K << std::endl; 
                ans+=1;
            }
            std::cout << ans << std::endl;
        }

    private:
        int N;
        long long K;
        std::vector<int> coins;
        int ans =0;
};

int main(){
    prob_11047 solver;
    solver.solver();

    return 0;
}