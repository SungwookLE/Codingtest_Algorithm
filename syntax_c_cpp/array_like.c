#include "array_like.h"

int main(int argc, char** argv){
    Union_Struct_Tracks tracks;
    func_struct_iterate(&tracks);

    printf("1. for 순회하여 읽기\n");
    for(int i =0 ; i < sizeof(Union_Struct_Tracks)/sizeof(Struct_Track); ++i){
        printf("tracks.Array_Struct_Tracks[%d].vel_x is %d\n", i, tracks.Array_Struct_Tracks[i].vel_x);
        printf("tracks.Array_Struct_Tracks[%d].vel_y is %d\n", i, tracks.Array_Struct_Tracks[i].vel_y);
        printf("tracks.Array_Struct_Tracks[%d].pos_x is %d\n", i, tracks.Array_Struct_Tracks[i].pos_x);
        printf("tracks.Array_Struct_Tracks[%d].pos_y is %d\n", i, tracks.Array_Struct_Tracks[i].pos_y);
    }

    printf("2. 멤버 호출하여 읽기\n");
    {
        printf("tracks.Tracks.A1.vel_x is %d\n", tracks.Tracks.A1.vel_x);
        printf("tracks.Tracks.A1.vel_y is %d\n", tracks.Tracks.A1.vel_y);
        printf("tracks.Tracks.A1.pos_x is %d\n", tracks.Tracks.A1.pos_x);
        printf("tracks.Tracks.A1.pos_y is %d\n", tracks.Tracks.A1.pos_y);

        printf("tracks.Tracks.A5.vel_x is %d\n", tracks.Tracks.A5.vel_x);
        printf("tracks.Tracks.A5.vel_y is %d\n", tracks.Tracks.A5.vel_y);
        printf("tracks.Tracks.A5.pos_x is %d\n", tracks.Tracks.A5.pos_x);
        printf("tracks.Tracks.A5.pos_y is %d\n", tracks.Tracks.A5.pos_y);
    }
    
    return 0;
}


