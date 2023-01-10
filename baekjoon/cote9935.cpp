/**
 * @date 2023-01-08
 * @brief 1차 시도: DFS로 시도 -> 이렇게 하니 시간초과나더라
 * @brief 2차 시도: 스택 방식이라고 하여, 임시 배열을 하나 만들고 문자열 검사를 뒤쪽에서만 하게 하니까, 
 * 시간초과 해소됨. solve_naive에서는 string::find() 함수를 씀으로써 배열의 길이만큼 계속해서 조회를 하게 되어 시간초과가 되었다.
 */

#include <iostream>
#include <string>

using namespace std;

class solver9935{
    public:
    solver9935(string _chars, string _bomb): chars(_chars), bomb(_bomb) {leng = bomb.length();}
    void solve_naive(){
        //DFS를 한다? 그래서 chars가 비워지면 FRULA를 출력하자!
        //이렇게 하니까 시간초과가 나더라
        string::size_type n;
        n = chars.rfind(bomb);

        if (n == string::npos){
            if (chars.empty())
                answer= "FRULA";
            else
                answer= chars;

            return;
        }
        else{
            chars = chars.substr(0,n) + chars.substr(n+bomb.length()) ;
            solve_naive();
        }
    }

    void solve(){
        string temp;
        for(int i = 0 ; i < chars.length(); ++i){
            temp+= chars[i];

            if (temp.length() >= leng){
                bool flag = true;
                for(int j =0; j < leng ; ++j){
                    if( temp[temp.length()-leng+j] != bomb[j]){
                        flag = false;
                        break;
                    }
                }

                if (flag)
                temp.erase(temp.end()-leng, temp.end()); //substr 보다 erase가 빠르네 주소 접근이라 그런가봄
            }
        }
        if (temp.empty()){
            answer = "FRULA";
        }
        else
            answer = temp;
    }

    string answer;
    private:
    string chars;
    string bomb;
    int leng;
};

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string chars, bomb;
    cin >> chars >> bomb;

    solver9935 solver(chars, bomb);
    solver.solve();

    cout << solver.answer << endl;

    return 0;
}