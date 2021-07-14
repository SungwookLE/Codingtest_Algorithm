#include <iostream>
#include <vector>

class solver_2740{
    public:
    void insert(){
        std::cin >> N >> M;

        A = new int*[N];
        for (int i = 0; i < N; ++i){
            A[i] = new int[M];
            for (int j =0 ; j < M ; ++j){
                std::cin >> A[i][j];
            }
        }

        std::cin >> M >> K;
        B = new int*[M];
        for (int i = 0; i < M; ++i){
            B[i] = new int[K];
            for (int j =0 ; j < K ; ++j){
                std::cin >> B[i][j];
            }
        }
    }

    void monitor(){

        // std::cout << "N: " << N << " |M: " << M << " |K: " << K << std::endl;

        // std::cout << "A matrix: \n";
        // for (int i = 0; i < N; ++i){
        //     for (int j =0 ; j < M ; ++j){
        //         std::cout << A[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }

        // std::cout << "B matrix: \n";
        // for (int i = 0; i < M; ++i){
        //     for (int j =0 ; j < K ; ++j){
        //         std::cout << B[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }

        // std::cout << "C matrix: \n";
        for (int i = 0; i < N; ++i){
            for (int j =0 ; j < K ; ++j){
                std::cout << C[i][j] << " ";
            }
            std::cout << std::endl;
        }

    }

    void product(){
        C=new int* [N];
        for (int i =0 ; i < N ; ++i){
            C[i] = new int[K];
            for (int j = 0 ; j < K ; ++j){
                int temp=0;

                for (int p =0 ; p < M ;++p){
                    temp+=A[i][p] * B[p][j];
                }
                C[i][j] = temp;
            }
        }

    }

    private:
    int N, M, K;
    int** A;
    int** B;
    int** C;

};

int main(){

    solver_2740 solver;
    solver.insert();
    solver.product();
    solver.monitor();


    return 0;
}