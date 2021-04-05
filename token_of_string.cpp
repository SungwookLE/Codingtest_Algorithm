#include <iostream>
#include <cstring>


int main(){
    
    std::string A, B;
    std::cin >> A >> B;

    int B1 = (B[0])- '0';
    int B2 = (B[1])- '0';
    int B3 = (B[2])- '0';

    int temp1=stoi(A) * B3 ;
    int temp2=stoi(A) * B2 * 10;
    int temp3=stoi(A) * B1 * 100 ;
    
    std::cout << temp1 << std::endl;
    std::cout << temp2/10 << std::endl;
    std::cout << temp3/100 << std::endl;
    std::cout << temp1+temp2+temp3 << std::endl;
    
    return 0;
}
