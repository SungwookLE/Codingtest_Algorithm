#include <iostream>
#include <vector>
#include <algorithm>
//https://www.acmicpc.net/problem/14889
//백트래킹 : DFS 로 하면되는데 문제 이해가 잘 안돼
int main(){
    int n ; 
    std::cin >> n;
    std::vector<std::vector<int>> alls;
    std::vector<int> arr;
    for (int i =0; i < n; ++i){
        for (int j =0 ; j < n ; ++j){
            int num;
            std::cin >> num;
            arr.push_back(num);
        }
        alls.push_back(arr);
    }
    std::vector<int> members;
    for (int i =0; i < n ; ++i)
        members.push_back(i);
    do{

    }while(std::next_permutation(members.begin(),members.end()));
    return 0;
}