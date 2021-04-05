#include <iostream>
#include <vector>

void deep_search(int N, int M, std::vector<int> &arr, std::vector<int> &visited, int limit){
    if (M == limit){
        for (int i = 0 ; i < M ; ++i)
            std::cout << arr[i] << " ";
        std::cout << "\n";
        return;
    }
    for(int i =0 ; i<N; ++i){

        if (visited[i] == 0){
            arr[limit] = (i+1);
            visited[i] = 1;
            deep_search(N, M, arr, visited, limit+1);
            visited[i] = 0;
        }
    }
}

int main(){

    int N, M;
    std::cin >> N >> M;

    std::vector<int> arr(M);
    std::vector<int> visited(N,0);

    deep_search(N,M, arr, visited, 0);
    return 0;
}

// 백트래킹? https://idea-sketch.tistory.com/29
// https://hoony-gunputer.tistory.com/entry/%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9-%EC%88%98%EC%97%B4-%EC%B6%9C%EB%A0%A5N-%EA%B3%BC-M1234
