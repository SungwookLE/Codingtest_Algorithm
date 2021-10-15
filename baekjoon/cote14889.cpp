#include <iostream>
#include <vector>
//https://www.acmicpc.net/problem/14889

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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n ; 
    std::cin >> n;
    std::vector<int> arr(n);
    std::vector<std::vector<int>> score_table(n,arr);
    std::vector<int> members;
    
    for (int i =0; i < n; ++i){
        members.push_back(i);
        for (int j =0 ; j < n ; ++j){
            std::cin >> score_table[i][j];
        }
    }

    int divide = n /2 ;
    std::vector<int> permutation(divide);
    std::vector<int> visited(members.size());
    std::vector<int> remain(members.size());
    std::vector<std::vector<int>> ans;

    DFS(members, 0, divide, permutation, visited, ans, remain);

    int min_diff =100000000;
    int cur_diff;

    for(int i =0 ; i < ans.size() ; ++i){
            members = ans[i];

            // std::cout <<"\n";
            // for(auto member : members)
            //     std::cout << member << " ";
            // std::cout << "\n";

            int sum_start=0, sum_link =0;
            for(int j =0 ; j < divide; ++j){
                for (int k = 0 ; k <divide ; ++k){
                    if (j!=k)
                        sum_start+=score_table[members[j]][members[k]];
                }
            }
            for(int j =divide ; j < n; ++j){
                for (int k = divide ; k < n ; ++k){
                    if (j!=k)
                        sum_link+=score_table[members[j]][members[k]];
                }
            }
            //std::cout << "START: " <<sum_start <<",   LINK:" <<sum_link << "\n";

            cur_diff = abs(sum_start- sum_link);
            if (cur_diff== 0){
                std::cout << 0 << "\n";
                exit(0);
            }
            else{
                if (min_diff > cur_diff)
                    min_diff = cur_diff;
            }
    }

    std::cout << min_diff << "\n";
    return 0;
}