#include <iostream>
#include <cmath>

int main(){
    std::string A,B;
    std::cin >> A >> B;
    

    int A_n=0, B_n=0;
    for(int i = 0 ; i  < A.length() ; ++ i){
        A_n += (A[i]-'0')*pow(10,i);
    }
    for(int i = 0 ; i  < B.length() ; ++ i){
        B_n += (B[i]-'0')*pow(10,i);
    }


    if (A_n > B_n)
        std::cout << A_n << "\n";
    else
        std::cout << B_n << "\n";

    return 0;
}