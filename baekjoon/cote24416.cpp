/**
 * @brief 백준 24416번 문제
 * @date 2023-01-15
 */


#include <iostream>
#include <vector>

using namespace std;

class solver_24416{

    public:
    solver_24416(int _N): N(_N) { DP = vector<int>(_N+1,0); }

    void DP_solve(){
        DP[1] = 1;
        DP[2] = 1;
        int count_iter = 0;
        for(int i = 3 ; i <= N ; ++i){
            DP[i] = DP[i-1] + DP[i-2];
            // DP[2] = DP[1] + DP[0] = 1
            count_iter +=1;
        }
        cout << count_iter  << endl;
    }

    int recur(int v){

        if (v == 1 || v == 2){
            count_recur +=1;
            return 1; 
        }
        else{
            return recur(v-1)+recur(v-2);
        }
        // recur(3) = recur(2) + recur(1) = 2
        // recur(4) = recur(3) + recur(2) = recur(2) + recur(1) + recur(2) = 3
        // recur(5) = recur(4) + recur(3) = 3 + 2 
    }

    void recur_solve(){
        int ret = recur(N);
        cout << count_recur << endl;
    }

    private:
    int N;
    vector<int> DP;
    int count_recur= 0;


};

int main(){
    int N;
    cin >> N;
    solver_24416 solver(N);
    solver.recur_solve();
    solver.DP_solve();

    return 0;
}