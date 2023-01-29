/**
 * @brief 백준 5014번 문제
 * @brief 근데 이 문제 DP 처럼도 풀 수 있나?
 * @brief 1차시도: 메모리 초과.. 아무래도  graph 만들어줄때 너무 SPARSE 하게 만들어서 배열 사이즈가 너무 커서 그런가보다...
 * @brief 2차시도: 시간초과 ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ 한 5시간 했나.. 하놔
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
        max_graph = F;
        graph = vector<vector<int>>(max_graph + 1); // make graph : graph[S-D] = {S-D+U, S-D-D} / graph[S] = {S+U, S-D} / graph[S+U] = {S+U+U, S+U-D} ...,
        navigator = vector<vector<int>>(max_graph + 1);
        upAndDown = {U, -D};
        vector<int> temp;

        int ii = S;
        temp.push_back(ii);

        re1:
        if (D > 0)
        {
            for (int i = ii; i - D >= 1; i = i - D)
            {
                if (find(graph[i].begin(), graph[i].end(), i-D) == graph[i].end()){
                    graph[i].push_back(i - D); // 아래 계단으로
                    cout << i << ":(re1 down) " << i - D << endl;
                    ii = i - D;
                    temp.push_back(ii);
                }
            }
        }

        if (U > 0)
        {
            for(auto a : temp){
                for (int i = a; i + U <= max_graph; i = i + U)
                {
                    if (find(graph[i].begin(), graph[i].end(), i+U) == graph[i].end()){
                        graph[i].push_back(i + U); // 윗 계단으로
                        cout << i << ":(re2 up) " << i + U << endl;
                        ii = i + U ;
                        goto re1;
                    }
                }
            }
            temp.clear();
        }
    }

    void solve()
    {
        opens.push({S, S, 0}); // opens = {from, to, diff};
        while (!opens.empty() && notFound)
        {
            vector<int> now = opens.front();
            opens.pop();
            int now_from = now[0];
            int now_to = now[1];

            if (now_to == G)
            {
                notFound = false;
                int answer = 0;
                while (now_to != S)
                {
                    // cout << "+++++: " << now_to << endl;
                    now_to = navigator[now_to][0];
                    answer += 1;
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
                    auto i = find(graph[next_from].begin(), graph[next_from].end(), next_to);
                    if (i != graph[next_from].end())
                    {
                        opens.push({next_from, next_to, now_to - now_from});
                        navigator[next_to].push_back(next_from);
                        graph[next_from].erase(i);
                    }
                }
            }
        }
        cout << "use the stairs";
    }

    void monitor()
    {
        int i = 0;

        for (auto r : graph)
        {
            cout << "[" << i << "] ";
            for (auto c : r)
                cout << c << " ";
            cout << endl;
            i++;
        }
    }

private:
    int F, S, G, U, D;
    vector<vector<int>> graph;
    queue<vector<int>> opens;
    vector<vector<int>> navigator;
    vector<int> upAndDown;
    bool notFound = true;
    int max_graph;
};

int main()
{
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    solver_5014 solver(F, S, G, U, D);
    solver.monitor();
    solver.solve();

    return 0;
}