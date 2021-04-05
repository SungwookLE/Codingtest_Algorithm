#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int N ;
    std::cin >> N;
    std::vector<int> list;

    for(int i =0 ; i < N ; ++i){
        int a;
        std::cin >> a;
        list.push_back(a);
    }

    std::sort(list.begin(), list.end(), [](int a, int b){
        if (a>b)
            return false;
        else
            return true;
    }); // b가 더 클 때 true 이므로, 오름차순 

    for ( auto a : list)
        std::cout << a<< "\n";


    return 0;
}