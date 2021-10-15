#include <iostream>
#include <vector>

class solver_3036{
    public:
    solver_3036(){
        std::cin >> N;
        int num;
        for (int i =0 ; i < N ; ++i){
            std::cin >> num;
            nums.push_back(num);
        }
    }

    void solver(){
        for(int i  =1 ; i < N ; ++i){
            std::cout << nums[0] / GCD(nums[0], nums[i]) << "/" << nums[i] / GCD(nums[0], nums[i]) << std::endl; 
        }
    }

    int GCD(int a, int b){
        while(b!=0){
            int r = a%b;
            a = b;
            b = r;
        }
        return a;
    }

    private:
    int N;
    std::vector<int> nums;
};


int main(){
    solver_3036 solver;
    solver.solver();
    
    return 0;
}