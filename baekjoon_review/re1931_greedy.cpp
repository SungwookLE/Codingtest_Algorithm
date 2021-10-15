#include <iostream>
#include <vector>
#include <algorithm>


// 백트래킹 방식으로 풀지 않아도 됫었던게, 애초에 끝나는 시간으로 정렬해서 뽑아버리면 구하고자
// 하는 경우의 수가 나와버리지!! (그리디)

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
            if ( a[1] < b[1])
                return true;
            else if (a[1]==b[1]){
                if ( a[0] < b[0])
                    return true;
                else
                    return false;
            }
            else
                return false;
        });


        // std::cout << std::endl;
        // for (auto row : times){
        //     for(auto ele : row)
        //         std::cout << ele << " ";
        //     std::cout << std::endl;
        // }

    }

    void solver(){
        
        std::vector<int> picked = times[0];
        ans += 1;
        for(int i = 1 ; i < N ; ++i){

            if ( picked[1]  <= times[i][0]){
                ans+=1;
                picked = times[i];
            }

        }
    }

    void print_ans(){
        std::cout << ans << std::endl;
    }

    private:
    int N;
    std::vector<std::vector<int>> times;
    int ans=0;

};

int main(){

    prob_1931 solver;
    solver.solver();
    solver.print_ans();

    return 0;
}