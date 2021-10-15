//counting sort https://www.cs.miami.edu/home/burt/learning/Csc517.091/workbook/countingsort.html
#include <iostream>
#include <vector> 

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<int> counting(10001,0); //최대 10000이라는 숫자가 입력 가능하므로 0 까지 생각해서 10001
    std::vector<int> list;

    for(int i =0 ; i < N ; ++i){
        int a ;
        std::cin >> a;
        list.push_back(a);   
        counting[a]+=1;
    }
    
    for (int i=1; i < counting.size(); ++i)
        counting[i] += counting[i-1];

    std::vector<int> ans(N+1,0); 
    for (int i=(N-1); i >=0; --i){
        ans[counting[list[i]]] = list[i];
        counting[list[i]] -= 1;
    }

    for (int i = 1 ; i <= N ; ++i)
        std::cout << ans[i] << "\n";

    return 0;
}