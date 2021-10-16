#include <string>
#include <vector>
#include <iostream>

using namespace std;


void solver(int iter, int n, int ans, vector<int> numbers,int target, int& answer){
    
    if ( iter == n){
        if (ans ==target)
            answer+=1;
    }
    else{
        
        ans += numbers[iter];
        solver(iter+1, n, ans, numbers, target, answer);
        
        ans -= numbers[iter];
        ans -= numbers[iter];
        solver(iter+1, n , ans, numbers, target, answer);
        
    }
    
    
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    
    solver(0, numbers.size(), 0, numbers, target, answer);    
        
    
    return answer;
}