#include <iostream>
#include <vector>

int main(){


    int n;
    std::cin >> n;

    while(n!=0){
        if (n < 1)
            return 0;

        int upper = 2*n;
        std::vector<bool> prime_arr(upper-2+1, true);

        for(int i=2 ; i*i <= upper ; ++i){
            if (prime_arr[i-2]==true){
                for(int j = i*i ; j <=upper ; j+=i)
                    prime_arr[j-2] = false;
            }
        }

        int idx =2 ;
        int count=0;
        for ( bool data: prime_arr){
            if (data == true){
                if ((idx <= upper) &&(idx >n)){
                    count +=1;
                }
            }
            idx+=1;
        }
        std::cout << count <<"\n";
        std::cin >> n;
    }
    return 0;
}