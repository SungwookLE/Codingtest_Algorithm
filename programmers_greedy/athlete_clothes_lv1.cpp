#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int restore=0;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    vector<pair<int, int>> check;
    for(int i = 0 ; i < lost.size() ; ++i){
        for(int j =0 ; j < reserve.size() ; ++j){
            if (lost[i] == reserve[j]){
                check.push_back(make_pair(i,j));
                break;   
            }
        }
    }
    
    for(int idx = check.size()-1 ; idx >=0 ; --idx){
       lost.erase(lost.begin()+check[idx].first);
       reserve.erase(reserve.begin()+check[idx].second);
    }
    
    for(int i = 0 ; i < lost.size() ; ++i){
        for(int j =0 ; j < reserve.size() ; ++j){
            if(lost[i]-1 == reserve[j] || lost[i]+1 == reserve[j]){
                restore +=1;
                reserve.erase(reserve.begin()+j);
                break;
            }   
        }
    }
    
    answer = n-lost.size() + restore ;
    return answer;
}