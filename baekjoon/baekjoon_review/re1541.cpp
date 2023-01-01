#include <iostream>
#include <vector>
#include <string>
#include <cmath>

// 그리디 알고리즘은 동적 프로그래밍 처럼 찾는게 아니라 규칙을 찾아내야한다.

class prob_1541{
    public:

    prob_1541(){

        std::cin >> temp;

    }

    void solver(){

        std::vector<int> number;
        for(int i =0 ; i < temp.size() ; ++i){

            if (temp[i]=='+' || temp[i]=='-' ){
                int temp_num =0;
                for(int k =0 ; k < number.size() ; ++k){
                    temp_num += number[k] * std::pow(10, number.size()-(k+1));
                }
                nums.push_back(temp_num);
                number.clear();
                calc.push_back(temp[i]);
            }
            else{
                number.push_back(temp[i]-'0');
            }
        }

        int temp_num =0;
        for(int k =0 ; k < number.size() ; ++k){
                    temp_num += number[k] * std::pow(10, number.size()-(k+1));
        }
        nums.push_back(temp_num);
        bool minus = false;
        ans = nums[0];
        for(int i = 0 ; i < calc.size() ; ++i){

            if ( calc[i] == '-'){
                minus = true;
            }    
            

            if (minus==true){
                ans -= nums[i+1];
            }        
            else{
                ans += nums[i+1];
            }
        }
        std::cout << ans << std::endl;

    }

    private:
    std::string temp;
    std::vector<char> calc;
    std::vector<int> nums;
    int ans =0;
};

int main(){

    prob_1541 solver;
    solver.solver();

    return 0;
}