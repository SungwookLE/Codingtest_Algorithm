#include <iostream>

class solver_10830{
    public:
    void insert(){
        std::cin >> N >> B;

        A = new long long int*[N];
        answer = new long long int*[N];
        init_A = new long long int*[N];

        for(int i =0 ; i < N ; ++i){
            A[i] = new long long int[N];
            answer[i] = new long long int[N];
            init_A[i]  = new long long int[N];
            
            for(int j =0 ; j < N; ++j){
                std::cin >> A[i][j] ;
                A[i][j] %= 1000;
                init_A[i][j]  = A[i][j];
            }
        }
    }

    void monitor(long long int **monit){
        for(int i=0 ; i < N ; ++i){
            for(int j =0; j < N ; ++j)
                std::cout << monit[i][j] << " ";
            std::cout << std::endl;
        }
    }

    void solver(){
        if (B==1){
            monitor(A);
            return;
        }    
        int power = 1;
        while(B>power){
            if ( power*2  > B){
                for(int row = 0 ; row < N ; ++row){
                    for(int col =0 ; col < N ; ++col){
                        long long temp  = 0;
                        for(int prod =0 ; prod < N ; ++ prod){
                            temp += A[row][prod] * init_A[prod][col];
                        }
                        answer[row][col] = temp % 1000;
                    }
                }
                power+=1;
                // std::cout << "\nodd answer: \n";
                // monitor(answer);
            }
            else {
                for(int row = 0 ; row < N ; ++row){
                    for(int col =0 ; col < N ; ++col){
                        long long temp  = 0;
                        for(int prod =0 ; prod < N ; ++ prod){
                            temp += A[row][prod] * A[prod][col];
                        }
                        answer[row][col] = temp % 1000;
                    }
                }
                power *= 2;
                // std::cout << "\neven answer: \n";
                // monitor(answer);
            }

            for(int row = 0; row < N ; ++row){
                for(int col =0; col < N ; ++col){
                    A[row][col] = answer[row][col];
                }    
            }
        }
        monitor(answer);
        return;
    }


    private:
        long long int **answer ;
        long long int **A;
        long long int **init_A;
        int N, B;
};

int main(){
    solver_10830 solver;
    solver.insert();
    solver.solver();

    return 0;
}