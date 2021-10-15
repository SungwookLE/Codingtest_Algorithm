#include <vector>
#include <iostream>
#include <string>
// https://programmers.co.kr/learn/courses/30/lessons/42583
// 아 이건 거의다 풀었는데, 여전히 못풀고 있쥬.. 
// Lv2의 문제들은 어려운게 아니고,, 지극히 개념적인것도 구현을 못하고 잇는 상황을 보여주는 것임.



using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    vector<int> on_bridge(bridge_length,0);
    int on_weights=0;
    
    
    while(!truck_weights.empty()){
        answer+=1;    
        for(int i = bridge_length-1 ; i >= 1 ; --i){
            on_bridge[i] = on_bridge[i-1];
        }
        
        on_weights += truck_weights.back();
        
        if (on_weights <= weight){
            on_bridge[0] = truck_weights.back();
            truck_weights.pop_back();
        }
        else{
            on_bridge[0] = 0;
            on_weights-= truck_weights.back();
        }
        
        
            
        if(on_bridge[bridge_length-1]>0){
            on_weights -= on_bridge[bridge_length-1];
        }
        
        
        for(auto a : on_bridge){
            std::cout << a << " ";
        }
        std::cout << std::endl;
        
    }
    answer+=bridge_length;
    
    return answer;
}
int main(){

    std::cout << solution(2, 10, {7,4,5,6}) << std::endl;

}
