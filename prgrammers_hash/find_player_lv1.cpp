#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    

    for (int i =0 ; i < completion.size() ; ++i){
            
            
        if (participant[i] != completion[i])
            return participant[i];
    }
    
    // for문 끝까지 찾아지지 않으면, participant의 끝에 선수가 완주자 목록에 없다는 의미다.
    return participant[participant.size()-1];
}

