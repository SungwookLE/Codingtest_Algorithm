#include <iostream>

int main(){

    int n;
    std::cin >> n;

    int ans=0;
    for(int i =0 ; i < n ; ++i){
        int num;
        std::cin >> num;

        int den = num-1;
        int count =0;

        while ( den > 1){
            if (num%den==0)
                count+=1;
            den-=1;
        }

        if ( (num!=1) && (count==0))
            ans+=1;
    }
    std::cout << ans;
    return 0;
}