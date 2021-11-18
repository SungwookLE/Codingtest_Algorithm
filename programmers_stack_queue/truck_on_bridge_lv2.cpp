#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    vector<int> on_bridge(bridge_length,0);
    int on_weights = 0;
    
    while(!truck_weights.empty()){
        int temp = *truck_weights.begin();
        on_weights -= on_bridge.back();
        on_weights += temp;

        if (on_weights <= weight){
            truck_weights.erase(truck_weights.begin());
            answer +=1;
            for(int i = on_bridge.size()-1 ; i > 0; --i)
                on_bridge[i] = on_bridge[i-1];
            on_bridge[0] = temp;
        }
        else{
            on_weights -= temp;
            answer +=1;
            for(int i = on_bridge.size()-1 ; i > 0; --i)
                on_bridge[i] = on_bridge[i-1];
            on_bridge[0] = 0;
        }
    }
    
    return answer+bridge_length;
}