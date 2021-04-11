#include <iostream>
#include <algorithm>
#include <vector>
int main(){
    int n;
    std::cin >> n;

    std::vector<long int> number(n);
    for(int i =0 ; i < n ; ++i)
        std::cin >> number[i];

    std::vector<int> permutation;
    for(int i =0 ; i < 4 ; ++i){
        int op;
        std::cin >> op;

        for(int j = 0 ; j < op ; ++j)
            permutation.push_back(i);
    }

    std::vector<long int> candidates;
    do{
        long int calc_value = number[0];
        for (int i =1 ; i < number.size() ; ++i){
                switch( permutation[i-1] ){
                    case 0: calc_value += number[i]; break;
                    case 1: calc_value -= number[i]; break;
                    case 2: calc_value *= number[i]; break;
                    case 3: calc_value /= number[i]; break;
                }
        }
        candidates.push_back(calc_value);
    }
    while( std::next_permutation(permutation.begin(), permutation.end()) );

    std::sort(candidates.begin(), candidates.end(), [](auto a , auto b){ if (a<b) return true; else return false;});
    std::cout << candidates.back() << "\n" << candidates[0] << "\n";
    return 0;
}