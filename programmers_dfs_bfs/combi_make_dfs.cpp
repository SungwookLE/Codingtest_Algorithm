#include <iostream>
#include <vector>
using namespace std;

void dfs(int iter, int n , vector<int> pick, vector<int> arr, vector<int>visited, vector<vector<int>>& combi){
    if(iter == n){
        combi.push_back(pick);
        return;
    }
    else{
        for(int i =0 ;i < arr.size() ; ++i){

            if (visited[i] == 0){
                visited[i] = 1;
                pick[iter] = i;
                dfs(iter+1, n , pick, arr, visited, combi);
                visited[i] = 0;
            }
        }
    }
}

int main(){

    vector<int> arr = {1,2,3};

    vector<int> pick(arr.size(), 0);
    vector<int> visited(arr.size(),0);
    vector<vector<int>> combi;

    dfs(0, arr.size(),pick, arr, visited, combi );

    for(auto a : combi){
        for(auto d : a)
            cout << d << " ";
        cout << endl;
    }

    return 0;
}