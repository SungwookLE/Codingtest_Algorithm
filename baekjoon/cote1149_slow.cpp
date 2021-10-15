#include <iostream>
#include <vector>
#include <algorithm>

// #1149 RGB 거리 // time ,,, limit -->fail
void DFS(int level, int N, std::vector<bool>& visited, std::vector<std::vector<int>> list, int& candidate, int& min_candidate){
    if(level==N){
        if (min_candidate > candidate)
            min_candidate = candidate;
        return;
    }
    for(int i=0 ; i<3; ++i){
        if (visited[i] == false){
            visited = {false, false, false}; //reset visited vector
            visited[i] = true;
            candidate += list[level][i];
            DFS(level+1, N, visited, list, candidate, min_candidate);
            candidate -= list[level][i];
            visited[i] = false;
        }
    }
}

int main(){
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> list(N);

    for (int i = 0 ; i < N; ++i){
        int R, G, B;
        std::cin >> R >> G >> B;
        list[i]={R,G,B};
    }
    std::vector<bool> visited(3, false);

    int candidate =0, min_candidate =1000000; 
    DFS(0, N, visited, list, candidate, min_candidate);

    std::cout << min_candidate << std::endl;

    return 0 ;
}