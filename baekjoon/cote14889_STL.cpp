#include <iostream>
#include <vector>
#include <algorithm>
//https://www.acmicpc.net/problem/14889
//백트래킹 : DFS 로 하면되는데 STL 활용해서 해봄 (4/12)

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

    int divide = n/2;
    int min_diff = 1000000000;
    int cur_diff;
    std::vector<int> prev(n,0);

    do{
        auto compare =[divide,members,prev](){    
            int cnt  = 0;
            for (int i = 0; i < divide ; ++i){
                for (int j = 0 ; j <divide ; ++j){
                    if (members[i] == prev[j]){
                        cnt+=1;
                        break;
                    }
                }
            }
            if (cnt == divide)
                return false;
            else
                return true;
        };
        
        if (compare()){
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
            cur_diff = abs(sum_start- sum_link);
            if (cur_diff== 0){
                std::cout << 0 << "\n";
                exit(0);
            }
            else{
                if (min_diff > cur_diff)
                    min_diff = cur_diff;
            }
            prev = members;


        }
    }while( std::next_permutation(members.begin(),members.end()) );
    std::cout << min_diff << "\n";
    return 0;
}