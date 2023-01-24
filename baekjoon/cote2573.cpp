/**
 * @brief 백준2573번 문제: 빙산
 * @brief 이런~ 빙산 1차시도: 시간초과 뭥미... ;;
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
        ices = vector<vector<int>>(N, vector<int>(M, 0));

        for (int row = 0; row < N; ++row)
        {
            for (int col = 0; col < M; ++col)
            {
                cin >> ices[row][col];
                if (ices[row][col] != 0){
                    ice_place.push_back({row, col});
                }
            }
        }
    }

    bool melt_ices()
    {
        auto pictured_ices = ices;
        bool isAllmelted = true;
        vector<vector<int>> new_ice_place;

        for (auto ice : ice_place){
            int row = ice[0];
            int col = ice[1];
            if (ices[row][col] != 0){
                int count_zero = check_around(pictured_ices, row, col);
                ices[row][col] -= count_zero;
                if (ices[row][col] < 0)
                    ices[row][col] = 0;

                if (ices[row][col] > 0){
                    isAllmelted = false;
                    new_ice_place.push_back({row, col});
                }
            }
        }
        ice_place = new_ice_place;
        return isAllmelted;
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
                if (ices[next_r][next_c] != 0 && visited[next_r][next_c] == 0)
                {
                    dfs(next_r, next_c);
                }
            }
        }

        return;
    }

    int check_around(vector<vector<int>> pictured_ices, int r, int c)
    {
        int next_r, next_c;
        int count_zero = 0;

        for (auto d : delta)
        {
            next_r = r + d.first;
            next_c = c + d.second;

            if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < M)
            {
                if (pictured_ices[next_r][next_c] == 0)
                {
                    count_zero += 1;
                }
            }
        }

        return count_zero;
    }

    void monitoring()
    {
        cout << endl;
        for (auto r : ices)
        {
            for (auto c : r)
            {
                cout << c << " ";
            }
            cout << endl;
        }
    }

    int solve()
    {
        bool isAllmelted = false;
        int answer;

        while (!isAllmelted)
        {
            int count = 0;
            visited = vector<vector<int>>(N, vector<int>(M, 0));

            isAllmelted = melt_ices();
            answer += 1;

            for (auto ice : ice_place){
                int row = ice[0];
                int col = ice[1];
                if (ices[row][col] > 0 && visited[row][col] == 0){
                    dfs(row, col);
                    count += 1;
                }
            }
            // monitoring();
            if (count >= 2)
                return answer;
        }
        return 0;
    }

private:
    int N, M;
    vector<vector<int>> ices;
    vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> visited;
    vector<vector<int>> ice_place;
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