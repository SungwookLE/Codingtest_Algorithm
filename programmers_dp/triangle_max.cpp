#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> t) {
    int answer = 0;

    for (int i = t.size() - 1; i > 0 ; i--)
    {
        for (int j = 0; j < t[i].size() - 1; j++)
        {
            if (t[i][j] > t[i][j + 1])
            {
                t[i - 1][j] += t[i][j];
            }
            else
            {
                t[i - 1][j] += t[i][j + 1];
            }
        }
    }
    //bottom-up으로 가면 바로 풀리네 ㅋㅋ,,
    answer = t[0][0];

    return answer;
}
