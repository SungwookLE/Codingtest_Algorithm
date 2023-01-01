#include <iostream>
#include <cstring>

typedef struct{
    int a;
    int b;
    int c;
}st_int;

void heap_struct(st_int *dest){
    st_int *dummy = (st_int*)malloc(sizeof(st_int));

    std::cout << std::endl << dest  << " " << dummy << std::endl;
    dummy->a = 4;
    dummy->b = 8;
    dummy->c = 12;

    std::memcpy(dest, dummy, sizeof(st_int));
    free(dummy);
}

void heap_array(int *dest){
    //dest = (int*)malloc(sizeof(int)*5);
    std::cout <<std::endl << dest  << std::endl;

    for(int i= 0 ; i < 5 ; ++i)
        dest[i] = i+1;
}

int main(){
    st_int *src_data  = (st_int*)malloc(sizeof(st_int));
    int* src = (int*)malloc(sizeof(int)*5);
    
    heap_struct(src_data);

    std::cout <<"MAIN(struct):\n";
    std::cout << src_data << std::endl<< std::endl;
    std::cout << src_data->a << std::endl;
    std::cout << src_data->b << std::endl;
    std::cout << src_data->c << std::endl;

    heap_array(src);
    std::cout <<"MAIN(array):\n";
    std::cout <<  src << std::endl << std::endl;

    for(int i =0 ; i < 5 ; ++i)
        std::cout << src[i] << std::endl;


    return 0;
}