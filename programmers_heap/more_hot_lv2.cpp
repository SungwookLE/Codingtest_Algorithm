#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> p_queue;
    for(int i = 0 ; i < scoville.size() ; ++i){
        p_queue.push(scoville[i]);
    }
 
    bool flag = true;
    int new_scoville;
    int fir,sec;
    
    while (flag){
        answer+=1;
        
        if (p_queue.size() <= 1)
            return -1;
        fir = p_queue.top(); p_queue.pop();
        sec = p_queue.top(); p_queue.pop();
        new_scoville =fir + sec*2;
        p_queue.push(new_scoville);
        
        if (p_queue.top() >=K)
            flag = false;
    }

    return answer;
}