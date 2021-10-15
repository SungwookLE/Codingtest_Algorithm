#include <iostream>
#include <vector>

class solver_10830{
public:

    std::vector<std::vector<long long int>> matrixMul(std::vector<std::vector<long long int>> A, std::vector<std::vector<long long int>> B){
        int n =A.size();
        std::vector<std::vector<long long int>> C(n, std::vector<long long int>(n));
            for(int row =0 ; row < n ; ++row){
                for(int col =0 ; col <n ; ++col){
                    for(int prod =0 ; prod < n ; ++prod)
                        C[row][col] += A[row][prod]*B[prod][col];

                    C[row][col] %= 1000;
                }    
            }
        return C;
    }

    std::vector<std::vector<long long int>> matrixPow(std::vector<std::vector<long long int>> A, int pow){
        if (pow == 0 ) return ones;
        else if (pow == 1) return A;
        else if ( pow % 2 == 0){
            std::vector<std::vector<long long int>> temp = matrixPow(A, pow/2);
            return matrixMul(temp, temp);
        }
        else{
            std::vector<std::vector<long long int>> temp = matrixPow(A, pow-1);
            return matrixMul(temp, A);
        }
    }

    void insert(){
        std::cin >> N >> B;
        mat.resize(N, std::vector<long long int>(N));
        ones.resize(N, std::vector<long long int>(N));

        for(long long int i =0 ; i < N ; ++i){
            for (long long int j =0 ; j < N ; ++j){
                std::cin >> mat[i][j];
                ones[i][j] =1;
            }    
        }
    }

    int N;
    int B;
    std::vector<std::vector<long long int>> mat;


private:
    std::vector<std::vector<long long int>> ones;
};

int main(){
    solver_10830 solver;
    solver.insert();
    auto ans = solver.matrixPow(solver.mat, solver.B);
    for (auto row : ans){
        for (auto col : row)
            std::cout << col % 1000 << " ";
        std::cout << std::endl;
    }

    return 0;
}