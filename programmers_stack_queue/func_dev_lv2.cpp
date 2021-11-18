#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<double> v(progresses.size(), 100);
    for(int i = 0 ; i < progresses.size() ; ++i)
        v[i] = (v[i] - double(progresses[i]))/double(speeds[i]);
    
    while(!v.empty()){
        for(int i = 0 ; i < v.size() ; ++i){
            v[i] -= 1;
            //cout << v[i] << " ";
        }
        //cout << endl;
        
        int count =0 ;
        while(v[0] <= 0 && !v.empty()){
            count +=1;
            v.erase(v.begin());
        }
        
        if (count > 0){
            answer.push_back(count);
        }
    }
    
    return answer;
}