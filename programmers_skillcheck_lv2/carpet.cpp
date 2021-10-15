//https://programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;


    for(int i = 1 ; i <= yellow ; ++i){
        int total = 0; 
        int width = (i+2);
        total = width*2;


        if( (yellow*100/i) % 100 == 0 ){ // 나누기가 정수인지
            int height = yellow/i;
            total += height*2;
            total += yellow;

            if (total == (brown+yellow) 
                && (width >=(height+2))){ // 문제조건에 부합한지 (w>h)
                answer.push_back(width);
                answer.push_back(height+2);
                break;
            }
        }


    }

    return answer;
}