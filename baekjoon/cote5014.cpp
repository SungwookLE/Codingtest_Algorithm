/**
 * @brief 백준 5014번 문제
 * @brief 근데 이 문제 DP 처럼도 풀 수 있나?
 * @brief 1차시도: 메모리 초과.. 아무래도  graph 만들어줄때 너무 SPARSE 하게 만들어서 배열 사이즈가 너무 커서 그런가보다...
 * @date 2023-01-27
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class solver_5014
{
public:
    solver_5014(int _F, int _S, int _G, int _U, int _D) : F(_F), S(_S), G(_G), U(_U), D(_D)
    {
        max_graph = F + 1 + 2 * U;
        graph = vector<vector<int>>(max_graph + 1, vector<int>(max_graph + 1, 0));
        visited = vector<vector<int>>(max_graph + 1, vector<int>(max_graph + 1, 0));
        upAndDown = {U, -D};

        // make graph: graph[from][to] = cost
        if (U > 0)
        {
            for (int i = S + U; i <= max_graph; i = i + U)
            {
                graph[i - U][i] = 1;

                if (D > 0)
                {
                    for (int j = i - D; j >= 1; j = j - D)
                    {
                        graph[j + D][j] = 1;
                    }
                }
            }
        }
        else
        {
            if (D > 0)
            {
                for (int j = S - D; j >= 1; j = j - D)
                {
                    graph[j + D][j] = 1;
                }
            }
        }
    }

    void solve()
    {
        opens.push({S, S}); // opens = {from, to};
        visited[S][S] = 1;

        while (!opens.empty() && notFound)
        {
            vector<int> now = opens.front();
            opens.pop();
            int now_from = now[0];
            int now_to = now[1];

            if (now_to == G)
            {
                notFound = false;
                int answer = 1;
                while (true)
                {
                    answer += 1;

                    int diff = visited[now_from][now_to];
                    now_to = now_from;
                    now_from = now_to - diff;

                    if (now_from == S)
                    {
                        break;
                    }
                }

                cout << answer << endl;
                return;
            }

            for (auto a : upAndDown)
            {
                int next_from = now_to;
                int next_to = now_to + a;

                if (next_from > 0 && next_from <= max_graph && next_to > 0 && next_to <= max_graph)
                {
                    if (visited[next_from][next_to] == 0 && graph[next_from][next_to] == 1)
                    {
                        visited[next_from][next_to] = now_to - now_from;
                        opens.push({next_from, next_to});
                        // navigator[next_from][next_to] = now_to - now_from;
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
    vector<vector<int>> visited;
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