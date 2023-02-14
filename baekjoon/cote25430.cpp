/**
 * @brief 백준 #25430번 문제: 1차시도 메모리초과 512MB 까지만 쓰라고 함.., int 1개가 4byte 니까 256*10^6*2 = 16 * 10^3 사이즈의 2차원 행렬 2개를 쓸수 있다는 말
 * @brief 2차시도: 조금 고생해서 메모리 초과는 없앳는데 25%에서 시간초과
 * @brief 3차시도: algorithm 의 sort를 써서 매번 정렬하지 않고, priority queue를 써서 정렬해서 넣어주니까.., 시간초과는 해소되었는데 63%에서 틀렸다고 뜸 ㅠ 
 * @brief 4차시도: 흠.. visited 의 누적 경로를 저장하고 있었는데,,. 오버플로우가 있었는지 long long으로 바꾸어주니까 29점으로 부분 성공
 * @date 2023-02-13
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Container
{
    int from, to;
    long long cost;
    int idx;
    Container(int _from, int _to, long long _cost, int _idx) : from(_from), to(_to), cost(_cost), idx(_idx) {}
};

// cost 기준으로 작은값이 Top 을 유지하도록
struct cmp
{
    bool operator()(Container a, Container b)
    {
        return a.cost > b.cost;
    }
};

class solver_25430
{

public:
    solver_25430(int _N, int _M)
    {
        N = _N;
        M = _M;

        visited = vector<long long>(M, 0);

        for (int i = 0; i < M; ++i)
        {
            int s, g, c;
            cin >> s >> g >> c;
            kernels.push_back({s, g, c});
        }

        cin >> S >> G;
    }

    void digesta()
    {

        for (int i = 0; i < kernels.size(); ++i)
        {
            if (kernels[i][0] == S)
            {
                opens.push(Container(S, kernels[i][1], kernels[i][2], i));
                visited[i] = kernels[i][2];
            }
            else if (kernels[i][1] == S)
            {
                opens.push(Container(S, kernels[i][0], kernels[i][2], i));
                visited[i] = kernels[i][2];
            }
        }

        Container now(0, 0, 0, 0);
        while (!opens.empty())
        {
            now = opens.top();
            opens.pop();

            if (now.to == G)
            {
                cout << visited[now.idx] << endl;
                return;
            }

            for (int i = 0; i < kernels.size(); ++i)
            {
                if (visited[i] == 0 && kernels[i][2] > kernels[now.idx][2])
                {
                    if (kernels[i][0] == now.to)
                    {
                        visited[i] = visited[now.idx] + kernels[i][2];
                        opens.push(Container(now.to, kernels[i][1], visited[i], i));
                    }
                    else if (kernels[i][1] == now.to)
                    {
                        visited[i] = visited[now.idx] + kernels[i][2];
                        opens.push(Container(now.to, kernels[i][0], visited[i], i));
                    }
                }
            }
        }

        cout << "DIGESTA\n";
        return;
    }

    void monitor()
    {
        cout << endl;
        for (int i = 0; i < kernels.size(); ++i)
        {
            cout << kernels[i][0] << ", " << kernels[i][1] << ": " << visited[i] << endl;
        }
        cout << endl;
    }

private:
    int N, M;
    int S, G;
    vector<vector<int>> kernels;
    vector<long long> visited;
    priority_queue<Container, vector<Container>, cmp> opens;
};

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    solver_25430 solver(N, M);
    solver.digesta();
    // solver.monitor();

    return 0;
}
