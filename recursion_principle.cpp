#include <iostream>
void recursion_test(int n){
    if (n==1){
        std::cout << "END " << n << std::endl;
    }
    else{
        recursion_test(n-1);
        std::cout<< "DURING: " << n-1<< std::endl;
    }
}

int main(){
    // 수학으로 따지면 대입(치환) 임.

    recursion_test(5);
    // =recursion(4)*(Print#4)
    // =recursion(3)*(Print#3)*(Print#4)
    // =recursion(2)*(Print#2)*(Print#3)*(Print#4)
    // =recursion(1)*(Print#1)*(Print#2)*(Print#3)*(Print#4)
    // =Print(End#1)*(Print#1)*(Print#2)*(Print#3)*(Print#4)

    return 0;
}