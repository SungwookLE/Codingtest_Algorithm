#include <iostream>
#include <vector>
#include <algorithm>

class solver_2805{
public:
solver_2805(long long _M, std::vector<long long> _trees){
    M = _M;
    trees = _trees;
    std::sort(trees.begin(), trees.end(), [](auto a, auto b){
        if ( a < b)
            return true;
        else
            return false;
    });

}

void solver(){

    long long cut;
    long long remain = 0;

    long long start =0;
    long long end = trees.back();

    while (start <= end){

        cut = (start+end)/2;
        remain=0;

        for(int i = 0 ; i < trees.size() ; ++i){
            if (trees[i] > cut)
                remain = remain+ (trees[i] - cut);
        }    

        if (remain < M)
            end = cut-1;
        else if (remain >= M)
            start = cut+1;
    }
    std::cout << end << std::endl;

}

private:
long long M;
std::vector<long long> trees;


};

int main(){
    long long N, M;
    std::cin >> N >> M;

    std::vector<long long> trees(N);
    for(int i = 0 ; i < N ; ++i)
        std::cin >> trees[i];
    
    solver_2805 solver(M, trees);
    solver.solver();

    return 0;
}