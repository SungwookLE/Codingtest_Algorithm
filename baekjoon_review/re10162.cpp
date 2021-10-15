#include <iostream>
#include <vector>

class solver_10162{

    public:
    solver_10162(){
        std::cin >> T;
        button.resize(3,0);
    }

    void solver(){
        int idx =0;
        while(T!=0){
            if ( T >= timer.back()){
                T-=timer.back();
            }
            else{
                while( T < timer.back()){
                    button[idx]=ans;
                    timer.pop_back();
                    ans = 0;
                    idx+=1;
                        
                    if (timer.size() == 0){
                        std::cout << -1 << std::endl;
                        return;
                    }
                }
                T-= timer.back();
            }
            ans+=1;
        }

        button[idx]=ans;
        for(auto a : button)
            std::cout << a << " ";
        std::cout << std::endl;
    }

    private:
    int T;
    int ans =0;
    std::vector<int> button;
    std::vector<int> timer={10,60,300};
};

int main(){
    solver_10162 solver;
    solver.solver();

    return 0;
}