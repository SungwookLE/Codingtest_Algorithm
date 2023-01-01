//백트래킹
//백트래킹은 일종의 재귀호출 구조를 이용하여 푸는 문제를 말하는데, 
//재귀에서 끝나지 않고 특별한 조건들이 재귀호출되면서 반영되게끔 하는 것을 말한다.
//스타트와 링크 #14889
// 시간 초과 나지만, 백트래킹을 연습하기 위한 것이니까 여기서 스톱하겠다.


#include <vector>
#include <iostream>

class prob_14889{
    public:
    prob_14889(){
        std::cin >> N;

        for(int r = 0 ; r < N ; ++r){
            std::vector<int> row(N,0);
            for(int i=0 ; i < N; ++i)
                std::cin >> row[i];
            
            player.push_back(row);
        }
        person1.resize(N/2,0);
        
        picked.resize(N,0);
        score = 100*N/2;
    }

    void match(int n){

        if( n == (N/2)){

            person2.clear();
            for(int idx = 0 ; idx < N ; ++idx){
                bool in = false;
                for(int p =0 ; p < person1.size() ; ++p)
                    if( person1[p] == idx){
                        in = true;
                        break;
                    }
                if (in == false)
                    person2.push_back(idx);
            }

            int temp_score1= 0, temp_score2=0;
            int temp_score;

            for(int i =0 ; i < (N/2) ; ++i){
                for(int j =0 ; j < (N/2); ++j){
                    temp_score1 += player[person1[i]][person1[j]];
                    temp_score2 += player[person2[i]][person2[j]];
                }
            }

            temp_score = abs(temp_score1- temp_score2);

            if (score > temp_score)
                score = temp_score;

        }
        else{
            for(int i = 0 ; i < N ; ++i){
                if (picked[i] == 0 ){
                    picked[i] = 1;
                    person1[n] = i;
                    match(n+1);
                    picked[i]= 0;

                }
            }
        }
    }

    void print_score(){
        std::cout << score<<std::endl;
        return;
    }


    private:
    int N;
    std::vector<std::vector<int>> player;
    int score;
    std::vector<int> picked, person1, person2;
    std::vector<std::vector<int>> team;



};

int main(){
    prob_14889 solver;
    solver.match(0);
    //solver.print_combi();
    solver.print_score();

    return 0;
}


