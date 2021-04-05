#include <iostream>
#include <vector>
#include <algorithm>

void deep_search(int N, int M, std::vector<int>&arr, int limit, std::vector<std::vector<int>>& ans){
    if (limit == M){
        ans.push_back(arr);
        return;
    }
    for(int i = 0 ; i < N ; ++i){
            arr[limit] = i+1;
            deep_search(N, M, arr, limit+1, ans);
    }
}

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> arr(M);
    std::vector<std::vector<int>> ans;

    deep_search(N,M, arr, 0, ans);

    std::sort(ans.begin(), ans.end(), [](std::vector<int> a, std::vector<int> b)->bool{
        for (int i =0 ; i < a.size(); ++i){
            if (a[i] != b[i]){
                if (a[i] < b[i])
                    return true;
                else
                    return false;
            }
        }
        return true;
    });

    for(auto row: ans){
        for(auto col : row)
            std::cout << col << " ";
        std::cout << "\n";
    }

    return 0;
}