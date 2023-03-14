#include <iostream>
#include "csv_handler.h"

void csvHandler::writeCsv(unordered_map<string, unordered_map<string, vector<double>>> const _data){
    data = _data;
    unordered_map<string, vector<double>> orderedData;
    
    auto item = data.find(channelName);
    if (item != data.end()){
        orderedData = reorderData(item);    

        for(auto s : orderedData)
           ofs << s.first << ", " ;
        ofs << endl; 

        for (int i = 0 ; i < orderedData.begin()->second.size(); ++i){
            for(auto const& pair : orderedData)
                ofs << pair.second[i] << ", ";
            ofs << endl;
        }
        ofs.close();
    }
    else
        cout << channelName << " is not exsited\n";
}

unordered_map<string, vector<double>> csvHandler::reorderData(unordered_map<string, unordered_map<string, vector<double>>>::iterator item){
        for(auto const& pair: item->second)
        if (pair.first != "Time")
           keys.push_back(pair.first);

    sort(keys.begin(), keys.end());
    keys.insert(keys.end(), "Time");

    unordered_map<string, vector<double>> orderedData;
    for(auto i = keys.rbegin(); i !=keys.rend(); ++i){
        orderedData.insert(item->second.find(*i), item->second.end());
    }

    cout << "signalName: ";
    for(auto k : keys)
        cout << k << " ";
    cout << endl;

    return orderedData;
}



// int main(){

//     unordered_map<string, unordered_map<string, vector<double>>> data;
//     data["ECAN"]["Time"]      = {10,20,30,40,50};
//     data["ECAN"]["VEH_INFO1"] = {1,2,3,4,5};
//     data["ECAN"]["VEH_INFO2"] = {6,7,8,9,10};
//     data["ECAN"]["VEH_INFO3"] = {11,12,13,14,15};

//     auto csv = csvHandler("pcap","ECAN", ios::trunc);
//     csv.writeCsv(data);

//     return 0;
// }