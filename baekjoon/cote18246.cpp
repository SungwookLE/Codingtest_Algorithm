/**
 * @brief 백준 18246번 문제: 색종이와 쿼리 (혼자선 못 풀겠음)
 * @brief 구글링 하였음: 데이터셋 정리 (IMOS 방법 사용) https://driip.me/65d9b58c-bf02-44bf-8fba-54d394ed21e0
 * @brief 쿼리 (2차원 벡터에서 최대값 출력): 세그먼트 트리를 이용하면 됨 (https://github.com/md1284/Algorithm_Prob/blob/master/%EB%B0%B1%EC%A4%80_18246%EB%B2%88_%EC%83%89%EC%A2%85%EC%9D%B4%EC%99%80%20%EC%BF%BC%EB%A6%AC.txt)
 * @date 2023-02-20
 */

#include <iostream>
#include <vector>
#define SSIZE 1500

using namespace std;
class Segment2D
{
    /**
     * @brief 구간 최대값을 구하는 2차원 세그먼트 트리
     * @brief https://github.com/md1284/Algorithm_Prob/blob/master/%EB%B0%B1%EC%A4%80_18246%EB%B2%88_%EC%83%89%EC%A2%85%EC%9D%B4%EC%99%80%20%EC%BF%BC%EB%A6%AC.txt
     */
public:
    Segment2D(int n): n(n), tree(2*n, vector<int>(2*n,0)) {}

    void init(vector<vector<int>> &v) {
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++)
                tree[i+n][j+n] = v[i][j];
        }

        for(int i = n; i<2*n; i++) {
            for(int j = n-1; j>0; j--)
                tree[i][j] = max(tree[i][j<<1], tree[i][j<<1|1]);
        }

        for(int i = n-1; i>0; i--) {
            for(int j = 1; j<2*n; j++)
                tree[i][j] = max(tree[i<<1][j], tree[i<<1|1][j]);
        }
    }

    void update(int y, int x, int v) {
        tree[y+n][x+n] = v;

        for(int i = x+n; i>1; i>>=1)
            tree[y+n][i>>1] = max(tree[y+n][i], tree[y+n][i^1]);
        
        for(y = y+n; y>1; y>>=1) {
            for(int i = x+n; i>=1; i>>=1)
                tree[y>>1][i] = max(tree[y][i], tree[y^1][i]);
        }
    }

    int get1d(int y, int x1, int x2) {
        int ret = 0;
        for(x1 += n, x2 += n+1; x1<x2; x1>>=1, x2>>=1) {
            if(x1&1)
                ret = max(ret, tree[y][x1++]);
            if(x2&1)
                ret = max(ret, tree[y][--x2]);
        }
        return ret;
    }

    int get(int y1, int x1, int y2, int x2) {
        int ret = 0;
        for(y1 += n, y2 += n+1; y1<y2; y1>>=1, y2>>=1) {
            if(y1&1)
                ret = max(ret, get1d(y1++, x1, x2));
            if(y2&1)
                ret = max(ret, get1d(--y2, x1, x2));
        }
        return ret;
    }

private:
    int n;
    vector<vector<int>> tree; // tree: 배열은 세그먼트 트리를 저장한 배열
};

class solver_18246
{
public:
    solver_18246(int _N, int _M)
    {
        N = _N;
        M = _M;

        int y1, x1, y2, x2;
        papers = vector<vector<int>>(SSIZE*2, vector<int>(SSIZE*2, 0));

        for (int i = 0; i < N; ++i){
            cin >> y1 >> x1 >> y2 >> x2;

            if (y2 > max_y)
                max_y = y2;
            if (x2 > max_x)
                max_x = x2;

            papers[y1][x1]++;
            papers[y1][x2]--;
            papers[y2][x1]--;
            papers[y2][x2]++;
        }

        for (int i = 0; i < M; ++i){
            cin >> y1 >> x1 >> y2 >> x2;
            querys.push_back({y1, x1, y2, x2});
        }

        for (int c = 1; c < SSIZE; ++c){
            for (int r = 0; r < SSIZE; ++r){
                papers[r][c] += papers[r][c - 1];
            }
        }

        for (int r = 1; r < SSIZE; ++r){
            for (int c = 0; c < SSIZE; ++c){
                papers[r][c] += papers[r - 1][c];
            }
        }

    }

    void get_querys()
    {
        Segment2D S(SSIZE+5);
        S.init(papers);
        for (auto q : querys)
        {
            int max_val = S.get(q[0], q[1], q[2]-1, q[3]-1);
            cout << max_val << endl;
        }
    }

private:
    int N, M;
    int max_y = 0, max_x = 0;
    vector<vector<int>> papers;
    vector<vector<int>> querys;

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    solver_18246 solver(N, M);
    solver.get_querys();

    return 0;
}