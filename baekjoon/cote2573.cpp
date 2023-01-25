/**
 * @brief 백준2573번 문제: 빙산
 * @brief 이런~ 빙산 1차시도: 시간초과 뭥미... ;;
 * @brief 2차시도: 시간초과 실패 ㅠㅠ.. dfs를 포기해야하는건가 근데 bfs로 풀어도 이 문제같은 경우는 시간복잡도가 같은건데...
 * @date 2023-01-24
 * @file cote2573.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

class solver_2573
{
public:
    solver_2573(int _N, int _M)
    {
        N = _N;
        M = _M;
        ices_map = vector<vector<int>>(N, vector<int>(M, 0));

        for (int row = 0; row < N; ++row)
        {
            for (int col = 0; col < M; ++col)
            {
                cin >> ices_map[row][col];
            }
        }
    }

    void melt_ices()
    {
        vector<vector<int>> copy_ices_map = ices_map;

        for (int row = 1; row < N - 1; ++row)
        {
            for (int col = 1; col < M - 1; ++col)
            {
                if (copy_ices_map[row][col] > 0)
                {
                    ices_map[row][col] -= check_around(copy_ices_map, row, col);
                    ices_map[row][col] = max(0, ices_map[row][col]);
                }
            }
        }

        return;
    }

    int check_around(vector<vector<int>> copy_ices_map, int r, int c)
    {
        int next_r, next_c;
        int count_zero = 0;

        for (auto d : delta)
        {
            next_r = r + d.first;
            next_c = c + d.second;

            if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < M)
            {
                if (copy_ices_map[next_r][next_c] == 0)
                {
                    count_zero += 1;
                }
            }
        }

        return count_zero;
    }

    void dfs(int r, int c)
    {
        visited[r][c] = 1;

        int next_r, next_c;
        for (auto d : delta)
        {
            next_r = r + d.first;
            next_c = c + d.second;
            if (next_r >= 1 && next_c >= 1 && next_r < N-1 && next_c < M-1)
            {
                if (ices_map[next_r][next_c] > 0 && visited[next_r][next_c] == 0)
                {
                    dfs(next_r, next_c);
                }
            }
        }

        return;
    }

    int solve()
    {
        int year = 0;

        while (true)
        {
            int count = 0;
            visited = vector<vector<int>>(N, vector<int>(M, 0));

            for (int row = 1; row < N - 1; ++row)
            {
                for (int col = 1; col < M - 1; ++col)
                {
                    if (ices_map[row][col] > 0 && visited[row][col] == 0)
                    {
                        if (count >= 2)
                            return year;
                        dfs(row, col);
                        count += 1;
                    }
                }
            }

            if (count == 0)
                return 0;

            melt_ices();
            year += 1;

            // monitoring();
        }
        return 0;
    }

    void monitoring()
    {
        cout << endl;
        for (auto r : ices_map)
        {
            for (auto c : r)
            {
                cout << c << " ";
            }
            cout << endl;
        }
    }

private:
    int N, M;
    vector<vector<int>> ices_map;

    vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> visited;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    solver_2573 solver(N, M);
    cout << solver.solve() << endl;

    return 0;
}