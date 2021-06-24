#include <iostream>
#include <vector>
// REF: https://bunnnybin.tistory.com/entry/%EB%B0%B1%EC%A4%80-9012-%EA%B4%84%ED%98%B8-C
// 나는 top인덱스를 이용해서 stack 을 내방식대로 만들어서 사용함.
/*
문제>> 
괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다. 
여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다. 
출력>>
출력은 표준 출력을 사용한다. 만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면 “YES”, 아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다. 
*/
class solver_9012{
    public:
    void insert_number(){
        std::cin >> T;
        std::string temp;
        for(int i =0 ; i < T ; ++i){
            std::cin >> temp;
            arr.push_back(temp);
        }
    }
    void solver(){
        std::string temp;
        for(int i = 0 ; i < T; ++i){
            temp = arr[i];

            if (check(temp))
                std::cout <<"YES" << std::endl;
            else
                std::cout <<"NO" <<std::endl;
        }
    }
    bool check(std::string temp){
            char s[temp.size()+1]={0,};
            int top =0;

            for(int j =0 ; j < temp.size(); ++j){
                if (temp[j] == '(')
                    s[++top] = temp[j];
                else{
                    if (top > 0)
                        top--;
                    else{
                        return false; // ')'가 많은 경우
                    }
                }
            }
            if (top>0)
                return false; //'('가 더 많은 경우
            else
                return true;
    }
    private:
    int T;
    std::vector<std::string> arr;
};

int main(){
    solver_9012 solver;
    solver.insert_number();
    solver.solver();

    return 0;
}