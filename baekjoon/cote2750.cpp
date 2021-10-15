#include <iostream>
#include <vector>

int main(){

    int N;
    std::cin >> N;
    std::vector<int> list;

    for(int i =0 ; i < N ; ++i){
        int a;
        std::cin >> a;
        list.push_back(a);
    }

    for(int i =0 ; i < list.size() ; ++i){
        for (int j =i; j < list.size() ; ++j){
            if( i != j){
                if (list[i] > list[j]){
                    int temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
    }

    for( auto a : list)
        std::cout <<a <<"\n";

    return 0;
}