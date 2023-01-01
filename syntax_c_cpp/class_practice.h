#ifndef __FORMAT__
#define __FORMAT__

#include <iostream>
#include <vector>
#include <algorithm>

class format_solver{
    public:

    void insert_array(){
        std::cin >> N;
        int num;
        for (int i = 0 ; i < N ; ++i){
            std::cin >> num;
            array.push_back(num);
        }
    }

    void solver();
    void print_array(){
        for (auto a : array)
            std::cout << a << " ";
        std::cout << std::endl;
    }

    int N;
    std::vector<int> array;

};






#endif