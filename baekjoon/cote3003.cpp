/*
@22.1.1.
https://www.acmicpc.net/problem/3003
*/

#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char **argv)
{
    vector<int> correct = {1, 1, 2, 2, 2, 8};
    vector<int> input(6, 0);
    vector<int> ans(6, 0);
    for (int i = 0; i < 6; ++i)
    {
        cin >> input[i];

        ans[i] = correct[i] - input[i];
        cout << ans[i] << " ";
    }

    return 0;
}