/**
 * @brief 백준 #25430번 문제: 1차시도 메모리초과 512MB 까지만 쓰라고 함.., int 1개가 4byte 니까 256*10^6*2 = 16 * 10^3 사이즈의 2차원 행렬 2개를 쓸수 있다는 말
 * @date 2023-02-13
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solver_25430{

    public:
    solver_25430(int _N, int _M){
        N = _N;
        M = _M;
        kernels = vector<vector<int>>(N+1, vector<int>(N+1,0));
        visited = vector<vector<int>>(N+1, vector<int>(N+1,0));

        for(int i=0 ; i < M ; ++i){
            int s, g, c;
            cin >> s >> g >> c;
            kernels[s][g] = c;
            kernels[g][s] = c;
        }

        cin >> S >> G;
    }

    void monitor(){
        cout << endl;
        for(int i = 1 ; i <= N ; ++i){
            for(int j = 1 ; j <= N ; ++j){
                cout << kernels[i][j] << " ";
            }
            cout << endl;
        }
    }


    void digesta(){

        for(int i = 1 ; i <= N ; ++i){
            if (kernels[S][i] != 0){
                opens.push_back({S, i, kernels[S][i]});
                visited[S][i] = S;
            }
        } 

        int cost =0;
        while(!opens.empty()){
            sort(opens.begin(), opens.end(), [](auto a, auto b){return a[2] > b[2];});
            vector<int> now = opens.back();

            opens.pop_back();

            while(now[2]<cost){
                opens.pop_back();
                now = opens.back();
                
                if(opens.empty()){
                    cout << "DIGESTA\n";
                    return;
                }
            }
            cost = now[2];

            if (now[1] == G){
                int from, to;

                from = visited[now[0]][now[1]];
                to = now[0];

                total_cost += kernels[to][G];
                // cout << G << "<-" << to << ": " << total_cost << endl;
                while(from != S){
                    total_cost += kernels[from][to];
                    // cout<< to << "<-" << from << ": " << total_cost << endl;
                    int temp = from;
                    from = visited[from][to];
                    to = temp;
                }
                total_cost += kernels[from][to];
                // cout<< to << "<-" << from << ": " << total_cost << endl;

                cout << total_cost << endl;
                return;
            }

            for(int i = 1 ; i <= N; ++i){
                if (kernels[now[1]][i] != 0 && visited[now[1]][i] == 0){
                    opens.push_back({now[1], i, kernels[now[1]][i]});
                    visited[now[1]][i] = now[0];
                }
            }
        }

        cout << "DIGESTA\n";
    }

    private:
    int N, M;
    int S, G;
    int total_cost=0;
    vector<vector<int>> kernels;
    vector<vector<int>> visited;
    vector<vector<int>> opens;


};

int main(){

    int N, M;
    cin >> N >> M;

    solver_25430 solver(N,M);
    solver.digesta();

    return 0;
}
