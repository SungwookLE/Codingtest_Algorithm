/**
 * @date 2023-03-01
 * @brief 삼성SW 역량테스트 문제: #13460
 * @brief 1차시도: 한 2시간 푼거같은데.. 반례가 많이 보이는... 알고리즘을 이런형태로 가져가면 안되는건가..
 * @brief 2차시도: 흠.... ..
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

        opens.push_back({Red[0], Red[1], Blue[0], Blue[1], -1});
        visited[Red[0]][Red[1]] = 0;

        vector<int> now;

        while (!opens.empty()){
            now = opens.front();
            opens.erase(opens.begin());

            if (now[0] == Goal[0] && now[1] == Goal[1]){
                cout << visited[now[0]][now[1]] << endl;
                return;
            }
            else if ( now[0] - Goal[0] == 0 ){
                // RED와 BLUE가 같은 row에 있다면, now[0] - now[2] == 0
                if(now[4] > 1){ 
                    if((now[0] - now[2] == 0) && !isThereObstacle(now[2], now[3], Goal[0], Goal[1], now[4])){
                        cout << -1 << endl;
                        return;
                    }
                    else if (!isThereObstacle(now[0], now[1], Goal[0], Goal[1], now[4])){ // Goal을 지나쳐 이동했음
                        cout << visited[now[0]][now[1]] << endl;
                        return;
                    }
                    
                }
            }
            else if ( now[1] - Goal[1] == 0 ){
                // RED와 BLUE가 같은 col에 있다면, now[1] - now[3] == 0
                if (now[4] == 0 || now[4] == 1){
                    if((now[1] - now[3] == 0) && !isThereObstacle(now[2], now[3], Goal[0], Goal[1], now[4])){
                        cout << -1 << endl;
                        return;
                    }
                    else if (!isThereObstacle(now[0], now[1], Goal[0], Goal[1], now[4])){ // Goal을 지나쳐 이동했음
                        cout << "QQQ"<< endl;
                        cout << visited[now[0]][now[1]] << endl;
                        return;                    
                    }
                }
            }
            
            if (visited[now[0]][now[1]] > 10){
                cout << -1 << endl;
                return;
            }

            int delta_idx = 0;
            for(auto d : delta){
                int next_r_RED=now[0], next_c_RED=now[1], next_r_BLUE=now[2], next_c_BLUE=now[3];

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

                }
                next_r_RED -= d[0];
                next_c_RED -= d[1];

                if (next_r_RED == next_r_BLUE && next_c_RED == next_c_BLUE){
                    // 파랑이 빨강의 후행
                    next_r_BLUE -=d[0];
                    next_c_BLUE -=d[1];
                }

                if(next_r_RED >= 0 && next_c_RED >= 0 && next_r_RED < H && next_c_RED < W){
                    if (visited[next_r_RED][next_c_RED] == -1 && board[next_r_RED][next_c_RED] != '#'){
                        opens.push_back({next_r_RED, next_c_RED, next_r_BLUE, next_c_BLUE, delta_idx});
                        visited[next_r_RED][next_c_RED]=visited[now[0]][now[1]]+1;
                    }
                }

                delta_idx += 1;
            }
        }
        cout << -1 << endl;
        return;
    }


    bool isThereObstacle(int start_r, int start_c, int goal_r, int goal_c, int delta_idx){
        bool ret = false;
        if (delta_idx <= 1){
            if (delta_idx%2 == 0){
                if (start_r < goal_r){
                    for(int i = start_r; i <= goal_r; ++i)
                        if (board[i][start_c] == '#'){
                            ret = true;
                            break;
                        }
                }
                else
                    ret = true;
            }
            else{
                if (start_r > goal_r){
                    for(int i = start_r; i >= goal_r; --i)
                        if(board[i][start_c] == '#'){
                            ret = true;
                            break;
                        }
                }
                else
                    ret = true;
            }
        }
        else{
            if (delta_idx%2 == 0){
                if (start_c < goal_c){
                    for(int i = start_c; i <= goal_c; ++i)
                        if (board[start_r][i] == '#'){
                            ret = true;
                            break;
                        } 
                }
                else
                    ret = true;
            }
            else{
                if (start_c > goal_c){
                    for(int i = start_c; i >= goal_c; --i)
                        if(board[start_r][i] == '#'){
                            ret = true;
                            break;
                        }
                }
                else
                    ret = true;
            }
        }
        return ret;
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
