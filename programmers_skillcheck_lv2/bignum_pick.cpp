#include <string>
#include <vector>
#include <iostream>
//https://life-with-coding.tistory.com/392
// https://programmers.co.kr/learn/courses/30/lessons/42883

using namespace std;

vector<vector<int>> temp;

// Try1: 브루트포스(전부 다 트라이해보기) ==> 시간 초과
void recursion(int n, int k, vector<int> arr, vector<int> visited){
    if (n==k){
        temp.push_back(arr);
    }
    else{
        for(int i =0 ; i < visited.size() ; ++i){


            if (visited[i] == 0){
                arr[n] = i;

                for(int j =0 ; j <= i ; ++j)
                    visited[j] = 1;
                n+=1;
                recursion(n, k, arr, visited);

                n-=1;
                for(int j = arr[n] ; j <= i ; ++j)
                    visited[j] = 0;
           }
        }
    }
}

// Try2: 그리디 알고리즘 : 와 나는 왜 이거 맥스값 찾는것도 잘 이해가 안됫냐 ..
/***********************************/
string greedy(string number, int k){
    string answer="";
    int start =0, maxidx =0;
    char maxnum = 0;

    for(int i =0 ; i < number.size()-k ; ++i){
        maxnum = number[start];
        maxidx = start;

        //k라는 `무빙 윈도우` 안에서 max 값을 찾는 것임!!!! (10/14)
        for(int j = start ; j <= (i+k); j++){ff
            if (maxnum < number[j]){
                maxnum = number[j];
                maxidx = j;
            }
        }
        std::cout << "maxidx: "<< maxidx << std::endl;
        start = maxidx+1;
        answer+= maxnum;
    }
    return answer;
}

string solution(string number, int k) {
    string answer = "";

    answer = greedy(number, k);

    return answer;
}

int main(){

    std::cout << solution("1891",2) << std::endl;
    return 0;
}
