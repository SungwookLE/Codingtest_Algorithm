/**
 * @brief 백준 9205번 문제: 맥주마시며 걸어가기
 * @brief 1차 시도 실패.. 일단 시간초과 생각않고 find 알고리즘 이용해서 구현을 했는데,알고리즘 오류가 있음 나는 단방향으로 생각해서, 부호처리 잘해주면 패스할수도?
 * @date 2023-02-08
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solver_9205
{
public:
    solver_9205(int _n) : n(_n)
    {
        int x, y;
        cin >> x >> y;
        start = {x, y};
        map.push_back(start);

        for(int i =0 ; i < n ; ++i){
            cin >> x >> y;
            map.push_back({x,y});
        }

        cin >> x >> y;
        goal = {x,y};
        map.push_back(goal);

        sort(map.begin(), map.end(), [](auto a, auto b){
            if (a[0] < b[0])
                return true;
            else if (a[0]==b[0]){
                if (a[1] < b[1])
                    return true;
                else
                    return false;
            }
            else
                return false;
        });
    }

    void DFS(vector<int> now){

        cout <<"NOW: " << now[0] << ", " << now[1] << endl;
        auto it = find(map.begin(), map.end(), now);
        if (it != map.end()){
            map.erase(it); // 방문처리 
        }

        int now_x = now[0], now_y = now[1];
        int next_x_xdir = now_x, next_y_xdir = now_y;
        int next_x_ydir = now_x, next_y_ydir = now_y;
        int next_x_xydir = now_x, next_y_xydir = now_y;


        beers = 20;

        if (abs(goal[0]-now_x) < PER && abs(goal[1]-now_y) < PER){
            cout << "happy\n";
            found = true;
            return;
        }

        vector<int> next;
        while(!resign && !found){
            beers-=1;
            if (beers == -1){
                cout << "sad\n";
                resign = true;
                return;
            }

            next_x_xdir += PER;
            next_y_xdir = now_y;

            next = {next_x_xdir, next_y_xdir};
            if (next[0] >=0 && next[1] >=0 && next[0] < 65536 && next[1] < 65536){
                if (abs(map.front()[0]-next[0]) < PER && abs(map.front()[1]-next[1]) < PER ){
                    DFS(next);
                    break;
                }
            }

            next_x_ydir = now_x;
            next_y_ydir += PER;
            next = {next_x_ydir, next_y_ydir};
            if (next[0] >= 0 && next[1] >= 0 && next[0] < 65536 && next[1] < 65536){
                if (abs(map.front()[0]-next[0]) < PER && abs(map.front()[1]-next[1]) < PER ){
                    DFS(next);
                    break;
                }
            }

            next_x_xydir += PER/2;
            next_y_xydir += PER/2;
            next = {next_x_xydir, next_y_xydir};
            if (next[0] >= 0 && next[1] >= 0 && next[0] < 65536 && next[1] < 65536){
                if (abs(map.front()[0]-next[0]) < PER && abs(map.front()[1]-next[1]) < PER ){
                    DFS(next);
                    break;
                }
            }

        }
    }
    

     vector<int> start;
private:
    bool resign =false;
    bool found = false;
    int n;
    vector<int> goal;
    vector<vector<int>> map;
    int beers = 20;
    int PER = 50;
    vector<vector<int>> delta = {{PER,0}, {0,PER}};

};

int main()
{
    int t; // 테스트 케이스의 개수
    int n; // 맥주를 파는 편의점의 개수

    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        solver_9205 solver(n);
        solver.DFS({solver.start[0], solver.start[1]});
    }

    return 0;
}