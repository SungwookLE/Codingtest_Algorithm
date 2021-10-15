#include <iostream>

int main(){

    // 1, 2, 3, 4, 5 = 15 = n*(n+1)/2 = 5*6/2 = 15
    int n;
    std::cin >> n;
    int idx = 1;
    int sum= idx;
    int res;
    while(n>sum){
        idx +=1;
        sum=(double)idx*(idx+1)/2;
    }
    idx -= 1;
    
    if ((idx)%2 ==0){
        //even
        res =  sum-n; 
        std::cout << res+1 <<"/" << idx-res+1 ; 
    }
    else{
        //odd
        res = sum-n;
        std::cout << idx-res+1 <<"/" << res+1;
    }
    return 0;
}