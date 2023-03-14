#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class csvHandler{

public:
csvHandler(string _fileName, string _channelName, ios::ios_base::openmode csvOption = ios::trunc){
    fileName = _fileName;
    channelName = _channelName;
    ofs = ofstream(fileName + "_" + channelName + ".csv", csvOption);
}

void writeCsv(unordered_map<string, unordered_map<string, vector<double>>> const _data);

private:
unordered_map<string, vector<double>> reorderData(unordered_map<string, unordered_map<string, vector<double>>>::iterator item);

unordered_map<string, unordered_map<string, vector<double>>> data;
ofstream ofs;
string fileName;
string channelName;
vector<string> keys;

};
