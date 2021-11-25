#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

// 1. back_tracking으로 full search 해서 풀었는데, 시간초과 났음

void back_tracking(int iter, int n, vector<string> nums, vector<int> check, string ret, vector<string>& rets){
    
    if ( n == iter){
        rets.push_back(ret);
        return;
    }
    else{
        for(int i = 0; i < nums.size() ; ++i){
            if (check[i] == 0){
                check[i] = 1;
                ret+=nums[i];
                back_tracking(iter+1, n, nums, check, ret, rets);
                ret.erase(ret.length()-nums[i].length(), ret.length());
                check[i] = 0;
            }
        }
    }
}


string solution(vector<int> numbers) {
    string answer = "";
    
    int iter = 0, n = numbers.size();
    string ret;
    vector<string> rets;
    vector<string> nums;
    vector<int> check(n,0);
    
    for(int i = 0 ; i < numbers.size(); ++i)
        nums.push_back(to_string(numbers[i]));
    
    back_tracking(iter, n, nums, check, ret, rets);
    sort(rets.begin(), rets.end());
    answer = rets.back();
    
    return answer;
}

//위와 같이  풀면 시간 초과다..
// 아래처럼 풀어야 한다. cmp 람다 함수 봐라,, 예술이다.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> nums;
    for(auto num: numbers)
        nums.push_back(to_string(num));
    
    
    sort(nums.begin(), nums.end(), [](auto a, auto b){
       
        if (a+b > b+a)
            return true;
        else
            return false;
     
    });
    
    for(int i =0 ; i < nums.size() ; ++i)
       answer += nums[i];
    
    if (answer[0] == '0')
        answer = "0";
    
    return answer;
}