/**
 * @brief 백준 5014번 문제
 * @brief 근데 이 문제 DP 처럼도 풀 수 있나?
 * @brief 1차시도: 메모리 초과.. 아무래도  graph 만들어줄때 너무 SPARSE 하게 만들어서 배열 사이즈가 너무 커서 그런가보다...
 * @date 2023-01-27
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class solver_5014
{
public:
    solver_5014(int _F, int _S, int _G, int _U, int _D) : F(_F), S(_S), G(_G), U(_U), D(_D)
    {
        max_graph = F + 1 + 2 * U;
        // graph = vector<vector<int>>(max_graph + 1, vector<int>(max_graph + 1, 0)); // 2차원배열이 아니고..., 1차원 배열로 바꾸셔야 겠소..,
        // visited = vector<vector<int>>(max_graph + 1, vector<int>(max_graph + 1, 0));
        upAndDown = {U, -D};

        // make graph: graph[from][to] = cost
        if (U > 0)
        {
            for (int i = S + U; i <= max_graph; i = i + U)
            {
                // graph[i - U][i] = 1; 
                graph.push_back({i-U, i});

                if (D > 0)
                {
                    // graph[i][i-D] = 1;
                    graph.push_back({i, i-D});
                }
            }
        }
        else
        {
            if (D > 0)
            {
                // graph[S][S-D] = 1;
                graph.push_back({S, S-D});
            }
        }
        sort(graph.begin(), graph.end(), [](auto a, auto b){
            if (a[0] < b[0])
                return true;
            else if (a[0] ==b[0]){
                if (a[1]<=b[1])
                    return true;
                else
                    return false;
            }
            else
                return false;
        });

        no_visited = graph;
    }

    void solve()
    {
        opens.push({S, S}); // opens = {from, to};
        // visited[S][S] = 1;

        while (!opens.empty() && notFound)
        {
            vector<int> now = opens.front();
            opens.pop();
            int now_from = now[0];
            int now_to = now[1];

            if (now_to == G)
            {
                notFound = false;
                cout << "FOUND\n";
                return;
            }

            for (auto a : upAndDown)
            {
                int next_from = now_to;
                int next_to = now_to + a;

                if (next_from > 0 && next_from <= max_graph && next_to > 0 && next_to <= max_graph)
                {
                    vector<int> v = {next_from, next_to};
                    auto i = find(no_visited.begin(), no_visited.end(), v);
                    if ( i!= no_visited.end()){
                        no_visited.erase(i);
                        opens.push(v);
                    }
                }
            }


        }
        cout << "use the stairs\n";
    }

    void monitor()
    {
        for (auto r : graph)
        {
            for (auto c : r)
                cout << c << " ";
            cout << endl;
        }
    }

private:
    int F, S, G, U, D;
    vector<vector<int>> graph;
    vector<vector<int>> no_visited;
    vector<vector<int>> navigator;
    queue<vector<int>> opens;
    vector<int> upAndDown;
    bool notFound = true;
    int max_graph;
};

int main()
{
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    solver_5014 solver(F, S, G, U, D);
    solver.solve();

    return 0;
}