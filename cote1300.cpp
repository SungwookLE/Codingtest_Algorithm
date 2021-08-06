#include <iostream>
#include <vector>
#include <algorithm>


class solver_1300{
    public:
    solver_1300(int _N, long long _K){
        N = _N;
        K = _K;

    }

    void solver(){

        int start = 1;
        int end = K;
        int mid;
        int result;

        while ( start <= end){
            mid = (start+end)/2;
            long long num = 0;

            
            std::cout << "mid: " << mid << std::endl;
            for(int i = 1 ; i <= N; ++i){
                num += std::min(mid/i, N);
                std::cout << num << " " ;
            }
            std::cout << std::endl;


            if (num < K)
                start = mid+1;
            else if ( num >= K){
                result = mid;
                end = mid -1;
            }
            std::cout << "result: " << result << std::endl;
        }

        std::cout << result << std::endl;
    }

    private:
    int N;
    long long K;
};

int main(){
    int N;
    long long K;

    std::cin >> N >>K;
    solver_1300 solver(N, K);
    solver.solver();

    return 0;
}