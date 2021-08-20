#include <iostream>
#include <cstring>

typedef struct{
    int a;
    int b;
    int c;
}st_int;



int main(){
    st_int src_data;
    st_int *des_data = new st_int;

    src_data.a = 4;
    src_data.b=8;
    src_data.c=12;
    
    std::memcpy(des_data, &src_data, sizeof(st_int)); //deep copy


    std::cout << "SRC: " << &src_data << ", DES: "<< &des_data << std::endl;

    std::cout << des_data->a << std::endl;
    std::cout << des_data->b << std::endl;
    std::cout << des_data->c << std::endl;



    return 0;
}