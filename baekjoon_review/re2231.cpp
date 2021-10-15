#include <iostream>
#include <vector>
#include <string>
//브루트 포스 (all search)
class prob_2231{
    public:
    prob_2231(){
        std::cin >> N;
    }
    
    void solver(){

        int cons=0;
        while(true){
            cons+=1;
            int temp = cons;
            std::string num = std::to_string(cons);

            for(int i =0 ; i < num.size() ; ++i){
                temp+=int(num[i]-'0');
            }

            if(temp == N){
                std::cout << cons << std::endl;
                break;
            }

            if (cons > N){
                std::cout << 0 << std::endl;
                break;
            }
        }
        return;
    }

    private:
    int N;

};

int main(){
    prob_2231 solver;
    solver.solver();


    return 0;
}