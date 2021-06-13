#include <iostream>
#include <vector>

class solver_2609{

    public:
    void insert_number(){
        std::cin >> a >> b;
    }

    void solver(){
        //최대공약수와 최대공배수를 출력하라

        int ans1 = 1;
        for(int i = 2 ; i <= std::max(a,b) ; ++i){
            if ( a % i == 0 && b % i ==0 ){
                if ( ans1 < i )
                    ans1 = i ;
            }
        }
        std::cout << ans1 << std::endl;

        int ans2 = a*b;
        for(int i = a*b ; i >= std::min(a,b) ; --i){
            if ( i % a == 0 && i % b ==0){
                if ( ans2 > i)
                    ans2 = i;
            }
        }
        std::cout << ans2 << std::endl;
    }

    private:
    int a, b;

};

int main(){
    solver_2609 solver;
    solver.insert_number();
    solver.solver();

    return 0;
}