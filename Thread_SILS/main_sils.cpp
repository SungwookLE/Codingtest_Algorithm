#include <iostream>
#include <thread>
#include "logic.h"
#include <vector>

using namespace std;


int main(){

    vector<vector<int>> vel(200,vector<int>(2,1));
    int inputs[2];

    for(auto v: vel){
        copy(v.begin(), v.end(), inputs);

        //https://nowonbun.tistory.com/732
        thread get_sensor_thread(get_sensors, inputs); 
        get_sensor_thread.join();
        
        thread logic_thread_10ms(logic_main_10ms);
        logic_thread_10ms.join();

        cout << g_output.pos_x << " " << g_output.pos_y << " " << endl;
        this_thread::sleep_for(chrono::milliseconds(10));
    }

    // SILS 프로그램에서 for문을 돌려서 bin 파일 로깅된 센서 신호 크기 만큼 for문을 돌고, 로직을 돌린 후 결과값 표출
    // 실제 로직에서는 10ms thread에 넣어서 돌리기

    //g++ main_sils.cpp logic.c -lpthread -fpermissive

    return 0;
}