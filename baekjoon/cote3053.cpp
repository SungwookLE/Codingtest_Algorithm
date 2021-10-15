#include <iostream>
#include <cmath>

int main(){

    double r;
    std::cin >> r;

    double pi = M_PI;

    double res_2 = pi*r*r;
    double res_1 = r*r*2.0;

    std::cout<<std::fixed;
    std::cout.precision(7);
    std::cout << res_2 << "\n" << res_1 <<"\n";


    return 0;
}