#include <iostream>
#include <vector>

// 팩토리얼하고 2004번 문제 쉽게 풀이해두었네
// REF: https://ksj14.tistory.com/entry/BackJoon2004-%EC%A1%B0%ED%95%A9-0%EC%9D%98-%EA%B0%9C%EC%88%98
// REF: https://ksj14.tistory.com/entry/BackJoon1676-%ED%8C%A9%ED%86%A0%EB%A6%AC%EC%96%BC-0%EC%9D%98-%EA%B0%9C%EC%88%98

class solver_2004{
    public:
    void insert_num(){
        std::cin >> n >> m;
    }

    void solver(){

        for(long long int i = 2 ; i <= n; i *=2)
            cnt2+= n/i;            
        for(long long int i = 5 ; i <= n; i *=5)
            cnt5+= n/i;
        for(long long int i = 2 ; i <= (n-m); i *=2)
            cnt2-= (n-m)/i;            
        for(long long int i = 5 ; i <= (n-m); i *=5)
            cnt5-= (n-m)/i;            
        for(long long int i = 2 ; i <= m; i *=2 )
            cnt2-= m/i;            
        for(long long int i = 5 ; i <= m; i *=5 )
            cnt5-= m/i;            
            
        std::cout << std::min(cnt2, cnt5) << std::endl;
    }
    private:
    int n, m;
    long long int cnt2=0, cnt5=0;
};

int main(){

    solver_2004 solver;
    solver.insert_num();
    solver.solver();

    return 0;
}