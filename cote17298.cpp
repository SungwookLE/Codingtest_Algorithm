#include <iostream>
#include <vector>
#include <algorithm>

class solver_17298{
    public:
    void insert(){
        std::cin >> N;
        arr.resize(N,0);
        for(int i = 0 ; i < N ; ++i)
            std::cin >> arr[i];
    }

    void solver_timeout(){
        // 내가 풀어본 방식인데 이렇게 풀면 , 타임아웃이 나거든 O(N^2) 의 복잡도가 생겨서,
        // 따라서 아래와 같이 스택을 이용해서 풀어야 하는데,
        for(int k = 0; k < N ; ++k){
            int s[N+1] = {0,};
            int top=k+1;

            s[top] = arr[k];

            for(int i = k+1 ; i < N ; ++i){
                int cur = arr[i];

                if ( s[top]  < cur ){
                    s[++top] = cur;
                    std::cout << cur << " ";
                    break;
                }    
            }

            if (s[top] ==  arr[k])
                std::cout << -1 << " ";

        }
    }

    void solver(){
        // REF: https://sihyungyou.github.io/baekjoon-17298/
        // REF 를 봐도 잘이해가 되진 않네,,

        int s[N+1] = {0,};
        int top =0;

        std::vector<int> ans(N,-1);
        for(int i = 0 ; i < N ; ++i){

            while( top > 0 && arr[s[top]]  < arr[i] ){
                ans[s[top]] = arr[i];
                top--;
            }

            s[++top]=i;
        }

        for (auto a : ans)
            std::cout << a << " " ;
    }

    private:
    int N;
    std::vector<int> arr;

};

int main(){

    solver_17298 solver;
    solver.insert();
    solver.solver();

    return 0;
}