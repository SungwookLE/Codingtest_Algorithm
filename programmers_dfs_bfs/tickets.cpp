#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void DFS(vector<vector<string>>& ans, vector<string> ports, vector<int> visited, vector<vector<string>> tickets){
    
    
    if (ports.size() == tickets.size()+1){
        ans.push_back(ports);
        return;
    }
    
    
    for(int i =0 ; i < tickets.size() ; ++i){
        
        if (tickets[i][0] == ports.back()){
            if (visited[i] == 0){

                
                visited[i]= 1;
            
                ports.push_back(tickets[i][1]);
                DFS(ans, ports, visited, tickets);
                ports.pop_back();
                visited[i] = 0;            
            
            }    
        }
    }
    
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    vector<string> ports = {"ICN"};
    vector<vector<string>> ans;
    vector<int> visited(tickets.size(),0);
    
    DFS(ans, ports, visited, tickets);
    
    sort(ans.begin(), ans.end());
  
    answer = ans[0];
    
    return answer;
}