#include <iostream>
#include<string>
using namespace std;

// 문자열 중 짝 지우기 (10/15 --> 22점)

int solution(string s)
{
    int answer = 1;
    
    bool check = true;    
    while(check && !s.empty()){
   
        for(int i =0 ; i < s.length()-1; ++i){

            char cmp = s[i];
            if (cmp == s[i+1]){
                s.erase(i,2);
                break;   
            } 
            else{
                
                if (  i == s.length()-2){
                    check=false;
                    answer =0;
                }    
            }

        }

        std::cout << s << std::endl;
    
    }        
    return answer;
}

int main(){


    std::cout << solution("baabaa");
}