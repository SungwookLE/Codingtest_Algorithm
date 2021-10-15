#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(),[](auto a, auto b){
        if ( a>b)
            return true;
        else
            return false;
    });
    
    for(int i=0; i<citations.size(); ++i){
        
        int cnt = citations[i] ;
        int num = i+1;
     
        if (num >= cnt){
            answer = cnt;
            break; 
       }
    }
    
    return answer;
}