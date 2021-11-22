#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    vector<int> v;
    for(int i = 0 ; i < operations.size(); ++i){
        string temp = operations[i];
        stringstream ss(temp);
        string key, val;
        ss >> key >> val;
        
        if (key == "I"){
            v.push_back(stoi(val));
            sort(v.begin(), v.end());
        }
        else{
            if (!v.empty()){
                if (val == "1")
                    v.pop_back();
                else if (val == "-1")
                    v.erase(v.begin());
            }
        }
    }
    
    if (!v.empty())
        answer = {v.back(), *v.begin()};
    else
        answer = {0,0};
    return answer;
}