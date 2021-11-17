#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> cl;
    
    for(int i = 0 ; i < clothes.size() ; ++i){
        cl[clothes[i][1]] += 1;
    }
    
    for(auto it = cl.begin(); it != cl.end() ; ++it)
        answer *=(it->second+1) ;
   
    // 아에 안입는 경우를 더해서 다 곱한다음에, 아무것도 안입는 경우의 수는 없으니까 1을 뺸다.. 머리 좋네.. 잉
    return answer-1;
}