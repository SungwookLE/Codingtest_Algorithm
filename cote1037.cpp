#include <iostream>
#include <vector>
#include <algorithm>

class solver_1037{

    public:

    void insert_data();
    void solver();

    private:
    int ea;
    std::vector<int> nums;


};

int main(){
    solver_1037 solver;
    solver.insert_data();
    solver.solver();


    return 0;
}

void solver_1037::insert_data(){
    
    try{
        std::cin >> ea;

        if (ea ==0)
            throw ea;
    

        int num;
        for(int i =0 ; i < ea ;++i){
            std::cin >> num;
            nums.push_back(num);
        }
    }
    catch(int expn){
        std::cout << "ea is zero" <<std::endl;
        exit(1);
    }
}

void solver_1037::solver(){
    int answer;
    std::sort(nums.begin(), nums.end() , [](int a, int b){
        if (a<b)
            return true;
        else
            return false;
    });
    answer = nums[0] * nums.back();
    std::cout << answer << std::endl;
}
