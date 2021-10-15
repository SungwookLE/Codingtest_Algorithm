// https://programmers.co.kr/learn/courses/30/lessons/17686

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class File{
    public:
    string h;
    int n;
    string t;
    File(string _h, int _n, string _t): h(_h), n(_n), t(_t) {} 
};

vector<File> file;

bool cmp(const File a, const File b){
    if ( a.h.compare(b.h) == 0 ) return a.n < b.n;
    else return a.h < b.h;
}

string strupr(string str){
    for(int i =0 ; i < str.size(); i++)
        if ('a' <= str[i] && str[i] <= 'z')
            str[i] = str[i] - 'a' + 'A';
        
    return str;
}

vector<string> solution(vector<string> files){
    vector<string> answer;
    for(int i =0; i < files.size(); ++i){
        int s = 0;
        for(int j =0 ; j < files[i].size(); ++j){
            if ('0' <= files[i][j] && files[i][j] <= '9'){
                s =j;
                break;
            }
        }
        
        file.push_back(File(strupr(files[i].substr(0,s)), stoi(files[i].substr(s)), files[i]));
        stable_sort(file.begin(), file.end(), cmp);
        for(int i =0 ; i < file.size(); ++i){
            answer.push_back(file[i].t);
        }

    }

    return answer;
}

int main(){

    vector<string> files = {"foo123.zip", "as123.z", "ppp999a.zo"};
    vector<string> ans = solution(files);

    for(auto a : ans){
        std::cout << a << std::endl;
    }
}
