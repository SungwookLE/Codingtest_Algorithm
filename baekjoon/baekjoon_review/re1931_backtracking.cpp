#include <iostream>
#include <vector>
#include <algorithm>

class prob_1931{
    public:
    prob_1931(){
        std::cin >> N;
        std::vector<int> time(2);
        for(int idx =0 ; idx< N ; ++idx){
            for(int i =0; i < 2; ++i)
                std::cin>> time[i];

            times.push_back(time);
        }
        
        std::sort(times.begin(), times.end(), [](auto a , auto b){
            if ( a[0] < b[0])
                return true;
            else if (a[0]==b[0]){
                if ( a[1] < b[1])
                    return true;
                else
                    return false;
            }
            else
                return false;
        });

        candi.push_back({0,0});

        // std::cout << std::endl;
        // for (auto row : times){
        //     for(auto ele : row)
        //         std::cout << ele << " ";
        //     std::cout << std::endl;
        // }

    }

    void solver(int n){
        if ( n == N){
            if ( ans < (candi.size()-1)){
                ans = candi.size()-1;
            }

            return;
        }
        else{
            for(int i=n ; i < N ; ++i){
                if (candi.back()[1] <= times[i][0]){
                    candi.push_back(times[i]);
                    solver(i+1);
                    candi.pop_back();
                }
            }
        }
    }

    void print_ans(){
        std::cout << ans << std::endl;
    }

    private:
    int N;
    std::vector<std::vector<int>> times;
    std::vector<std::vector<int>> candi;
    int ans=0;

};

int main(){

    prob_1931 solver;
    solver.solver(0);
    solver.print_ans();

    return 0;
}