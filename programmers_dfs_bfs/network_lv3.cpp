#include <string>
#include <vector>
#include <iostream>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/43162
// 풀이: https://programmers.co.kr/learn/courses/30/lessons/43162/solution_groups
// 알거같으면서도 와닿지가 않네.. 이러면  못푼다는건데.

// DFS는 기본적으로 visited , check를 해가면서 깊이 탐색을 하는 것이다. (10/20)

void DFS(int from, int n, vector<int> &visited, vector<vector<int>> computers){
    
    for(int i = 0 ; i < n ; ++i){
        if ( i != from && visited[i] == 0 && computers[from][i] == 1){
            visited[i] = 1;
            cout <<"from: " <<from << ", to: "<< i << endl;
            DFS(i, n, visited, computers);
        }        
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<int> visited(n,0);
    for(int i =0 ; i < n ; ++i){
        if (visited[i] == 0){
            visited[i] = 1;
            answer +=1;
            DFS(i, n, visited, computers);
            cout << answer << endl;
        }
        
    }
    return answer;
}
int main(){




    cout << solution(3, {{1,1,0}, {1,1,1}, {0,1,1}});



}