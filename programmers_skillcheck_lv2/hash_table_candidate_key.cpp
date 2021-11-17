#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/42890
// 틀렸어요.. (10/24)

bool check_col(vector<string> &relation, int &answer){
    bool flag = false;
        vector<string> col = relation;
        
        bool same = false;
    
        for(int i = 0 ; i < relation.size(); ++i){
            string comp= relation[i];
            for(int j = i; j < relation.size() ; ++j){
                    if(i!=j){
                        if ( comp == relation[j]){
                            same =true;
                            break;
                        }
                            
                    }
                
            }
            
        }
    
        if (same==false){
            answer+=1;
            flag = true;
            
            for(auto  a : col){
                cout << a << endl;
            }
        }                     
    return flag;
}

void bfs(int iter  , int n,  int t, vector<int> visited,  vector<int> combi,  vector<vector<int>>& combis){
    
    if (iter == n){
        
        combis.push_back(combi);
    }
    else{
        for(int i = 0 ; i < t ; ++i){
           if(visited[i] == 0){
               
                for(int j =0 ; j <=i ; ++j)
                    visited[j]=1;
                    combi[iter] = i;
                    bfs(iter+1, n, t, visited, combi, combis);
                    visited[i]=0;
           }     
        }
    }
    
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<vector<int>> combis;
    
    for(int i= 1; i < relation[0].size() ; ++i){
        vector<int> visited(relation[0].size(),0);
        vector<int> combi(i,-1);
        bfs(0, i, relation[0].size(), visited, combi, combis);
        
        
    }
    
    
    for(int k = 0 ; k < combis.size() ; ++k){
    
        vector<string> temp_col;
        for(int row =0 ; row < relation.size() ; ++row){
            string temp="";
            for(auto it = combis[k].begin() ; it != combis[k].end() ; ++it){
                temp += relation[row][*it];
            }
            temp_col.push_back(temp);
        }
      
        if(check_col(temp_col, answer)){
        
            for(int r = 0 ; r < relation.size() ; ++r)
                
                for(auto it = combis[k].begin() ; it != combis[k].end() ; ++it){
                    relation[r].erase(relation[r].begin()+(*it));
                }
        }
    }
    
   
    
    //check_col(temp_col, answer);
    
            
    return answer;
}