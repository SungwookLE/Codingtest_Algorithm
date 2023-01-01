#include <iostream>
#include <vector>
#include <algorithm>


// template <typename T>
class prob_11399{

    public:
    prob_11399(){
        std::cin >> N;
        P.resize(N,0);
        for(int i = 0 ; i < N ; ++i)
            std::cin >> P[i];

        std::sort(P.begin(), P.end(), [](auto a, auto b){
            if ( a< b)
                return true;
            else
                return false;
        });
        
    }
    void solver(){

        
        for(int i = 0 ; i < N; ++i){
            ans += P[i];
            for(int j =0 ; j < i ; ++j)
                ans+= P[j];
        }
        std::cout << ans << std::endl;

    }

    

    private:
    int N;
    std::vector<int> P;
    int ans=0;


};

int main(){
    prob_11399 solver;
    solver.solver();


    return 0;
}
