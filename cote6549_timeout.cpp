#include <iostream>
#include <vector>

class solver_6549{

public:
    void insert_histogram(std::vector<long long> histo){
        histo_ = histo;
    }

    void solver(){

        long long ans=0;
        for(int i =0 ; i < histo_.size() ; ++i){
            long long temp =0;
            for(int j =i ; j < histo_.size() ; ++j){
                if (histo_[i] > histo_[j])
                    break;
                else{
                    temp += histo_[i];
                }
            }
            ans = std::max(ans, temp);
        }
        std::cout << ans << std::endl;
    }

private: 
    std::vector<long long> histo_;
};

int main(){
    int N ;
    std::vector<long long> histo;
    solver_6549 solver;

    std::cin >> N;
    while(N!=0){
        long long sum = 0;
        histo.resize(N);
        for(int i =0 ; i < N ; ++i){
            std::cin >> histo[i];
        }

        /*solve here*/
        solver.insert_histogram(histo);
        solver.solver();

        std::cin >> N;
    }

    return 0;
}