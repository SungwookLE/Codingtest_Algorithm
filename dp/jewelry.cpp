/**
 * @date 2023-01-11
 * @brief 가방에 담을 수 있는 보석의 최대 값어치를 담아서 훔쳐라
 * @brief DP문제를 만나면 항상 점화식을 고민해야하고, 써야한다.
 * @image img/2023-01-11-23-44-10.png
 */

#include <iostream>
#include <vector>

using namespace std;

class solver_jewerly
{
public:
    solver_jewerly(int _N, int _K)
    {
        N = _N;
        K = _K;

        for (int i = 0; i < N; ++i)
        {
            int W, P;
            cin >> W >> P;
            jewerlys.push_back(make_pair(W, P));
        }
        DP = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));
    }
    int solve()
    {

        for (int row = 1; row <= N; ++row)
        {
            int W = jewerlys[row].first;
            int P = jewerlys[row].second;
            for (int col = 1; col <= K; ++col)
            {
                if (W <= col)
                    DP[row][col] = max(DP[row - 1][col], DP[row - 1][col - W] + P);
                else
                    DP[row][col] = DP[row - 1][col];
            }
        }
        return DP[N][K];
    }

private:
    int N, K;
    vector<pair<int, int>> jewerlys = {{0, 0}};
    vector<vector<int>> DP;
};

int main()
{
    int N, K;
    cin >> N >> K;

    solver_jewerly solver(N, K);
    cout << solver.solve() << endl;

    return 0;
}