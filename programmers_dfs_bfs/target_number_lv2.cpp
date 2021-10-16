#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 분할 탐색이라고 해서 풀었었는데, 이것도 BFS의 일종이겠구나.


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