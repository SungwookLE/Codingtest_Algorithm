#include <iostream>
#include <vector>

class solver_1676{

    public:
    void insert_num(){
        std::cin >> N;
    }

    void factorial(){
        for(int i = 1 ; i <= N ; ++i)
            ans *= i;
        std::string ans_str;
        ans_str = std::to_string(ans);

        bool stop_flag = false;
        int print_ans = 0;
        for(int i=ans_str.size()-1 ; i >= 0 ; --i){
            if (ans_str[i] != '0'){
                stop_flag = true;
                break;
            }
            else{
                print_ans+=1;
            }
        }
        std::cout << print_ans << std::endl;
    }

    private:
    int N;
    int ans=1;
};


int main(){

    solver_1676 solver;
    solver.insert_num();
    solver.factorial();


    return 0;
}