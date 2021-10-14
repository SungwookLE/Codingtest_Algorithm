#include <iostream>
#include <vector>
#include <string>


using namespace std;

vector<vector<int>> temp;

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

string solution(string number, int k) {
    string answer = "";

    int pick_k = number.size()-k;

    vector<int> arr(pick_k,0);
    vector<int> visited(number.size(),0);

    recursion(0, pick_k, arr, visited);

    for(auto ele: temp){
        string pick;
        for(auto k : ele)
            pick+=number[k];

        if (answer <= pick)
            answer =pick;
    }


    return answer;
}

int main(){

    std::cout << solution("12345",2)<<std::endl;;



    return 0;
}