#ifdef __cplusplus
extern "C" {
#endif

struct Wrapper;
Wrapper* Wrapper_create();
void Wrapper_put_data(Wrapper* wrapper, const char* channelName, const char* signalName, double input);
void Wrapper_make_csv(Wrapper* wrapper, const char* _fileName, const char* _channelName);

#ifdef __cplusplus
}
#endif