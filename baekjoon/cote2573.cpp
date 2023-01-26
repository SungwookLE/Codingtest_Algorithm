/**
 * @brief 백준2573번 문제: 빙산
 * @brief 이런~ 빙산 1차시도: 시간초과 뭥미... ;;
 * @brief 2차시도: 시간초과 실패 ㅠㅠ.. dfs를 포기해야하는건가 근데 bfs로 풀어도 이 문제같은 경우는 시간복잡도가 같은건데...
 * @brief 3차시도: 백준에 질문해서 해결함.. 와 대박
 * check_around 에서 값 복사에 따라서 시간 크게 차이 난다는걸.. 알게되었습니다.
 * stl의 vector 가 값을 복사할 때, 하나씩 복사해간다는 사실을 망각하고 있었습니다.
 * 이에 check_ around 함수에서 맵을 복사해오지 않고., 클래스의 멤버 변수로 선언하여 사용하였더니.. 시간초과 해결하였습니다.
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
        copy_ices_map = ices_map;

        for (int row = 1; row < N - 1; ++row)
        {
            for (int col = 1; col < M - 1; ++col)
            {
                if (copy_ices_map[row][col] > 0)
                {
                    ices_map[row][col] -= check_around(row, col);
                    ices_map[row][col] = max(0, ices_map[row][col]);
                }
            }
        }

        return;
    }

    // 시간초과가 났던 코드에는 함수의 프로토타입에 check_around(vector<vector<int>> check_map, int r, int c) 로 선언어 되어있었다. 
    // 모든 배열 요소마다 맵을 복사해오면서 맵복사 시간복잡도(O(NM))이 소요되어 시간 소모가 컸던 것이 문제였다.
    // 이에 check_ around 함수에서 맵을 복사해오지 않고., 클래스의 멤버 변수로 선언하여 사용하였더니.. 시간초과 해결하였습니다.
    int check_around(int r, int c) 
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
            if (next_r >= 1 && next_c >= 1 && next_r < N - 1 && next_c < M - 1)
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
                        dfs(row, col);
                        count += 1;
                        if (count >= 2)
                            return year;
                    }
                }
            }

            if (count == 0)
                return 0;

            melt_ices();
            year += 1;

            //monitoring();
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
    vector<vector<int>> copy_ices_map; // 이에 check_ around 함수에서 맵을 복사해오지 않고., 클래스의 멤버 변수로 선언하여 사용하였더니.. 시간초과 해결하였습니다.

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