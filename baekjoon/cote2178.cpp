/**
 * @brief baekjoon 2178번 문제: 미로 찾기 문제,  A*가 아닌 DFS로 풀었다.
 * https://www.acmicpc.net/problem/2178
 * @date 2023-01-13
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solver_2178{
    public:
    solver_2178(int _row, int _col): row_(_row), col_(_col){
        string input;
        maze = vector<vector<int>>(_row, vector<int>(_col,0));
        visited = vector<vector<int>>(_row, vector<int>(_col,0));
        navigator = vector<vector<int>>(_row, vector<int>(_col,0));

        for(int row =0 ; row < _row; ++row){
            cin >> input;
            for (int col =0; col < _col; ++col){
                maze[row][col] = (int)(input[col]-'0');
            }
        }
    }

    void solve(){
        int answer = 1;
        int start_row=0, start_col=0;
        opens.push_back({start_row, start_col});
        visited[start_row][start_col] = 1;

        while(!opens.empty()){

            start_row = opens.front().first;
            start_col = opens.front().second;
            opens.erase(opens.begin());

            if (start_row == row_-1 && start_col == col_-1){
                
                while(start_row != 0 || start_col != 0){

                    int inv = navigator[start_row][start_col];
                    start_row -= delta[inv].first;
                    start_col -= delta[inv].second;
                    answer +=1;
                }

                cout << answer << endl;
                return;
            }

            for(int i = 0 ; i < delta.size(); ++i){
                
                int next_row=start_row+delta[i].first;
                int next_col=start_col+delta[i].second;
                if (next_row >= 0 && next_col >=0 && next_row < row_ && next_col < col_ 
                    && visited[next_row][next_col] == 0 && maze[next_row][next_col] == 1){
                    visited[next_row][next_col] = 1;
                    opens.push_back({next_row, next_col});
                    navigator[next_row][next_col] = i;
                }
            }
        }

        cout << "NO EXIT" << endl;

        return ;
    }

    private:
    int row_, col_;
    vector<vector<int>> maze;
    vector<pair<int, int>> delta = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    vector<pair<int, int>> opens;
    vector<vector<int>> visited;
    vector<vector<int>> navigator;

};

int main(){
    int _row, _col;
    cin >> _row >> _col;
    solver_2178 solver(_row, _col);
    solver.solve();

    return 0;
}