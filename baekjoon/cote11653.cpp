#include <iostream>

int main(){
    int n;
    std::cin >> n;

    int den=2;
    while(den <= n){
        if (n%den==0){
            n = n/den;
            std::cout << den << "\n";
        }
        else
            den+=1;
    }

    return 0;
}