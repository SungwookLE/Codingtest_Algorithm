#include <iostream>
#include <vector>
#include <algorithm>

class solver_1654{
public:
solver_1654(std::vector<long long> _ran , long long _N){
    ran = _ran;
    N = _N;
}

void solver(){
    std::sort(ran.begin(), ran.end(), [](long long a, long long b){
        if ( a <b)
            return true;
        else
            return false;
    });

    long long start = 1;
    long long end = ran.back();

    long long mod;
    long long rem;
    while( start<=end){
        rem =(start+end)/2;

        mod = 0;
        for(int i = 0 ; i < ran.size() ; ++i)
            mod+=ran[i] / rem ;

        if ( mod < N )
            end= rem-1;
        else if ( mod >= N)
            start = rem+1;
    }

    std::cout << end << std::endl;
    return;
}



private:
std::vector<long long> ran;
long long N;
};

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    long long K, N;

    std::cin >> K >> N;
    std::vector<long long> ran(K);

    for (int i =  0 ; i < K ; ++i)
        std::cin >> ran[i];

    solver_1654 solver(ran, N);
    solver.solver();
    
    return 0;
}