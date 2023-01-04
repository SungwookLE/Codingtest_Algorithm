/**
 * @date 2023-01-02
 * @brief 첫번째 시도(실패): 가장 영역이 큰 부분 (DFS)을 찾아낸 후에, 면적이 큰 부분부터 선 차단을 하려고 하였다. 근데 이렇게 하면 바이러스 전파 속도에 따른 차단 전략을 구사할 수가 없다
 * @brief 두번째 시도(실패): 흠... 벽 세우는것도 좀 생각해봐야하네.. 조합 만드는것도 좀 복잡혀 
 * @brief 세번째 시도(성공): 벽세우는 조합 만들기 고민 끝에 성공했음.. 끝
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> map;
vector<vector<int>> starts;
vector<int> answers;
int row, col;

void space(int r, int c, vector<vector<int>> &check)
{
    for (auto d : delta)
    {
        int forward_r = r + d[0];
        int forward_c = c + d[1];

        if ((forward_r < map.size()) && (forward_c < map[0].size()) && (forward_r >= 0) && (forward_c >= 0) && check[forward_r][forward_c] == 0)
        {
            check[forward_r][forward_c] = 2; // means checked!
            space(forward_r, forward_c, check);
        }
    }
}

void makeWall(int cnt, int cur_r, int cur_c, vector<vector<int>> check)
{
    int survive = 0;
    if (cnt == 3)
    {
        // DFS 호출: 갈수 있는 모든 지점에 2를 전파
        for (auto s : starts)
            space(s[0], s[1], check);
        cout << endl;
        for (int r = 0; r < row; ++r)
        {
            for (int c = 0; c < col; ++c)
            {
                cout << check[r][c] << " ";
                if (check[r][c] == 0)
                    survive += 1;
            }
            cout << endl;
        }
        answers.push_back(survive);
        check = map; //  초기화
        return;
    }

    for (int r = cur_r; r < row; ++r)
    {
        // 백트래킹: 벽을 세울수 있는 모든 조합 만들기 Combination
        int start_c;
        if (r != 0)
            start_c = ((cur_r * cur_c / r) < cur_c) ? 0 : cur_c;
        else
            start_c = cur_c;

        for (int c = start_c; c < col; ++c)
        {
            if (check[r][c] == 0)
            {
                check[r][c] = 1;
                makeWall(cnt + 1, r, c, check);
                check[r][c] = 0;
            }
        }
    }
}

int main()
{
    cin >> row >> col;
    map = vector<vector<int>>(row, vector<int>(col, 0));
    vector<vector<int>> check(row, vector<int>(col, 0));

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

    check = map;
    makeWall(0, 0, 0, check);

    sort(answers.begin(), answers.end(), [](auto a, auto b)
         { return a > b; });

    cout << answers.front() << endl;
    return 0;
}