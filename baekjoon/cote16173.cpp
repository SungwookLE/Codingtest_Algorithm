/**
 * @brief #16173번 문제. 점프왕 쩰리
 * @breif 단순한 BFS 문제: 1차시도 성공
 * @date 2023-02-20
 */

#include <iostream>
#include <vector>

using namespace std;

class solver_16173{

    public:
    solver_16173(int _N){
        N = _N;
        map = vector<vector<int>>(N,vector<int>(N,0));
        visited = vector<vector<int>>(N,vector<int>(N,0));

        goal = {N-1, N-1};
        for(int r = 0 ; r < N ; ++r){
            for(int c = 0 ; c < N ; ++c){
                cin  >> map[r][c];
            }
        }

    }

    void BFS(){

        opens.push_back({start.first, start.second, map[start.first][start.second]});
        visited[start.first][start.second] = 1;

        vector<int> now;
        while(!opens.empty()){
            
            now = opens.front();
            opens.erase(opens.begin());

            if (now[0] == goal.first && now[1] == goal.second){
                // reach goal

                cout << "HaruHaru\n";
                return;
            }


            for(auto d : deltas){
                int next_r = now[0]+d.first * map[now[0]][now[1]];
                int next_c = now[1]+d.second * map[now[0]][now[1]];

                if ( next_r >= 0 && next_r < N && next_c >=0 && next_c <N){
                    if (visited[next_r][next_c] == 0){
                        visited[next_r][next_c] = 1;
                        opens.push_back({next_r, next_c, map[next_r][next_c]});
                    }
                }
            }

        }

        cout << "Hing\n";
        return;

    }

    private:
    int N;
    vector<vector<int>> map;
    vector<vector<int>> visited;
    pair<int,int> start = {0,0};
    pair<int,int> goal;
    vector<vector<int>> opens;
    vector<pair<int, int>> deltas = {{0,1},{1,0}};


};

int main(){
    int N;
    cin >> N;
    solver_16173 solver(N);
    solver.BFS();

    return 0;
}