#include <unordered_map>
#include <iostream>
#include "csv_handler.h"

using namespace std;

class dataCarrier
{

public:
    void put_data(string channelName, string signalName, double input)
    {
        data[channelName][signalName].push_back(input);
    }

    int get_channel_size(string channelName)
    {
        return data[channelName].size();
    }

    int get_singal_size(string channelName, string signalName)
    {
        return data[channelName][signalName].size();
    }

    bool is_empty()
    {
        return data.empty();
    }

    unordered_map<string, unordered_map<string, vector<double>>> get_data()
    {
        return data;
    }

    void make_csv(string _fileName, string _channelName, ios::ios_base::openmode csvOption = ios::trunc){
            auto csv = csvHandler(_fileName,_channelName, csvOption);
            csv.writeCsv(data);
    }
    

private:
    unordered_map<string, unordered_map<string, vector<double>>> data;
};