#include <iostream>
#include <vector>

/*
정수론 및 조합론,
#5086 배수와 약수

*/

class solver_5086{

    public:
    
    void feed_and_solve(){

        int a, b;
        std::cin >> a >> b;

        while ( a != 0 || b!= 0){
            if (a>b){

                if ( a%b==0)
                    std::cout << "multiple" << std::endl;
                else
                    std::cout << "neither" << std::endl;

            }
            else if (a<b){

                if ( b%a ==0)
                    std::cout << "factor" <<std::endl;
                else
                    std::cout << "neither" << std::endl;
            }
            else{
                std::cout<<"SAME" << std::endl;
            }

            std::cin >> a >> b;
        }
    }


};

int main(){
    solver_5086 solver;
    solver.feed_and_solve();

    return 0;
}