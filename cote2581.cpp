#include <iostream>

int main(){

    int under, upper;
    std::cin >> under >> upper;

    int ans_sum=0, min_ans=upper;
    for(int i = under; i<=upper ; ++i){
        int num = i-1;
        int count = 0;
        while ( num > 1){
            if ( i % num == 0){
                count +=1;
                break;
            }
            num-=1;
        }
        if ((count==0) && (i!=1)){
            ans_sum+=i;
            if (min_ans >= i)
                min_ans = i;
        }
    }
    if (ans_sum ==0)
        std::cout << -1 ;
    else
        std::cout << ans_sum <<"\n" << min_ans;

    return 0;
}