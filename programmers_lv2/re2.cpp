#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 전화번호부 접두어 찾기 (10/15 --> 35점)


bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(int i = 0 ; i < phone_book.size()-1 ; ++i){
        
        for(int j = i+1 ; j<phone_book.size();++j){

            if ( phone_book[i].length() <= phone_book[j].length()){

                string cpy = phone_book[j];
                string cmp = cpy.substr(0, phone_book[i].size());

                if (cmp.compare(phone_book[i])==0){
                    answer = false;
                    break;
                }            
            }
            
        }

        if (!answer)
            break;
    }
    
    return answer;
}

int main(){

    std::cout << solution({"119", "97674223", "1195524421"})<<std::endl;


    return 0;
}