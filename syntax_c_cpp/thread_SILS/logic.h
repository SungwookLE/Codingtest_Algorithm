typedef struct{
    int pos_x; // SF: 1000
    int pos_y; // SF: 1000
}ST_pos;

typedef struct{
    int vel_x; // SF: 10
    int vel_y; // SF: 10
}ST_vel;

extern ST_vel g_input;
extern ST_pos g_output;

void logic_main_10ms();
void get_sensors(int *arr);
