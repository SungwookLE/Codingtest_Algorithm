#include "logic.h"
#include <threads.h>
#include <time.h>
#include <stdio.h>

ST_vel g_input;
ST_pos g_output;

void logic_main_10ms(){
    
        g_output.pos_x = (g_input.vel_x * 1  + g_output.pos_x ) ;
        g_output.pos_y = (g_input.vel_y * 1  + g_output.pos_y ) ;

    return;
}

void get_sensors(int *arr){

    //https://karupro.tistory.com/19
    thrd_sleep(&(struct timespec){.tv_nsec=50000000}, NULL); // sleep 50 msec 50,000,000

    g_input.vel_x = arr[0];
    g_input.vel_y = arr[1];

    return;
}
