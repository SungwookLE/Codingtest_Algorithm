#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days(progresses.size(),0);    
 
    for(int i =0 ; i < progresses.size(); ++i){
        days[i] = ceil( (double)(100-progresses[i])/speeds[i] );
    }

    int last =0;
    while ( !days.empty()){

        for(int i=0 ; i < days.size() ; ++i)
            days[i] -= 1;


        for(int i = days.size()-1 ; i >= 0 ; --i){

            if(days[i]<=0){
                bool check = true;
                int count =0;
                for(int j =0 ; j <= i ; ++j){
                    if (days[j] > 0){
                        check = false;
                        break;
                    }
                    else{
                        count +=1;
                    }
                }

                if(check){
                   
                    days.erase(days.begin(), days.begin()+count);
                    
                    answer.push_back(count);

                    if (days.empty())
                        break;

                }

            }

        }



    }

    
    return answer;
}

int main(){


    vector<int> ans = solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1});
    for(auto a : ans){
        std::cout << a << " ";
    }

    return 0;
}