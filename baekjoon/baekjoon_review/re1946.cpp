#include <iostream>
#include <vector>
#include <algorithm>
//https://www.acmicpc.net/problem/1946
class solver_1946{

public:
solver_1946(){
    std::cin >> T;
    for(int i =0 ; i < T ; ++i){
        std::cin >> N;

        std::vector<std::vector<int>> score(N, std::vector<int>(2,0));
        for(int j=0; j < N ; ++j){
            std::cin >> score[j][0] >> score[j][1];
        }

        std::sort(score.begin(), score.end());
        scores.push_back(score);
    }
}
void print_score(){
    std::cout << "Print:\n";
    for(auto idx : scores){
        for(auto i : idx){
            for(auto a : i){
                std::cout << a << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void solver(){

    for(int idx =0 ; idx < scores.size() ; ++idx){

        auto score = scores[idx];
        int ans = 1;
        int comp = score[0][1];

        for(int i =1 ; i < score.size(); ++i){

            if (comp > score[i][1] ){
                comp = score[i][1];
                ans+=1;
            }

        }


        std::cout << ans <<"\n";

    }

}

private:
int T;
int N;
std::vector<std::vector<std::vector<int>>> scores;



};

int main(){

    solver_1946 solver;
    // solver.print_score();
    solver.solver();
    return 0;
}