#include <iostream>
#include <vector>

class solver_1676{
    public:
    void solver(int n_in){
        // 처음에 Recursive 로 구성햇는데, 이건 메모리를 많이 잡아먹기 떄문에 메모리 초과 에러가 났다. 따라서 그냥 for문으로 잡고 돌려버림
        // REF: https://ksj14.tistory.com/entry/BackJoon1676-%ED%8C%A9%ED%86%A0%EB%A6%AC%EC%96%BC-0%EC%9D%98-%EA%B0%9C%EC%88%98
        // 첫번쨰 트라이는 factoiral을 직접 단계마다 계산하고, 끝에 0의 개수를 세서 숫자를 줄여주는 방식으로 오버플로우를 피해보고자 햇는데,
        // 그런경우 while문을 타다보니까 시간초과 에러가 나더라!
        for(int i = 1 ; i <=n_in ; ++i){
            int temp = i;
            while ( temp % 2 == 0){
                cnt2 += 1;
                temp /= 2;
            }
            while ( temp % 5 == 0){
                cnt5 += 1;
                temp /= 5;
            }
        }
    }

    void print_ans(){
        std::cout << std::min(cnt2, cnt5) << std::endl;
    }

    private:
    int cnt2=0, cnt5=0;
    
};

int main(){
    solver_1676 solver;
    int N;
    std::cin >> N;
    solver.solver(N);
    solver.print_ans();
    return 0;
}