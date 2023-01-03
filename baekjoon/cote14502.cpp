/**
 * @date 2023-01-02
 * @brief 첫번째 시도(실패): 가장 영역이 큰 부분 (DFS)을 찾아낸 후에, 면적이 큰 부분부터 선 차단을 하려고 하였다. 근데 이렇게 하면 바이러스 전파 속도에 따른 차단 전략을 구사할 수가 없다
 * @brief 두번째 시도(실패): 흠... 벽 세우는것도 좀 생각해봐야하네..
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> map;
vector<vector<int>> walls;

int row, col;

void space(int r, int c, vector<vector<int>> &check)
{
    check[r][c] = 2; // means checked!

    for (auto d : delta)
    {
        int forward_r = r + d[0];
        int forward_c = c + d[1];

        if ((forward_r < map.size()) && (forward_c < map[0].size()) && (forward_r >= 0) && (forward_c >= 0) && check[forward_r][forward_c] == 0)
        {
            space(forward_r, forward_c, check);
        }
    }
}

void makeWall(int r, int c, int cnt, vector<vector<int>> check)
{
    if (cnt == 3)
    {
        space(r, c, check);
        return;
    }

    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
        {
            walls[r][c] = 1;
            makeWall(cnt + 1);
            walls[r][c] = 0;
        }
    }
}

int main()
{
    cin >> row >> col;

    map = vector<vector<int>>(row, vector<int>(col, 0));
    vector<vector<int>> check(row, vector<int>(col, 0));

    vector<vector<int>> starts;
    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
        {
            cin >> map[r][c];
            if (map[r][c] == 2)
            {
                starts.push_back({r, c});
            }
        }
    }
    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c < col; ++c)
        {
            if (map[r][c] == 0)
            {
                walls.push_back({r, c});
                map[r][c] = 3;
            }

            if (walls.size() == 3)
            {
                check = map;
                // DFS 호출하고,
                for (auto s : starts)
                    space(s[0], s[1], check);

                count += 1;
                for (int r = 0; r < row; ++r)
                {
                    for (int c = 0; c < col; ++c)
                        cout << check[r][c] << " ";
                    cout << endl;
                }
                cout << endl;

                map[walls[0][0]][walls[0][1]] = 0;
                walls.erase(walls.begin());
            }
        }
    }

    return 0;
}
