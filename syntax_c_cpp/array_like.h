#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int vel_x;
    int vel_y;

    int pos_x;
    int pos_y;
} Struct_Track;

typedef struct {
    /* 
    트랙 정보가 아래와 같이 1~10번 트랙의 구조체에 담겨 있다고 하면,
    for 문을 이용한 값 매핑이 되지 않는 불편함이 있음. 오직 멤버 호출만을 통해서 데이터를 넣고 읽을 수 있음

    (11/7) 현재, Code-gen 결과 해당 구조체로 코드가 작성되고 있음
    */
    Struct_Track A1;
    Struct_Track A2;
    Struct_Track A3;
    Struct_Track A4;
    Struct_Track A5;
} Struct_Tracks;  

typedef union{
    /* 참고: https://stackoverflow.com/questions/14418595/c-method-for-iterating-through-a-structs-members-like-an-array 
       
       해당 Union 공용체와 같이 Tracks 정보를 Struct로도 정의하여 넣어두고, Array 형태로도 정의하여 넣어두면,
       필요에 따라 for문 순회하여 데이터를 매핑하거나, 필요에 따라 멤버를 호출하여서 데이터를 불러올 수 있으니 편하다.

       (11/7) Code-gen 하여 나온 센서 트랙 구조체를 Union 공용체로 Envelop 하여서 사용하면 편하게 사용할 수 있겠음
    */
    Struct_Tracks Tracks;
    Struct_Track Array_Struct_Tracks[5];
} Union_Struct_Tracks;


/**
 * @brief Union_Struct_Tracks 으로 공용체를 만들고, Array-like 값 대입
 * @param ptr 
 */
void func_struct_iterate(Union_Struct_Tracks* ptr){
    for(int i =0 ; i < sizeof(Union_Struct_Tracks)/sizeof(Struct_Track); ++i){
        ptr->Array_Struct_Tracks[i].vel_x = i*10+1;
        ptr->Array_Struct_Tracks[i].vel_y = i*10+2;

        ptr->Array_Struct_Tracks[i].pos_x = i*10+3;
        ptr->Array_Struct_Tracks[i].pos_y = i*10+4;
    }
    return;
}


