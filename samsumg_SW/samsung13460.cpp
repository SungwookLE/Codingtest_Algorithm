/**
 * @date 2023-03-01
 * @brief 삼성SW 역량테스트 문제: #13460
 * @brief 1차시도: 한 2시간 푼거같은데.. 반례가 많이 보이는... 알고리즘을 이런형태로 가져가면 안되는건가..
 * @brief TC: https://www.acmicpc.net/board/view/90094
 */

#include <iostream>
#include <vector>
#include<iomanip>

using namespace std;

class solver_13460
{

public:
    solver_13460(int _H, int _W) : H(_H), W(_W) {
        board = vector<vector<char>>(H, vector<char>(W,' '));
        visited = vector<vector<int>>(H, vector<int>(W,-1));

        for(int r = 0 ; r < H ; ++r){
            for(int c =0 ; c < W ; ++c){
                cin >> board[r][c]; // '.','#','O','R','B'
                if (board[r][c] == 'O')
                    Goal = {r,c};
                else if (board[r][c] == 'R')
                    Red = {r,c};
                else if (board[r][c] == 'B')
                    Blue = {r,c};
            }
        }
    }
    
    void dfs(){

        opens.push_back({Red[0], Red[1], Blue[0], Blue[1]});
        visited[Red[0]][Red[1]] = 0;

        vector<int> now;

        while (!opens.empty()){
            now = opens.front();
            opens.erase(opens.begin());

            if (now[0] == Goal[0] && now[1] == Goal[1]){
                cout << visited[now[0]][now[1]] << endl;
                return;
            }
            else if (visited[now[0]][now[1]] > 10){
                cout << -1 << endl;
                return;
            }
            else{
                for(auto d : delta){
                    int next_r_RED=now[0], next_c_RED=now[1], next_r_BLUE=now[2], next_c_BLUE=now[3];
                    bool flag_R = false, flag_B = false;

                    while(board[next_r_RED][next_c_RED] != '#'){
                        next_r_RED += d[0];
                        next_c_RED += d[1];
                        next_r_BLUE += d[0];
                        next_c_BLUE += d[1];
                    
                        if (next_r_BLUE < 0 || next_c_BLUE < 0 || next_r_BLUE >= H || next_c_BLUE >= W || board[next_r_BLUE][next_c_BLUE] == '#'){
                            next_r_BLUE -= d[0];
                            next_c_BLUE -= d[1];
                        }

                        if (next_r_RED == next_r_BLUE && next_c_RED == next_c_BLUE){
                            break; // 빨강이 파랑의 후행
                        }

                        if (next_r_RED == Goal[0] && next_c_RED == Goal[1]){
                            visited[next_r_RED][next_c_RED]=visited[now[0]][now[1]]+1;
                            flag_R = true;
                        }
                        else if (next_r_BLUE == Goal[0] && next_c_BLUE == Goal[1]){
                            flag_B = true;
                        }
                    }
                    next_r_RED -= d[0];
                    next_c_RED -= d[1];

                    if (next_r_RED == next_r_BLUE && next_c_RED == next_c_BLUE){
                        // 파랑이 빨강의 후행
                        next_r_BLUE -=d[0];
                        next_c_BLUE -=d[1];
                    }

                    if(flag_B){
                        cout << -1 << endl;
                        return;
                    }
                    else if(flag_R){
                        cout << visited[now[0]][now[1]]+1 << endl;
                        return;
                    }

                    if(next_r_RED >= 0 && next_c_RED >= 0 && next_r_RED < H && next_c_RED < W){
                        if (visited[next_r_RED][next_c_RED] == -1 && board[next_r_RED][next_c_RED] != '#'){
                            
                            cout << "====(" << visited[now[0]][now[1]]+1 << ")\n"; 
                            cout << "RED: " << next_r_RED << ", "<< next_c_RED << endl;
                            cout << "BLUE: " << next_r_BLUE << ", "<< next_c_BLUE << endl;
                            cout << "-------\n";

                            opens.push_back({next_r_RED, next_c_RED, next_r_BLUE, next_c_BLUE});
                            visited[next_r_RED][next_c_RED]=visited[now[0]][now[1]]+1;
                        }
                    }
                }
            }
        }
        cout << -1 << endl;
        return;
    }

    void monitor(){
        for(auto v : visited){
            for(auto vv : v){
                cout << setw(2) << vv << " ";
            }
            cout << endl;
        }
    }


private:
    int H, W;
    int ans = 0;
    vector<int> Red, Blue, Goal;
    vector<vector<char>> board;
    vector<vector<int>> visited;
    vector<vector<int>> opens;

    vector<vector<int>> delta = {{-1,0},{1,0}, {0,-1}, {0,1}};
};

int main()
{

    int H, W;
    cin >> H >> W;
    solver_13460 solver(H,W);
    solver.dfs();
    solver.monitor();

    return 0;
}
