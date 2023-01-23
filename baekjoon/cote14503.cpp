/**
 * @file cote14503.cpp
 * @brief 백준 14053번 문제, 1차시도 테스트케이스 실패 음... 모니터링하는것도 만들어서 봤는데 잘못된거없는거 같은데...?
 * @brief 2차시도 (2023-01-23) 성공, visited 체크하는 부분에서 섞여서 꼬여있었음..
 * @date 2023-01-17
 */

#include <iostream>
#include <vector>

using namespace std;

class solver_14503{
    public:
    solver_14503(int _N, int _M){
        cin >> xyTheta[0] >> xyTheta[1] >> xyTheta[2];
        N = _N;
        M = _M;
        room = vector<vector<int>>(N, vector<int>(M,0));
        visited = vector<vector<int>>(N, vector<int>(M,-1));

        for(int row = 0 ; row < N ; ++row){
            for(int col =0 ; col < M ; ++col){
                cin >> room[row][col];
            }
        }
    }

    void DFS(vector<int> to, int count){
       
        int now_row = to[0];
        int now_col = to[1];
        int now_Theta = to[2];

        visited[now_row][now_col] = now_Theta;
        int next_row, next_col, next_Theta;

        // cout << now_row << " " << now_col << " " << now_Theta << endl;
        // monitoring(visited, to);

        if (count >3){
            
            if (now_Theta ==0){
                next_Theta = now_Theta;
                next_row = now_row - delta[next_Theta][0];
                next_col = now_col- delta[next_Theta][1];
            }
            else if (now_Theta ==1){
                next_Theta = now_Theta;
                next_row = now_row - delta[next_Theta][0];
                next_col = now_col- delta[next_Theta][1];
            }
            else if (now_Theta ==2){
                next_Theta = now_Theta;
                next_row = now_row - delta[next_Theta][0];
                next_col = now_col- delta[next_Theta][1];
            }
            else if (now_Theta ==3){
                next_Theta = now_Theta;
                next_row = now_row - delta[next_Theta][0];
                next_col = now_col- delta[next_Theta][1];
            }

            if(next_row >= 0 && next_col >= 0 && next_row < N && next_col < M){
                if (room[next_row][next_col] == 0){
                    DFS({next_row, next_col, next_Theta}, 0);
                }
            }
            return;
        }

        
        if (now_Theta == 0){
            next_Theta = 3;
            next_row = now_row + delta[next_Theta][0];
            next_col = now_col + delta[next_Theta][1];
        }
        else if (now_Theta == 1){
            next_Theta = 0;
            next_row = now_row + delta[next_Theta][0];
            next_col = now_col + delta[next_Theta][1];
        }
        else if (now_Theta == 2){
            next_Theta = 1;
            next_row = now_row + delta[next_Theta][0];
            next_col = now_col + delta[next_Theta][1];
        }
        else if (now_Theta == 3){
            next_Theta = 2;
            next_row = now_row + delta[next_Theta][0];
            next_col = now_col + delta[next_Theta][1];
        }

        if(next_row >= 0 && next_col >= 0 && next_row < N && next_col < M){
            if (room[next_row][next_col] == 0 && visited[next_row][next_col] == -1){
                DFS({next_row, next_col, next_Theta}, 0);
            }
            else if (room[next_row][next_col] == 1 || visited[next_row][next_col] != -1){
                DFS({now_row, now_col, next_Theta}, count+1);
            }
        }

        
    }

    int answer(){
        for(auto row: visited){
            for (auto col: row){
                if (col != -1)
                    ans += 1;
            }
        }
        return ans;
    }

    void monitoring(vector<vector<int>> _visited, vector<int> now){
        vector<vector<char>> char_visited = vector<vector<char>>(N, vector<char>(M,' '));

        for(int r =0 ; r < _visited.size(); ++r){
            for(int c =0 ; c< _visited[0].size(); ++c){
                if (room[r][c] == 1)
                    char_visited[r][c] = '#';
                else if (_visited[r][c] == -1)
                    char_visited[r][c] = ' ';
                else
                    char_visited[r][c] = d[_visited[r][c]];
                cout << char_visited[r][c] << " ";
            }
            cout << endl;
        }

    }




    vector<int> xyTheta= {0,0,0};

    private:
    vector<char> d = {'^', '>', 'v', '<'}; // 북, 동, 남, 서

    vector<vector<int>> delta = {{-1,0},{0,1}, {1,0}, {0,-1}}; // 북, 동, 남, 서
    int N, M;
    vector<vector<int>> room;
    vector<vector<int>> visited;
    int ans = 0;
};

int main(){
    
    int N, M;
    cin >> N >> M;

    solver_14503 solver(N, M);
    solver.DFS(solver.xyTheta, 0);
    cout << solver.answer() << endl;


    return 0;
}