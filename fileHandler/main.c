#include "wrapper.h"
#include <stdio.h>

int main(){
    
    Wrapper* wrapper = Wrapper_create();
    Wrapper_put_data(wrapper, "ECAN", "VEH1", 1);
    Wrapper_put_data(wrapper, "ECAN", "VEH2", 1);
    Wrapper_put_data(wrapper, "ECAN", "VEH3", 1);
    Wrapper_put_data(wrapper, "ECAN", "Time", 10);
    
    Wrapper_put_data(wrapper, "ECAN", "Time", 20);
    Wrapper_put_data(wrapper, "ECAN", "VEH1", 2);
    Wrapper_put_data(wrapper, "ECAN", "VEH2", 3);
    Wrapper_put_data(wrapper, "ECAN", "VEH3", 4);

    Wrapper_put_data(wrapper, "ECAN", "Time", 30);
    Wrapper_put_data(wrapper, "ECAN", "VEH1", 4);
    Wrapper_put_data(wrapper, "ECAN", "VEH2", 6);
    Wrapper_put_data(wrapper, "ECAN", "VEH3", 8);

    Wrapper_put_data(wrapper, "ECAN", "Time", 40);
    Wrapper_put_data(wrapper, "ECAN", "VEH1", 6);
    Wrapper_put_data(wrapper, "ECAN", "VEH2", 9);
    Wrapper_put_data(wrapper, "ECAN", "VEH3", 12);


    Wrapper_make_csv(wrapper, "pcap", "ECAN");
}