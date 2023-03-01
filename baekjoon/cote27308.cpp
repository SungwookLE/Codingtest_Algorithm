/**
 * @brief 백준 27308번: 흠.. 트라이 실패했는데. 세그먼트 트리를 배운것에 의의를 두고 세그먼트 트리 연습함(./famous_algorithm/segment_tree.cpp)
 * @date 2023-02-25
 */

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

class solver_27308
{

public:
    solver_27308(ll _N, ll _X, ll _Y, ll _Z) : N(_N), X(_X), Y(_Y), Z(_Z)
    {
        s = vector<ll>(X, N);
        for (ll i = 0; i < Y; ++i)
            s[i] = Z - 1;
    }

    void permutation(ll length, ll idx, ll nested, vector<ll> v)
    {
        if (length == N)
        {
            // for (auto a : v)
            //     cout << a << " ";
            // cout << endl;

            answer += 1;
            answer = answer % (1000000007);
            return;
        }
        else
        {
            for (ll i = 0; i < X; ++i)
            {
                if (i == idx)
                {
                    if (s[i] > nested + 1)
                    {
                        v.push_back(i + 1);
                        permutation(length + 1, i, nested + 1, v);
                        v.pop_back();
                    }
                }
                else
                {
                    v.push_back(i + 1);
                    permutation(length + 1, i, 0, v);
                    v.pop_back();
                }
            }
        }
    }

    void ans()
    {
        cout << answer << endl;
    }

private:
    ll N, X, Y;
    ll Z;
    vector<ll> s;
    int answer = 0;
};

int main()
{
    ll N, X, Y;
    ll Z;
    cin >> N >> X >> Y >> Z;
    vector<ll> v;
    solver_27308 solver(N, X, Y, Z);
    solver.permutation(0, -1, 0, v);
    solver.ans();

    return 0;
}