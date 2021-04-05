#include <iostream>

int factorial(int n){

    int ans =n;

    if (n>1)
        ans *= factorial(n-1);
    else
        ans =1;

    return ans;
}

int main(){
    int n;
    std::cin >> n;

    std::cout << factorial(n) << "\n";

    return 0;
}

/* pseudo code 
factorial(10) = 10*factorial(9) = 10 * 9 * factorial(8) 
= 10 * 9 * ... * 2 * factorial(1) = 10 * 9 * 8 * ... * 2 * 1
*/