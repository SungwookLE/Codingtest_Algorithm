#include <iostream>
#include <cstring>

void resize_arr(int *& arr, int size){
    //포인터의 주소도 바뀌어야 하니까 레퍼런스로 받은 것임
    int* new_arr = new int[size]{};

    std::copy(arr, arr+size, new_arr);
    delete [] arr;
    arr = new_arr;

    std::cout << "heap_handler: " <<std::endl;
    for(int i =0 ; i < size ; ++i)
        std::cout << arr[i] << " " ;
    std::cout << std::endl;
}

int main(){
    int size = 10;
    int* arr = new int[size];
    for(int i = 1; i <= size ; ++i)
        arr[i-1]=i;

    std::cout << "arr 주소: " << arr << std::endl;
    resize_arr(arr,size);
    std::cout << "arr 주소: " << arr << std::endl;

    std::cout << "main: " <<std::endl;
    for(int i =0 ; i < size ; ++i)
        std::cout << arr[i] << " " ;
    
    std::cout << std::endl;



    return 0;
}