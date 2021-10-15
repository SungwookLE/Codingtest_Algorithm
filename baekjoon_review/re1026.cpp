#include <iostream>
#include <vector>
#include <algorithm>

class prob_1026{

    public:
    prob_1026(){
        std::cin >> N;
        A.resize(N,0);
        B.resize(N,0);

        for(int i =0 ; i < N ; ++i)
            std::cin >> A[i];
        
        for(int i =0 ; i < N ; ++i)
            std::cin >> B[i];

    }

    void solver(){

        std::sort(A.begin(), A.end(), [](int a, int b){
            if ( a>b)
                return true;
            else
                return false;
        });
        std::sort(B.begin(), B.end());
        

        int ans = 0;
        for(int i =0 ; i < N ; ++i){
            ans += (A[i]*B[i]);
        }
        std::cout << ans << std::endl;

        return;
    }

    private:
    int N;
    std::vector<int> A, B;


};

int main(){
    prob_1026 solver;
    solver.solver();

    return 0;
}