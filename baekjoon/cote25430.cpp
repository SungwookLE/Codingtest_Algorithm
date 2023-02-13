/**
 * @brief 백준 #25430번 문제: 1차시도 메모리초과 512MB 까지만 쓰라고 함.., int 1개가 4byte 니까 256*10^6*2 = 16 * 10^3 사이즈의 2차원 행렬 2개를 쓸수 있다는 말
 * @brief 2차시도 조금 고생해서 메모리 초과는 없앳는데 시간초과 ㅠ
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

        visited = vector<vector<int>>(2*M,vector<int>(2,0));

        for(int i=0 ; i < M ; ++i){
            int s, g, c;
            cin >> s >> g >> c;

            kernels.push_back({s,g,c});
            kernels.push_back({g,s,c});
        }

        cin >> S >> G;

    }

    void monitor(){
        cout << endl;
        for(auto k : kernels){
            for(auto kk : k)
                cout << kk << " ";
            cout << endl;
        }
    }

    void digesta(){

        for(int i = 0 ; i<kernels.size() ; ++i){
            if (kernels[i][0] == S){
                opens.push_back({S, kernels[i][1], kernels[i][2], i});
                visited[i]= {S, 0};
            }
        } 


        int cost =0;
        while(!opens.empty()){
            sort(opens.begin(), opens.end(), [](auto a, auto b){return a[2] > b[2];});
            vector<int> now = opens.back();
            opens.pop_back();

            while(now[2]<cost){
                now = opens.back();
                opens.pop_back();
                
                if(opens.empty()){
                    cout << "DIGESTA\n";
                    return;
                }
            }

            cost = now[2];

            if (now[1] == G){
                int from, idx, to;   

                idx = now[3];
                from = visited[idx][0];
                to = now[0];

                total_cost += kernels[idx][2];
                // cout << G << "<=" << to << ": " << total_cost << endl;
                while(from != S){
                    idx = visited[idx][1];
                    total_cost += kernels[idx][2];
                    // cout<< to << "<-" << from << ": " << total_cost << endl;

                    int temp = from;
                    from = visited[idx][0];
                    to = temp;
                }
                idx = visited[idx][1];
                total_cost += kernels[idx][2];
                // cout<< to << "<=" << from << ": " << total_cost << endl;

                cout << total_cost << endl;
                return;
            }
            

            for(int i = 0 ; i < kernels.size(); ++i){
                if (visited[i][0] == 0 && kernels[i][0] == now[1] ){
                    opens.push_back({now[1], kernels[i][1], kernels[i][2], i});
                    visited[i] = {now[0], now[3]};
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
