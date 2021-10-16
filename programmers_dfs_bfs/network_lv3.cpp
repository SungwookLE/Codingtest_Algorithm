#include <string>
#include <vector>
#include <iostream>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/43162
// 풀이: https://programmers.co.kr/learn/courses/30/lessons/43162/solution_groups
// 알거같으면서도 와닿지가 않네.. 이러면  못푼다는건데.

void DFS(int from, int n , vector<int> &visited, vector<vector<int>>&computers){


    for(int i =0 ; i < n ; ++i){
        if (from != i && computers[from][i] == 1 && visited[i] == 0){

            visited[i] = 1;
            DFS(i, n, visited, computers);

        }
    }

}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<int> visited(n,0);

    for(int i =0; i < n ;++i){
        if (visited[i] == 1)
            continue;
        

        // visit node and start DFS
        answer+=1;
        visited[i] = 1;

        DFS(i, n, visited, computers);

    }
    
    return answer;
}

int main(){




    cout << solution(3, {{1,1,0}, {1,1,0}, {0,0,1}});



}