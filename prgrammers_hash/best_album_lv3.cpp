#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genres_count;
    
    for(int i =0 ; i < genres.size() ; ++i){
        genres_count[genres[i]]+=plays[i];
    }
    
    
    unordered_map<int, vector<int>> feature;
    for(int i =0 ; i < genres.size() ; ++i){
        feature[i] = {genres_count[genres[i]] , plays[i]};
    }
    
    
    vector< pair<int, vector<int> >> v;
    copy(feature.begin(), feature.end(), back_inserter<vector<pair<int, vector<int> >>>(v));
    
    sort(v.begin(), v.end(), [](auto a, auto b){
        if (a.second[0] > b.second[0])
            return true;
        else if ( a.second[0] == b.second[0]){
            if ( a.second[1] > b.second[1])
                return true;
            else if ( a.second[1] == b.second[1]){
                if ( a.first < b.first)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    });
    
    unordered_map<int, int> counter;
    for(auto it = v.begin() ; it != v.end() ; ++it){
        
        counter[it->second[0]]+=1;
        if ( counter[it->second[0]] <= 2)
            answer.push_back(it->first);
        
    }
    
    return answer;
}