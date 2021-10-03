#include <iostream>
#include <vector>

class prob_13305{
    public:
    prob_13305(){
        std::cin >> N;
        roads.resize(N-1,0);
        costs.resize(N,0);
        for(int i =0 ; i <(N-1); ++i)
            std::cin >> roads[i];
        
        for(int i =0 ; i < N ; ++i)
            std::cin >> costs[i];
    }

    void solver(){
        long long cost = costs[0];
        ans = cost * roads[0];
        
        for(int i = 1 ; i < (N-1) ; ++i){
            if (costs[i] >= cost ){
                //do nothing
            }

            else
                cost = costs[i];

            ans += (long long)cost * roads[i];            
        }
        std::cout << ans << std::endl;

    }

    private:
    int N;
    std::vector<long long> roads;
    std::vector<long long> costs;
    long long ans;

};

int main(){
    prob_13305 solver;
    solver.solver();

    return 0;
}