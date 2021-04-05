#include <iostream>

int pivonac(int n){
    int ans;

    if (n >= 2)
        ans = pivonac(n-1) + pivonac(n-2);
    else{
        if (n == 1)
            ans = 1;
        else if (n ==0)
            ans =0;
    }
    return ans;
}


int main(){
    int n ;
    std::cin >> n;

    std::cout << pivonac(n) << "\n";

    return 0;
}

/* pseudo code 
pivonac(5) = pivonac(4) + pivonac(3) = pivonac(3) + pivonac(2) + pivonac(2) + 1
= pivonac(2) + 1 + 1 + 0 + 1 + 0 + 1 = 1 + 0 + 1 + 1 + 0 + 1 + 0 + 1 = 5

*/