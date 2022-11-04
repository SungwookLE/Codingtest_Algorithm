#include <stdio.h>
#include <stdlib.h>

typedef unsigned char boolean;

boolean* memory_return(boolean* k){
    *k = 127;

    // https://thinkpro.tistory.com/67
    // Heap 메모리를 선언하여 dangling 방지
    boolean* new_pointer_with_address = (boolean*)malloc(sizeof(boolean));  
    
    *new_pointer_with_address = *k;

    // bool g ;
    // bool* new_pointer_without_address= &g;
    // *new_pointer_without_address = *k; //dangling pointer

    return new_pointer_with_address; 
}

int main(int argc, char** argv){

    boolean k;
    boolean *g;
    
    g = memory_return(&k);
    printf("1-1) Call by Address=========================\n");
    printf("%d\n", k);
    printf("%p\n", &k);
    printf("=========================\n");

    printf("1-2) Return by Address with Heap=========================\n");
    printf("%d\n", *g);
    printf("%p\n", g);
    printf("=========================\n");

    free(g);
    g = NULL; // Heap 사용 후엔 메모리 NULL 주소 할당하여 사용하지 말아야할 주소로 명시, 
    printf("%d\n", *g); //Segment 에러
    
    return 0;
}


