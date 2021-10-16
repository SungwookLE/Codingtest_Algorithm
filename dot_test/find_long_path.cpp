#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class long_path{
    public:
    long_path(vector<int> start, int number, vector<vector<int>> board){
        x = start[0];
        y = start[1];

        visited.resize(board.size(), vector<int>(board[0].size(),0));

        for(int i =0 ; i < board.size() ; ++i){
            for(int j =0 ;j < board[0].size() ; ++j){

                if ( board[i][j] == number)
                    visited[i][j] = 0;
                else
                    visited[i][j] = 1;
            }
        }
    }

    int search(){

        bool resign = false;

        visited[x][y] = 1;
        opens.push_back({x,y,g});

        int iteration =0;

        while(resign == false){

            sort(opens.begin(), opens.end(), [](auto a, auto b){
                if ( a[2] < b[2])
                    return true;
                else
                    return false;
            });

            vector<int> now = opens.back();
            opens.pop_back();
            x = now[0];
            y = now[1];
            g = now[2];
            g_s.push_back(g);

            for(int i =0 ; i < delta.size() ; ++i){
                int x2, y2, g2;
                x2 = x + delta[i][0];
                y2 = y + delta[i][1];
                g2 = g+1;

                if (x2>= 0 && y2>=0 && x2<visited.size() && y2<visited[0].size()){
                    if ( visited[x2][y2] == 0  ){

                        visited[x2][y2] = 1;
                        opens.push_back({x2,y2,g2});

                    }
                }
            }

            if ( opens.empty()){
                resign = true;

                if(iteration ==0)
                    return -1;

                sort(g_s.begin(), g_s.end());
                return g_s.back();
            }    

            iteration +=1;

        }

    }

    private:
        int x, y, g=1;
        vector<int> g_s;
        vector<vector<int>> delta = {
            {0,1}, //right
            {0,-1}, //left
            {1,0}, //down
            {-1,0} //up
        };
        vector<vector<int>> visited;
        vector<vector<int>> opens;
};



int solution(vector<vector<int>> board)
{
    int answer =0;

    vector<int> path;
    for(int i =0; i < board.size() ; ++i){
        for(int j =0 ; j < board[0].size() ; ++j){
            vector<int> start = {i,j};
            int number = board[i][j];
            long_path particle(start, number, board);
            path.push_back(particle.search());
        }
    }

    sort(path.begin(), path.end());
    answer = path.back();




    return answer;
}
