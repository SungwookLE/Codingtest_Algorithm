#include <iostream>
#include <vector>

class solver_5585{

    public:
    solver_5585(){
        std::cin >> value;
        diff = total-value;
    }

    void solver(){
        int ans =0;
        while ( diff != 0 ){

            if (change.back() <= diff){
                diff -= change.back();
            }
            else{
                if (change.empty()){
                    return;
                }

                while( diff < change.back())
                    change.pop_back();

                diff -= change.back();
            }

            ans +=1;
        }

        std::cout << ans << std::endl;

        return;
    }




    private:
    int diff;
    int value;
    int total = 1000;
    std::vector<int> change= {1, 5, 10, 50, 100, 500};


};

int main(){

    solver_5585 solver;
    solver.solver();

    return 0;
}