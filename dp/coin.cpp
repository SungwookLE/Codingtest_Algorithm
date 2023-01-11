/**
 * @date 2023-01-11
 * @brief 특정 금액을 만들 수 있는 동전의 최소 개수를 찾아라
 * @brief DP문제를 만나면 항상 점화식을 고민해야하고, 써야한다.
 * @image img/2023-01-11-23-16-21.png
 */

#include <iostream>
#include <vector>
#define X -1

using namespace std;
class solver_coiner
{
public:
    solver_coiner(int _input)
    {
        input = _input;
        dp = vector<int>(max(input, 5) + 1, 0);
        dp[0] = X;
        dp[1] = X;
        dp[2] = X;
        dp[3] = 1;
        dp[4] = X;
        dp[5] = 1;
    }
    int solve()
    {
        for (int i = 6; i <= input; ++i)
        {
            if ((dp[i - 3] != X) && (dp[i - 5] != X))
                dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
            else
            {
                if ((dp[i - 3] == X) && (dp[i - 5] != X))
                {
                    dp[i] = dp[i - 5] + 1;
                }
                else if ((dp[i - 3] != X) && (dp[i - 5] == X))
                {
                    dp[i] = dp[i - 3] + 1;
                }
                else
                {
                    dp[i] = X;
                }
            }
        }

        for (int i = 0; i <= input; ++i)
        {
            cout << dp[i] << " ";
        }
        cout << endl;

        if (dp[input] >= 999)
            return -1;
        else
            return dp[input];
    }

private:
    int input;
    vector<int> dp;
};

int main()
{
    int N;
    cin >> N;
    solver_coiner solver(N);
    cout << solver.solve() << endl;

    return 0;
}
