/**
 * @brief 백준 7569번 문제
 * @date 2023-01-15
 */

#include <iostream>
#include <vector>

using namespace std;

class solver_7569
{
public:
    solver_7569(int _M, int _N, int _H)
    {
        M = _M;
        N = _N;
        H = _H;
        boxes = vector<vector<vector<int>>>(
            H,
            vector<vector<int>>(
                N,
                vector<int>(M, 0)
                )
            );
        

        for (int z = 0; z < H; ++z){
            for (int y = 0; y < N; ++y){
                for (int x = 0; x < M; ++x){
                    cin >> boxes[z][y][x];
                    if (boxes[z][y][x] == 1){
                        starts.push_back({x,y,z});
                        count_tomato += 1;
                    }
                    else if (boxes[z][y][x] == 0){
                        count_notyet += 1;
                        count_tomato += 1;
                    }
                }
            }
        }
        // 정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸
    }

    void print_boxes(){
        cout << endl << "BOX PRINT:" << endl;
        for (int z = 0; z < H; ++z){
            for (int y = 0; y < N; ++y){
                for (int x = 0; x < M; ++x){
                    cout << boxes[z][y][x] << " ";
                }
                cout << endl;
            }
            cout << "----" <<endl;
        }
    }

    void DFS(vector<int> to){
        int x = to[0], y = to[1], z = to[2];
        boxes[z][y][x] = 1;

        for (auto d : deltas){
            int n_x = x + d[0], n_y = y + d[1], n_z = z + d[2];
            if (n_x >= 0 && n_y >= 0 && n_z >= 0 && n_x < M && n_y < N && n_z < H){
                if (boxes[n_z][n_y][n_x] == 0){
                    infection = true;
                    count_notyet -= 1;
                    DFS({n_x, n_y, n_z});
                }
            }
        }
    }

    void BFS(vector<int> start){

        if (count_notyet == 0)
            return;

        visited = vector<vector<vector<int>>>(
            H,
            vector<vector<int>>(
                N,
                vector<int>(M, 0)
                )
            );
        navigator = vector<vector<vector<int>>>(
            H,
            vector<vector<int>>(
                N,
                vector<int>(M, 0)
                )
            );

        int x=start[0], y=start[1], z=start[2];
        visited[z][y][x] = 1;
        opens.push_back({x,y,z});

        while(!opens.empty()){

            vector<int> next_point = opens.front();
            opens.erase(opens.begin());

            x = next_point[0];
            y = next_point[1];
            z = next_point[2];

            boxes[z][y][x] = 1;

            for(int i = 0 ; i < deltas.size(); ++i){
                vector<int> d = deltas[i];
                int n_x = x + d[0], n_y = y + d[1], n_z = z + d[2];
                if (n_x >= 0 && n_y >= 0 && n_z >= 0 && n_x < M && n_y < N && n_z < H){
                    if (visited[n_z][n_y][n_x] == 0 && boxes[n_z][n_y][n_x] == 0){
                        visited[n_z][n_y][n_x] = 1;
                        count_notyet -= 1;
                        opens.push_back({n_x, n_y, n_z});
                        navigator[n_z][n_y][n_x] = i;
                    }
                }
            }
        }

        int days = 0;
        while( x != start[0] || y != start[1] || z != start[2]){
            days+=1;
            int coord_x = x, coord_y = y, coord_z = z;
            x -= deltas[navigator[coord_z][coord_y][coord_x]][0];
            y -= deltas[navigator[coord_z][coord_y][coord_x]][1];
            z -= deltas[navigator[coord_z][coord_y][coord_x]][2];
        } 
        if (shortest_days < days)
            shortest_days = days;

        return;
    }

    void BFS_answer(){
        if (count_notyet > 0)
            cout << -1 << endl;
        else
            cout << shortest_days << endl;
    }
    vector<vector<int>> starts;

private:
    int M, N, H; // 가로, 세로, 높이
    int count_notyet = 0;
    int count_tomato = 0;

    vector<vector<vector<int>>> boxes;

    int shortest_days = 0; // BFS
    vector<vector<vector<int>>> visited; // BFS
    vector<vector<vector<int>>> navigator; // BFS
    vector<vector<int>> opens; // BFS

    vector<vector<int>> deltas = { {-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0}, {0,0,-1}, {0,0,1} };
    bool infection = false; // DFS
};

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int M, N, H; // 가로, 세로, 높이
    cin >> M >> N >> H;
    solver_7569 solver(M, N, H);

    for(auto s : solver.starts){
        solver.BFS(s);
    }

    solver.BFS_answer();

    return 0;
}