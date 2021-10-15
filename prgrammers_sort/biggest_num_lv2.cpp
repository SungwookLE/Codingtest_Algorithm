#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// 이게 아이디어구나..
// 와 이... compare 함수 천재네..
bool compare(const string &a, const string &b)
{
    if (b + a < a + b)
        return true;
    return false;
}


string solution(vector<int> numbers) {
    string answer = "";
 
    sort(numbers.begin(), numbers.end(), [](auto a, auto b){
        string s_a = to_string(a);
        string s_b = to_string(b);
        
        if(compare(s_a, s_b))
            return true;
        else
            return false;
        
    });
    
    for(int i =0 ; i < numbers.size(); ++i){
        answer+= to_string(numbers[i]);
    }
    
    
    
     if (answer[0] == '0')
        answer = "0";

    
    return answer;
}