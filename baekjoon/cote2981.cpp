
#include <vector>
#include <iostream>
#include <algorithm>

class solver_2981{
    public:
    void insert_data(){
        std::cin >> N;
        int num;
        for (int i =0 ; i < N ; ++i){
            std::cin >> num;

            if (i ==1)
                max_num = num;
            nums.push_back(num);
        }
        std::sort(nums.begin(), nums.end(), [](int a, int b){
            if ( a < b)
                return true;
            else
                return false;
        });
    }

    void solver(){

        int gcd_value = nums[1]-nums[0];
        for(int i = 2 ; i < N; ++i)
            gcd_value = gcd(gcd_value, nums[i] - nums[i-1]);
        
        for(int i = 2 ; i*i <= gcd_value ; ++i)
            if (gcd_value % i == 0){
                answer.push_back(i);
                answer.push_back(gcd_value/i);
            }

        answer.push_back(gcd_value);
        answer.erase(std::unique(answer.begin(), answer.end()), answer.end());
        std::sort(answer.begin(), answer.end(), [](int a, int b){
            if (a < b)
                return true;
            else
                return false;
        });
        for(auto a : answer)
            std::cout << a << " ";
    }

    int gcd(int a , int b){
        while(b!= 0){
            int r = a%b;
            a = b;
            b = r;
        }
        return a;
    }

    private:
    int N;
    int max_num =0;
    std::vector<int> nums;
    std::vector<int> answer;
};

int main(){
    solver_2981 solver;
    solver.insert_data();
    solver.solver();

    return 0;
}

/*
#2981: 검문
이 문제는 좀 어렵네, 최대공약수를 구하는 문제인데, 주어진 수들의 차이의 최대공약수를 구하는 문제였음


REF: https://cocoon1787.tistory.com/214
*/