#include <string>
#include <vector>
#include <iostream>


using namespace std;

// 이거 lv1인데도 마지막에 최대값 조회하는게 생각이 안나서 헤맷다... 제발.. ㅠㅠ 왜그려

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    
    vector<int> one = {1,2,3,4,5};
    vector<int> two = {2,1,2,3,2,4,2,5};
    vector<int> three = {3,3,1,1,2,2,4,4,5,5};
    
    
    while ( one.size() < answers.size())
        one.insert(one.begin(), one.begin(), one.end());
    while ( two.size() < answers.size())
        two.insert(two.begin(), two.begin(), two.end());
    while ( three.size() < answers.size())
        three.insert(three.begin(), three.begin(), three.end());
    
    vector<int> pts(3,0);
 
    for(int i = 0 ; i < answers.size() ; ++i){
        if (answers[i] == one[i])
            pts[0] +=1;     
        
        if (answers[i] == two[i])
            pts[1] +=1;     
       
        if (answers[i] == three[i])
            pts[2] +=1;     

    }

    int max = 0;
    for(int i =0 ; i < pts.size(); ++i){
       if (max < pts[i])
           max = pts[i];
    }
    
    for(int i =0; i < pts.size(); ++i)
        if (max == pts[i])
            answer.push_back(i+1);
    
    return answer;
}