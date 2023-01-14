/**
 * @brief baekjoon2606번 문제, DFS로 문제 품
 * @date 2023-01-14
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class solver_2606{
    public:
    solver_2606(int _computer_N, int _network_N){
        computer_N = _computer_N;
        network_N = _network_N;
        checked = vector<int>(computer_N+1, 0);

        int computer1, computer2;
        for(int i = 0 ; i < network_N ; ++i){
            cin >> computer1 >> computer2;
            networks.push_back({computer1, computer2});
            networks.push_back({computer2, computer1});
        }
        sort(networks.begin(), networks.end());
    }

    void DFS(int to){
        checked[to]= 1;
        int next_to ;

        for(auto d: networks){
            next_to = d.second;
            if (d.first == to && checked[next_to] == 0){
                answer+=1;
                DFS(next_to);
            }
        }
    }

    int answer  =0;


    private:
    int computer_N, network_N;
    vector<pair<int,int>> networks;
    vector<int> checked;


};

int main(){
    int computer_N, network_N;
    cin >> computer_N >> network_N;
    solver_2606 solver(computer_N, network_N);
    solver.DFS(1);
    cout << solver.answer << endl;

    return 0;
}