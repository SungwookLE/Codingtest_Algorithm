/**
 * @brief 백준 9205번 문제: 맥주마시며 걸어가기
 * @brief 1차 시도 실패.. 일단 시간초과 생각않고 find 알고리즘 이용해서 구현을 했는데,알고리즘 오류가 있음 나는 단방향으로 생각해서, 부호처리 잘해주면 패스할수도? => 실패
 * @brief 2차 시도: 답 참고하여 풀었음.. 나는 제자리 걸음인가봐 ㅠ
 * @date 2023-02-08
 */

#include <iostream>
#include <vector>

using namespace std;

class solver_9205{

    public:
    solver_9205(){
        cin >> n;
        int x, y;
        cin >> x>> y;
        home = {x,y};
        for(int i = 0 ; i < n ; ++i){
            cin >> x >> y;
            store.push_back({x,y});
        }
        cin >> x >> y;
        goal = {x,y};

        visited = vector<int>(n,0);
    }


    bool DFS(int node, pair<int, int> coord){
        if (abs(coord.first - goal.first) + abs(coord.second - goal.second) <= 1000) return true;
        if (node == n) return false;

        for (int i =0 ; i < n ; ++i){

            if ( visited[i] == 1) continue;
            int d = (abs(coord.first - store[i].first) + abs(coord.second - store[i].second));
            if (d > 1000) continue;
            visited[i] = true;
            if( DFS(node+1, store[i])) return true;
        }

        return false;


    }
    pair<int, int> home;

    private:
    int n;
    vector<pair<int, int>> store;
    pair<int, int> goal;
    vector<int> visited;



};

int main(){

    int T;
    cin >> T;
    for(int tc = 1 ; tc <= T; ++tc){
        solver_9205 solver;
        if (solver.DFS(0, solver.home)) cout << "happy\n";
        else cout << "sad\n";
    }
    

}