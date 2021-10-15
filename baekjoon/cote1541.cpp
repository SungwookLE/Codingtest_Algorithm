#include <iostream>
#include <vector>

class solver_1541{
    public:
    void insert_input(){
         std::cin >> line;
    }

    void print_insert(){
        std::cout << line <<std::endl;
    }

    int solver(){

        

        int answer =0;

        bool minus = false;
        signV.push_back(1);

        int num =0;


        for(int i = 0 ; i < line.length(); ++i){

            if (line[i] == '+' || line[i] == '-'){
                if (line[i] == '+')
                    signV.push_back(1);
                else
                    signV.push_back(-1);
                
                numV.push_back(num);
                num = 0;

            }
            else{
                num = num*10 + int(line[i]-'0');
            }
        }
        numV.push_back(num);

        for(int i =0; i < numV.size(); ++i){
            if (signV[i] == -1)
                minus = true;
            
            if (minus == true)
                answer -= numV[i];
            else
                answer += numV[i];
        }

        // 아 '-'가 한번이라도 뜨면 그 뒤는 무조건 다 음수로 처리해버리면 최소값이 뜨겠구나!!
        return answer;
    }


    void debug(){
        for(int a =0 ; a<numV.size() ; ++a)
            std::cout << numV[a] << " ";
        std::cout << std::endl;

        for(int b : signV)
            std::cout << b << " ";
        std::cout << std::endl;
        
    }


    private:
    std::vector<int> numV; // +: 1, -: -1
    std::vector<int> signV;
    std::string line;
    int answer =0;

};

int main(){
    solver_1541 solver;
    solver.insert_input();
    int answer = solver.solver();
    //solver.debug();

    std::cout << answer << std::endl;
    return 0;
}


/*
>> REF: https://ssungkang.tistory.com/entry/C-BAEKJOON-1541-%EC%9E%83%EC%96%B4%EB%B2%84%EB%A6%B0-%EA%B4%84%ED%98%B8


문제>>
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.
그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력>>
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

출력>>
첫째 줄에 정답을 출력한다.
*/