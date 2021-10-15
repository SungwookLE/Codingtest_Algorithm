#include <iostream>
#include <vector>

//피보나치 수6
// ![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FzCH4A%2Fbtq0z0MTzkN%2FY3tgeZ6mGjz0PAMyoCyVT0%2Fimg.png)
// REF: https://cocoon1787.tistory.com/349

typedef std::vector<std::vector<long long int>> matrix;
matrix operator*(matrix& mtx_a, matrix& mtx_b){
        matrix c(2, std::vector<long long int>(2));

        for(int i = 0 ; i < 2 ; ++i)
            for(int j = 0 ; j < 2 ; ++j){
                for(int k =0 ; k <2; ++k)
                    c[i][j] += mtx_a[i][k] * mtx_b[k][j];
                c[i][j] %=1000000007;
            }

        return c;
    }

class solver_11444{
public:
    void insert(){
        std::cin >> N;
    }

    // N번째 피보나치 수를 1,000,000,007로 나눈 나머지를 출력한다.
    void solver(){
        while ( N > 0){
            if ( N%2 == 1 )
                ans = ans*a;
            a = a*a;
            N /=2;
        }
        std::cout << ans[0][1]<< std::endl;
    }

    

private:
    long long int N;
    matrix ans = {{1,0},{0,1}};
    matrix a = {{1,1},{1,0}};
    long long int mod = 1000000007;
};

int main(){
    solver_11444 solver;
    solver.insert();
    solver.solver();

    return 0;
}