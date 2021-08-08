#include <iostream>
#include <vector>
#include <algorithm>


int main(){

    std::vector<int> arr = {90,2,43,1,2,3,1,2,1,4,5,1,7};
    
    int target = 6;

    std::sort(arr.begin(), arr.end(), [](int a , int b){
        if ( a < b)
            return true;
        else
            return false;
    });

    std::cout <<"arr: \n";
    for (auto a: arr)
        std::cout << a << " ";
    std::cout << std::endl;


    int start = 0 ;
    int end = arr.size()-1;
    int mid ;
    while ( start <= end){
        mid = (start+end)/2;

        if (arr[mid] == target)
            break;
        
        else if ( arr[mid] > target)
            end = mid-1;
        else if ( arr[mid] < target)
            start = mid+1;

        std::cout << "idx: " << mid << std::endl;
    }

    if ( arr[mid]== target)
        std::cout << std::endl << "mid: " << mid << " ,arr[mid]: " << arr[mid] << std::endl;
    else
        std::cout << std::endl << "NONE" <<std::endl;
    
    std::cout << "TRUE/FALSE: \n";
    std::cout << std::binary_search(arr.begin(), arr.end(), 43) <<std::endl;

    std::cout << "ITERATOR: \n";
    std::cout << *arr.begin() << std::endl;

    std::cout << "lower?6: \n";
    auto k = *std::lower_bound(arr.begin(), arr.end(), 7);
    std::cout << k << std::endl;
    std::cout << "upper?6: \n";
    auto g = *std::upper_bound(arr.begin(), arr.end(), 7);
    std::cout << g << std::endl;

    return 0;


}