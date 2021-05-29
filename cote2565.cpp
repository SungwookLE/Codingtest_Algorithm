#include <iostream>
#include <vector>
#include <algorithm>

class solver_2565{
    public:
    solver_2565(int size): N(size){
        DP.resize(N,0);
    }

    void get_lines(){
        std::vector<int> res(2,0);
        for (int i = 0 ; i < N; ++i){
            std::cin >> res[0] >> res[1];
            lines.push_back(res);
        }
    }

    void get_answer(){
        /*CODE HERE*/

        std::sort(lines.begin(), lines.end(), [](auto a , auto b){
            if (a[0] < b[0])
                return true;
            else
                return false;});
        int max_num = 0;
        for (int i = 0 ; i < N ; ++i){ //최장 증가 수열을 구하는 과정
            DP[i] = 1; 
            for (int j = 0 ; j < i ; ++j){
                if (lines[i][1] > lines[j][1] && DP[i] < (DP[j]+1))
                    DP[i] = DP[j] + 1 ;
            }
            max_num = std::max ( max_num , DP[i]);
        }
        answer = N-max_num; // answer;
    };

    void print_lines(){
        std::cout << "PRINT INPUT LINES: \n";

        for (auto row : lines){
            for (auto col : row){

                std::cout << col << " ";
            }
            std::cout << std::endl;
        }

    }

    int answer;

    private:
    int N;
    std::vector< std::vector<int> > lines;
    std::vector<int> DP;


};

int main(){
    int N;
    std::cin >> N;

    solver_2565 solver(N);
    solver.get_lines();
    solver.get_answer();

    std::cout << solver.answer << std::endl;
    return 0;
}

/*
#2565
문제>> 
두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니
전깃줄이 서로 교차하는 경우가 발생하였다. 합선의 위험이 있어
이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.

예를 들어, <그림 1>과 같이 전깃줄이 연결되어 있는 경우 A의 1번
위치와 B의 8번 위치를 잇는 전깃줄, A의 3번 위치와 B의 9번 위치를 잇는
전깃줄 A의 4번 위치와 B의 1번 위치를 잇는 전깃줄을 없애면 남아있는 모든
전깃줄의 서로 교차하지 않게 된다. 
*/