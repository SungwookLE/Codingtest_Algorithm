#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<int> count;
    for(int i =0 ; i < prices.size() ; ++i){
        int cmp = prices[i];
        int tick = 0;
        for(int j = i+1 ; j <prices.size(); ++j){
            tick +=1;
            if ( cmp > prices[j])
                break;
        }
        count.push_back(tick);
    }
    
    return answer=count;
}