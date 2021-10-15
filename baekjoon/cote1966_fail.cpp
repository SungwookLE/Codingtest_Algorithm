#include <iostream>
#include <queue>
#include <algorithm>

class solver_1966{

public:
solver_1966(){}
void insert_and_solver(){
    int tc_n, N, M;
    std::cin >> tc_n;
    for(int i =0 ; i < tc_n ; ++i){
        std::queue<std::pair<int,int>> empty;
        std::swap(docu, empty);


        int ans =0;
        std::cin >> N >> M;
        int prior;

        for(int j =0 ; j < N ; ++j){
            std::cin >> prior;
            docu.push(std::make_pair(prior, j));       
        }

        //문제 풀기 시작
        while(!docu.empty()){
            bool is_big = true;
            for(int k= 1 ; k < docu.size() ; ++k){
                if (docu.front().first < (&docu.front()+k)->first){
                    is_big = false;
                    break;
                }    
            }
            if (is_big == false){
                docu.push(docu.front());
                docu.pop();
            }    
            else{
                ans +=1;

                int idx = docu.front().second;
                if (idx == M ){
                    //std::cout << "ANSWER: \n";
                    std::cout << ans << std::endl;
                    //break;
                }    
                docu.pop();
            }
        }
    }
}

private:
std::queue<std::pair<int,int>> docu;

};

int main(){
    solver_1966 solver;
    solver.insert_and_solver();


    return 0;
}