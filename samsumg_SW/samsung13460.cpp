/**
 * @date 2023-03-05
 * @brief 삼성SW 역량테스트 문제: #13460
 * @brief 레퍼런스: https://junbastick.tistory.com/37
 * @brief BFS로 푸는 접근은 맞았고, 나는 RED공만 주체로 해서 진행하면서 BLUE 공은 예외적으로 처리하려고 하였는데, RED공, BLUE공 둘다 주체로서 처리해주어야 했음
 */

#include <iostream>
#include <queue>

using namespace std;

typedef struct
{
    int Rx, Ry; // RED
    int Bx, By; // BLUE
    int Count;
} step;

class solver_13460
{
public:
    solver_13460(int _H, int _W) : H(_H), W(_W)
    {

        int Rx = 0, Ry = 0, Bx = 0, By = 0;
        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                cin >> map[i][j];
                if (map[i][j] == 'R')
                    Rx = i, Ry = j;
                else if (map[i][j] == 'B')
                    Bx = i, By = j;
            }
        }
        BFS(Rx, Ry, Bx, By);
    }

    void move(int &rx, int &ry, int &distance, int &i)
    {
        while (map[rx + dx[i]][ry + dy[i]] != '#' && map[rx][ry] != 'O')
        {
            rx += dx[i];
            ry += dy[i];
            distance += 1;
        }
    }

    void BFS(int Rx, int Ry, int Bx, int By)
    {
        queue<step> q;
        q.push({Rx, Ry, Bx, By, 0});
        visit[Rx][Ry][Rx][Ry] = true;
        while (!q.empty())
        {
            int rx = q.front().Rx;
            int ry = q.front().Ry;
            int bx = q.front().Bx;
            int by = q.front().By;
            int count = q.front().Count;
            q.pop();

            if (count >= 10)
                break;

            for (int i = 0; i < 4; ++i)
            {
                int nrx = rx, nry = ry, nbx = bx, nby = by;
                int rc = 0, bc = 0, ncount = count + 1;

                move(nrx, nry, rc, i);
                move(nbx, nby, bc, i);

                if (map[nbx][nby] == 'O')
                    continue;
                if (map[nrx][nry] == 'O')
                {
                    cout << ncount << endl;
                    return;
                }

                if (nrx == nbx && nry == nby)
                {
                    if (rc > bc)
                        nrx -= dx[i], nry -= dy[i];
                    else
                        nbx -= dx[i], nby -= dy[i];
                }

                if (visit[nrx][nry][nbx][nby])
                    continue;
                visit[nrx][nry][nbx][nby] = true;
                q.push({nrx, nry, nbx, nby, ncount});
            }
        }
        cout << -1 << endl;
    }

private:
    int H, W;
    char map[11][11];
    bool visit[11][11][11][11];
    int N, M;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
};

int main()
{
    int H, W;
    cin >> H >> W;
    solver_13460 solver(H, W);
    return 0;
}