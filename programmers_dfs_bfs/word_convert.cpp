#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//맞추긴 맞췄는데, 제대로 푼건가.. 

bool check_one(string source, string target){
    int same =0;
    for(int i =0 ; i < source.length(); ++i){
        if (source[i] == target[i])
            same+=1;
    }
    
    if (same == source.length()-1)
        return true;
    else
        return false;
}

void DFS(string now, string target, vector<int> visited, vector<string> words, int ans, vector<int>& answers){

    for(int i =0 ;i < words.size() ; ++i){
        if (visited[i] == 0){
            
            if (check_one(now, words[i])){
                
                visited[i] = 1;
                cout << ans << ": "<< words[i] << endl;
                
                string temp = now;
                now = words[i];
                
                if (now == target){
                    answers.push_back(ans+1);
                    break;
                }    
                
                DFS(now, target, visited, words, ans+1, answers);
                cout <<   endl;
                visited[i] = 0;
                now = temp;
            }
        }
    }
    return;
}



int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    int iter =0;
    int n = words.size();
    
    vector<int> answers;
    vector<int> visited(words.size(), 0);
    string now = begin;
    
    sort(words.begin(), words.end());
    DFS(now,  target, visited, words, answer, answers);
    sort(answers.begin(), answers.end());
    
    if (answers.empty())
        answer =0 ;
    else
        answer = answers[0];
        
    return answer;
}