/**
 * @brief #2048 1차 시도 4% 까지 가고 성공,, 음 디버깅해보면 승산있나..?
 * @brief 오 웬일이래 2차 시도 성공 ㅎㅎ, 이 문제는 약간 세부 구현 문제에 가깝다. 특정 알고리즘을 쓰는 문제라기 보다는
 * @date 2023-03-28
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class solver_2048
{

public:
    solver_2048(int _N) : N(_N)
    {
        board = vector<vector<int>>(N, vector<int>(N, 0));
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                cin >> board[i][j];
        }
    }

    vector<vector<int>> move(vector<vector<int>> nowBoard, vector<int> d)
    {
        // 일단 0없이 밀착시킨 후에, 앞에서 부터 같은 숫자가있는지 체크하고 터트린 후에 한 칸씩 땡겨주기

        if (d[0] == -1 && d[1] == 0)
        {
            for (int j = 0; j < N; ++j)
            {
                for (int i = 0; i < N - 1; ++i)
                {
                    int inc = 1;
                    while ((i + inc) < N - 1 && nowBoard[i + inc][j] == 0)
                    {
                        inc++;
                    }
                    if (nowBoard[i][j] == 0)
                    {
                        nowBoard[i][j] = nowBoard[i + inc][j];
                        nowBoard[i + inc][j] = 0;
                    }
                }
            }

            for (int j = 0; j < N; ++j)
            {
                bool isPang = false;
                for (int i = 0; i < N - 1; ++i)
                {
                    // if (isPang == false)
                    {
                        if (nowBoard[i][j] == nowBoard[i + 1][j])
                        {
                            isPang = true;
                            nowBoard[i][j] *= 2;
                            nowBoard[i + 1][j] = 0;
                        }
                    }
                }
            }

            for (int j = 0; j < N; ++j)
            {
                for (int i = 0; i < N - 1; ++i)
                {
                    int inc = 1;
                    while ((i + inc) < N - 1 && nowBoard[i + inc][j] == 0)
                    {
                        inc++;
                    }
                    if (nowBoard[i][j] == 0)
                    {
                        nowBoard[i][j] = nowBoard[i + inc][j];
                        nowBoard[i + inc][j] = 0;
                    }
                }
            }
        }
        if (d[0] == 1 && d[1] == 0)
        {
            for (int j = 0; j < N; ++j)
            {
                for (int i = N - 1; i > 0; --i)
                {
                    int inc = -1;
                    while ((i + inc) > 0 && nowBoard[i + inc][j] == 0)
                    {
                        inc--;
                    }
                    if (nowBoard[i][j] == 0)
                    {
                        nowBoard[i][j] = nowBoard[i + inc][j];
                        nowBoard[i + inc][j] = 0;
                    }
                }
            }

            for (int j = 0; j < N; ++j)
            {
                bool isPang = false;
                for (int i = N - 1; i > 0; --i)
                {
                    // if (isPang == false)
                    {
                        if (nowBoard[i][j] == nowBoard[i - 1][j])
                        {
                            isPang = true;
                            nowBoard[i][j] *= 2;
                            nowBoard[i - 1][j] = 0;
                        }
                    }
                }
            }
            for (int j = 0; j < N; ++j)
            {
                for (int i = N - 1; i > 0; --i)
                {
                    int inc = -1;
                    while ((i + inc) > 0 && nowBoard[i + inc][j] == 0)
                    {
                        inc--;
                    }
                    if (nowBoard[i][j] == 0)
                    {
                        nowBoard[i][j] = nowBoard[i + inc][j];
                        nowBoard[i + inc][j] = 0;
                    }
                }
            }
        }
        if (d[0] == 0 && d[1] == -1)
        {
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N - 1; ++j)
                {
                    int inc = 1;
                    while ((j + inc) < N - 1 && nowBoard[i][j + inc] == 0)
                    {
                        inc++;
                    }
                    if (nowBoard[i][j] == 0)
                    {
                        nowBoard[i][j] = nowBoard[i][j + inc];
                        nowBoard[i][j + inc] = 0;
                    }
                }
            }
            for (int i = 0; i < N; ++i)
            {
                bool isPang = false;
                for (int j = 0; j < N - 1; ++j)
                {
                    // if (isPang == false)
                    {
                        if (nowBoard[i][j] == nowBoard[i][j + 1])
                        {
                            isPang = true;
                            nowBoard[i][j] *= 2;
                            nowBoard[i][j + 1] = 0;
                        }
                    }
                }
            }
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N - 1; ++j)
                {
                    int inc = 1;
                    while ((j + inc) < N - 1 && nowBoard[i][j + inc] == 0)
                    {
                        inc++;
                    }
                    if (nowBoard[i][j] == 0)
                    {
                        nowBoard[i][j] = nowBoard[i][j + inc];
                        nowBoard[i][j + inc] = 0;
                    }
                }
            }
        }
        if (d[0] == 0 && d[1] == 1)
        {
            for (int i = 0; i < N; ++i)
            {
                for (int j = N - 1; j > 0; --j)
                {
                    int inc = -1;
                    while ((j + inc) > 0 && nowBoard[i][j + inc] == 0)
                    {
                        inc--;
                    }
                    if (nowBoard[i][j] == 0)
                    {
                        nowBoard[i][j] = nowBoard[i][j + inc];
                        nowBoard[i][j + inc] = 0;
                    }
                }
            }

            for (int i = 0; i < N; ++i)
            {
                bool isPang = false;
                for (int j = N - 1; j > 0; --j)
                {
                    // if (isPang == false)
                    {
                        if (nowBoard[i][j] == nowBoard[i][j - 1])
                        {
                            isPang = true;
                            nowBoard[i][j] *= 2;
                            nowBoard[i][j - 1] = 0;
                        }
                    }
                }
            }
            for (int i = 0; i < N; ++i)
            {
                for (int j = N - 1; j > 0; --j)
                {
                    int inc = -1;
                    while ((j + inc) > 0 && nowBoard[i][j + inc] == 0)
                    {
                        inc--;
                    }
                    if (nowBoard[i][j] == 0)
                    {
                        nowBoard[i][j] = nowBoard[i][j + inc];
                        nowBoard[i][j + inc] = 0;
                    }
                }
            }
        }

        return nowBoard;
    }

    void monitoring(vector<vector<int>> b)
    {
        for (auto row : b)
        {
            for (auto element : row)
            {
                cout << element << " ";
            }
            cout << endl;
        }
    }

    void solve(int depth, vector<vector<int>> nowBoard){

        if (depth==5){
            int temp = find_max(nowBoard);
            if (temp > ans){
                ans = temp;
            }

            return;
        }


        for(auto d : delta){
            auto bb = move(nowBoard, d);
            solve(depth+1, bb);
        }
    }

    int find_max(vector<vector<int>> b){
        int ans = 0;
        for(int i =0 ; i < N; ++i){
            for(int j =0 ; j < N ; ++j){
                if (b[i][j] > ans)
                    ans = b[i][j];
            }
        }
        return ans;
    }

    int ans = 0;
    vector<vector<int>> board;

    vector<vector<int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

private:
    int N;
};

unordered_map<char, int> delta_map = {{'^', 0}, {'v', 1}, {'<', 2}, {'>', 3}};

int main()
{
    int N;
    cin >> N;
    solver_2048 solver(N);
    solver.solve(0, solver.board);
    cout << solver.ans << endl;
    /*
    auto bb = solver.board;
    while(1){
        char T;
        cin >> T;
        bb = solver.move(bb, solver.delta[delta_map[T]]);
        solver.monitoring(bb);

    */

    
    return 0;
}