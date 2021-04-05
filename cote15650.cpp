#include <iostream>
#include <vector>
#include <algorithm>

void deep_search(int N, int M, std::vector<int> &visited, std::vector<int> &arr, int limit){

    if (limit == M){
        if (arr.size() == 0){
            return;
        }

        for(int i =0 ; i <arr.size() ; ++i){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        return;
    }

    for(int i =0 ; i < N ; ++i){

        if (visited[i] == 0 ){
            for (int j =0 ; j<=i; ++j)
                visited[j] = 1;

            arr[limit] = i+1;
            deep_search(N, M, visited, arr, limit+1);
            
            for (int j =0 ; j<=i; ++j)
                visited[j] = 0;

        }
    }

}


int main(){

    int N, M;
    std::cin >> N >> M;

    std::vector<int> arr(M);
    std::vector<int> visited(N);

    deep_search(N,M,visited,arr,0);

    return 0;
}