#include <iostream>
#include <vector>
#include <algorithm>


class solver_2110{
    public:
    solver_2110(long long _C, std::vector<long long> _home){
        C= _C;
        home = _home;

        std::sort(home.begin(), home.end(), [](auto a , auto b){
            if(a<b)
                return true;
            else
                return false;
        });
    }

    void solver(){

        long long start = 0;
        long long end = home.back();
        long long mid;

        while (start <= end){

            mid = (start+end)/2;

            int count = 1;
            long long basis = home[0];

            for(int i =1 ; i < home.size() ; ++i){
                int distance = home[i] - basis;
                if (distance >= mid){
                    count++;
                    basis = home[i];
                }
            }

            if (count < C)
                end = mid-1;
            else
                start = mid+1;
        }

        std::cout << end << std::endl;
    }
    private:
    long long C;
    std::vector<long long> home;

};

int main(){
    long long N, C;
    std::cin >> N >> C;

    std::vector<long long> home(N);
    for(int i = 0 ; i < N ; ++i)
        std::cin >> home[i];
    
    solver_2110 solver(C, home);
    solver.solver();

    return 0;
}