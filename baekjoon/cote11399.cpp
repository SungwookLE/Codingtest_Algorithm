#include <iostream>
#include <vector>
#include <algorithm>

class solver_11399{

    public:
    solver_11399(int N_in): N(N_in){}

    void insert_arr(){

        for(int i=0; i < N ; ++i){
            int res;
            std::cin >> res;
            arr.push_back(res);
        }
        std::sort(arr.begin(), arr.end(), [](int a, int b){
            if (a< b)
                return true;
            else
                return false;
        });

    }

    int solver(){
        int answer =arr[0];
        std::vector<int> move_sum(N,0);
        move_sum[0] = arr[0];        
        for(int i =1 ; i < N ; ++i){
            move_sum[i] += arr[i] + move_sum[i-1];
            answer += move_sum[i];
        }


        return answer;

    }


    private:
    int N;
    std::vector<int> arr;


};

int main(){
    int N;
    std::cin >> N;
    solver_11399 solver(N);
    solver.insert_arr();
    int answer = solver.solver();
    std::cout << answer << std::endl;
    return 0;
}