#include <iostream>
#include <vector>

int main(){

    std::string line;
    std::cin >> line;

    std::vector<int> counting(10);
    std::vector<int> list;
    for (int i =0 ; i < line.length() ; ++i){
        int n  = line[i]-'0';
        list.push_back(n);
        counting[n]+=1;
    }

    //integral
    for (int i =1; i < counting.size() ; ++i){
        counting[i] += counting[i-1];
    }

    std::vector<int> sort_ans(line.length()+1);
    for (int i = (list.size() -1) ; i >= 0 ; --i){
        sort_ans[counting[list[i]]]=list[i];
        counting[list[i]]-=1;
    }

    for (int i =(sort_ans.size()-1) ; i >0 ; --i){
        std::cout << sort_ans[i] ;
    }


    return 0;
}