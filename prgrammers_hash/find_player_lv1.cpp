#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    // 정렬을 하면 알파벳 순으로 정렬이 되는데, 
    

    for (int i =0 ; i < completion.size() ; ++i){
            
        // 정렬 순서가 다르다는 것은, 달라지는 순서에 participant가 없다는 뜻이고,    
        if (participant[i] != completion[i])
            return participant[i];
    }
    
    // for문 끝까지 찾아지지 않으면, participant의 끝에 선수가 완주자 목록에 없다는 의미다.
    return participant[participant.size()-1];
}

