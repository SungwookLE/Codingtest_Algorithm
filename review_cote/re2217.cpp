#include <iostream>
#include <vector>
#include <algorithm>

class solver_2217{
    public:
    solver_2217(){
        std::cin >> N;
        weights.resize(N,0);
        for(int i=0 ; i < N ; ++i)
            std::cin >> weights[i];

        std::sort(weights.begin(), weights.end());
    }

    void solver(){

        int load=weights[0]*N, this_load;
        for(int i = 0 ; i < N ; ++i){

            this_load = weights[i] * (N-i);
            if ( load < this_load){
                load = this_load;
            }
        }
        std::cout << (load) << std::endl;

        return;
    }

    private:
    int N;
    std::vector<int> weights;
};

int main(){
    solver_2217 solver;
    solver.solver();





    return 0;
}