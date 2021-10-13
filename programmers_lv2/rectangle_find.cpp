// https://programmers.co.kr/learn/courses/30/lessons/62048?language=cpp
// https://mingmi-programming.tistory.com/130

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int getGcd(int s, int b){
    int tmp =0;
    
    while (s!=0){
        tmp = b%s;
        b = s;
        s = tmp;
    }
    return b;
}

long long solution(int w,int h) {
    long long answer =(long long)w* h;
    int min_num = std::min(w,h);
    int max_num = std::max(w,h);
    int gcd = getGcd(min_num, max_num);
    
    return answer - (min_num+max_num - gcd);
}

int main(){

    std::cout<< solution(8,12) <<std::endl;

}