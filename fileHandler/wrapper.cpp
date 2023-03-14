#include "data_carrier.h"
#include "wrapper.h"

struct Wrapper
{
    dataCarrier* obj;
};

Wrapper* Wrapper_create(){
    Wrapper* wrapper = new Wrapper();
    wrapper->obj = new dataCarrier();

    return wrapper;
}

void Wrapper_put_data(Wrapper* wrapper, const char* channelName, const char* signalName, double input){

    return  wrapper->obj->put_data(string(channelName), string(signalName), input);
}
void Wrapper_make_csv(Wrapper* wrapper, const char* _fileName, const char* _channelName){
    return wrapper->obj->make_csv(string(_fileName),string(_channelName));
}

