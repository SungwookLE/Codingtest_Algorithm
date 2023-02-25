/**
 * @brief 백준 27308번
 * @date 2023-02-25
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solver_27308{

    public:
    solver_27308(int _N, int _X, int _Y, int _Z): N(_N), X(_X), Y(_Y), Z(_Z){
       s.resize(X, N);
       for(int i = 0 ; i < Y ; ++i)
            s[i] = Z-1;
    
        
    }

    void make_permutation(int ssize){

        if (ssize == N){
            for(auto a : s)
                cout << a << " ";
            cout << endl;
            
            samples+=1;
            return;
        }
        else{
            for(int i =0 ; i < s.size(); ++i){
                if (s[i] > 0){
                    s[i] -=1;
                    make_permutation(ssize+1);
                    s[i] +=1;
                }
            }
        }
    }

    void show(){
        cout << samples << endl;
        
    }

    private:
    int N, X, Y, Z;
    string comb;
    vector<int> s;
    int samples =0;
};

int main(){
    int N, X, Y, Z;
    cin >> N >> X>>Y>>Z;
    solver_27308 solver(N,X,Y,Z);
    solver.make_permutation(0);
    solver.show();




    return 0;
}