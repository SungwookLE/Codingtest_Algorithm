/**
 * @date 2023-01-02
 * @brief 첫번째 시도(실패): 가장 영역이 큰 부분 (DFS)을 찾아낸 후에, 면적이 큰 부분부터 선 차단을 하려고 하였다. 근데 이렇게 하면 바이러스 전파 속도에 따른 차단 전략을 구사할 수가 없다
 */

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> map;
vector<vector<int>> flags;

void space(int r, int c, int flag)
{
    map[r][c] = 2; // means checked!
    flags[r][c] = flag;

    for (auto d : delta)
    {
        int forward_r = r + d[0];
        int forward_c = c + d[1];

        if ((forward_r < map.size()) && (forward_c < map[0].size()) && (forward_r >= 0) && (forward_c >= 0) && map[forward_r][forward_c] == 0)
        {
            space(forward_r, forward_c, flag);
        }
    }
}

int main()
{
    int row, col;
    cin >> row >> col;

    map = vector<vector<int>>(row, vector<int>(col, 0));
    vector<vector<int>> map_copy = map;
    flags = vector<vector<int>>(row, vector<int>(col, 0));

    vector<vector<int>> starts;
    for (int r = 0; r < row; ++r){
        for (int c = 0; c < col; ++c)
        {
            cin >> map[r][c];
            if (map[r][c] == 2)
            {
                starts.push_back({r, c});
            }
        }
    }

    vector<vector<int>> walls;
    for(int r = 0 ; r < row ; ++r){
        for(int c = 0 ; c < col ; ++c){

            if (map[r][c] == 0){
                walls.push_back({r,c});
                map[r][c] = 1;
            }

            if (walls.size() == 3){
                // DFS 호출하고,
                int flag = -1;
                for (auto s : starts)
                {
                    space(s[0], s[1], flag);
                    flag--;
                }

                for (int r = 0; r < row; ++r)
                {
                    for (int c = 0; c < col; ++c)
                        cout << map[r][c] << " ";
                    cout << endl;
                }

                map[walls[0][0]][walls[0][1]] = 0;
                walls.erase(walls.begin());
            }

        }
    }

    return 0;
}
