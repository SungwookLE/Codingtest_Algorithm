// GCD(최대공약수), LCM(최대공배수)

#include <iostream>
#include <vector>

int gcd(int a, int b){
    // RULE: GCD(a,b) = GCD(b,r) 이고 r은 (a%b)이고 r이 0이되면 첫번째 인자가 공약수임
    while (b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    int gcd_v = gcd(a,b);
    return a*b / gcd_v;
}

int main(){
    int a , b;
    std::cin >> a >> b;

    int gcd_value = gcd(a,b);
    std::cout << "GCD: " << gcd_value << std::endl;

    int lcm_value = lcm(a,b);
    std::cout << "LCM: " << lcm_value << std::endl;
}