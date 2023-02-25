/**
 * @brief 백준 20112번, 쉬운문제임
 * @date 2023.02.25.
 */


#include <iostream>
#include <vector>

using namespace std;

class solver_20112{
    public:
    solver_20112(int _N): N(_N){
        arr.resize(N, vector<char>(N,' '));
        for(int i = 0 ; i < N ; ++i){
            for(int j =0; j < N ; ++j){
                cin >> arr[i][j];
            }
        }
    }

    void solve(){

        int col_idx = N-1;
        int row_idx = N-1;

        while(!arr.empty()){

            auto row = arr[row_idx];
            for(int i = 0 ; i <= row_idx ; ++i){
                if(row[i] != arr[i][col_idx]){
                    cout << "NO" << endl;
                    return;
                }
                else
                    arr[i].pop_back();
                
            }
            arr.pop_back();

            col_idx--;
            row_idx--;
        }

        cout << "YES" << endl;

    }


    private:
    int N;
    vector<vector<char>> arr;


};

int main(int argc, char **argv){
    int N;
    cin >> N;
    solver_20112 solver(N);
    solver.solve();


 return 0;   
}

