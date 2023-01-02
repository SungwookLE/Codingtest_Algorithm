/*
@22.1.1.
https://www.acmicpc.net/problem/8958
*/

#include <iostream>
#include <string>

using namespace std;
int solver(string ox);

int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i)
    {
        string ox;
        cin >> ox;
        cout << solver(ox) << endl;
    }

    return 0;
}

int solver(string ox)
{
    int res = 0;
    int score = 0;
    for (int i = 0; i < ox.length(); ++i)
    {

        if (ox[i] == 'O')
            score += 1;
        else
            score = 0;

        res += score;
    }
    return res;
}
