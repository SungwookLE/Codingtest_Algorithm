#include <iostream>

using namespace std;

int N, M;
int x, y;
int K;

int map[21][21];
int order[1001];

int dice[7] = {0, 1, 2, 3, 4, 5, 6};
int value[7] = {0, 0, 0, 0, 0, 0, 0};

int main()
{

    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];
    for (int i = 0; i < K; ++i)
        cin >> order[i];

    pair<int, int> cur = {x, y};

    for (int i = 0; i < K; ++i)
    {
        bool in_map = false;
        switch (order[i])
        {
        case (1):
            if (cur.second + 1 < M)
            {
                in_map = true;
                cur.second += 1;
                int temp = dice[6];
                dice[6] = dice[4];
                dice[4] = dice[1];
                dice[1] = dice[3];
                dice[3] = temp;
            }
            break;
        case (2):
            if (cur.second - 1 >= 0)
            {
                in_map = true;
                cur.second -= 1;
                int temp = dice[6];
                dice[6] = dice[3];
                dice[3] = dice[1];
                dice[1] = dice[4];
                dice[4] = temp;
            }
            break;

        case (3):
            if (cur.first - 1 >= 0)
            {
                in_map = true;
                cur.first -= 1;
                int temp = dice[6];
                dice[6] = dice[5];
                dice[5] = dice[1];
                dice[1] = dice[2];
                dice[2] = temp;
            }
            break;

        case (4):
            if (cur.first + 1 < N)
            {
                in_map = true;
                cur.first += 1;
                int temp = dice[2];
                dice[2] = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[6];
                dice[6] = temp;
            }
            break;
        }

        if (in_map)
        {
            if (map[cur.first][cur.second] == 0)
            {
                map[cur.first][cur.second] = value[dice[1]];
            }
            else
            {
                value[dice[1]] = map[cur.first][cur.second];
                map[cur.first][cur.second] = 0;
            }
            cout << value[dice[6]] << endl;
        }
    }

    return 0;
}