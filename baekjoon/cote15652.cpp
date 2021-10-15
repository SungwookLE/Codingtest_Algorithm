#include <iostream>
#include <vector>

void deep_search(int N, int M, std::vector<int>& arr, std::vector<int>& visited, int limit, std::vector<std::vector<int>>& ans){

    if ( limit == M){
        ans.push_back(arr);
        return;
    }

    for(int i =0 ; i < N ; ++i){

        if (visited[i] ==0){

            for (int j=0; j < i ; ++j)
                visited[j] = 1;

            arr[limit] = i+1;
            deep_search(N,M,arr, visited, limit+1, ans);
        
            for (int j=0; j < i ; ++j)
                visited[j] = 0;
        }
    }
}

int main(){

    int N, M;
    std::cin >> N >> M;

    std::vector<int> arr(M);
    std::vector<int> visited(N);
    std::vector<std::vector<int>> ans;

    deep_search(N,M,arr,visited, 0, ans);

    for(auto row: ans){
        for(auto col : row)
            std::cout << col << " ";
        std::cout << "\n";
    }

    return 0;
}