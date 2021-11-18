#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector<pair<int, int>> train, ans;
    for(int i =0 ; i < priorities.size() ; ++i){
        train.push_back(make_pair(i, priorities[i]));
    }
    
    while (!train.empty()){
        auto temp = *train.begin();
        train.erase(train.begin());

        bool checker = true;
        for(int i = 0 ; i < train.size() ; ++i){
            if (temp.second < train[i].second){
                train.push_back(temp);
                checker = false;
                break;
            }
        }
        if (checker){
            ans.push_back(make_pair(temp.first, temp.second));
        }
    }
    
    for(int i =0 ; i < ans.size() ; ++i){
        if ( ans[i].first == location){
            answer = i+1;
        }
    }
    
    return answer;
}