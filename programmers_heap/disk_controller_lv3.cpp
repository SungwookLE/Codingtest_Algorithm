#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end(), [](auto a, auto b){
        if (a[0] < b[0])
            return true;
        else if (a[0] == b[0]){
            if (a[1] < b[1])
                return true;
            else
                return false;
        }
        else
            return false;
    });
    
    auto temp = *jobs.begin();
    int last = temp[0];
    
    vector<int> ans;
    while(!jobs.empty()){
        ans.push_back(temp[1] + last - temp[0]);
        last = temp[1] + last;
        jobs.erase(jobs.begin());
        
        sort(jobs.begin(), jobs.end(), [last](auto a , auto b){
            if (last > a[0] && last > b[0]){
                if (a[1] < b[1])
                    return true;
                else if (a[1] == b[1]){
                    if (a[0] < b[0])
                        return true;
                    else
                        return false;
                }
                else
                    return false;
            } 
            else{
                if (a[0] < b[0])
                    return true;
                else if (a[0] == b[0]){
                    if (a[1] < b[1])
                        return true;
                    else
                        return false;
                }
                else
                    return false;
            }
        });
        temp = *jobs.begin();
    }
    
    int sum = 0;
    for(auto a : ans)
        sum+= a;
    
    return answer = sum / ans.size();
}