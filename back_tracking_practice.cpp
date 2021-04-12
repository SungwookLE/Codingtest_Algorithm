#include <iostream>
#include <vector>

void DFS(std::vector<int> &arr, int level, int depth, std::vector<int> &permutation, std::vector<int> visited, std::vector<std::vector<int>>& ans, std::vector<int>& remain){
    if (level == depth){
        std::vector<int> res;
        for(int i =0; i < remain.size(); ++i){
            if (remain[i] == 0)
                res.push_back(arr[i]);
        }
        res.insert(res.begin(), permutation.begin(), permutation.end());    
        ans.push_back(res);
        return;
    }    
    for (int i = 0 ; i < arr.size() ; ++i){
        if(visited[i] == 0){
            permutation[level] = arr[i];
            visited[i] = 1;
            remain[i] = 1;
            DFS(arr, level+1, depth, permutation, visited, ans, remain);
            remain[i]= 0;
        }
    }
    return;
}

int main(){

    std::vector<int> arr = {1,2,3,4,5,6};
    int depth = 3;
    std::vector<int> permutation(depth);
    std::vector<int> visited(arr.size());
    std::vector<int> remain(arr.size());
    std::vector<std::vector<int>> ans;

    DFS(arr, 0, depth, permutation, visited, ans,remain);

    for(auto a : ans){
        for(auto b : a )
            std::cout << b << " ";
        std::cout << "\n";
    }  
    

    return 0;
}