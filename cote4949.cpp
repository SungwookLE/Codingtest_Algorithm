#include <iostream>
#include <vector>

class solver_4949{
    public:
    void insert(){
        std::string temp;
        std::getline(std::cin, temp);

        while ( temp[0] != '.'){
            arr.push_back(temp);
            std::getline(std::cin, temp);
        }
    }
    void solver(){
        std::string temp;
        for(int i =0 ; i < arr.size() ; ++i){
            temp = arr[i];

            if (check(temp)) 
                std::cout <<"yes" << std::endl;
            else
                std::cout <<"no" <<std::endl;
        }
    }
    bool check(std::string temp){
            char s[temp.size()+1]={0,};
            int top =0;
            for(int j =0 ; j < temp.size(); ++j){
                if (temp[j] == '(' || temp[j] == '[')
                    s[++top] = temp[j];
                else if (temp[j] == ')' ){
                    if (top > 0){
                        if (s[top] != '(')
                            return false;
                        else
                            top--;
                    }
                    else
                        return false; // ')'가 많은 경우
                }
                else if (temp[j] == ']' ){
                    if (top > 0){
                        if (s[top] != '[')
                            return false;
                        else
                            top--;
                    }
                    else
                        return false; // ')'가 많은 경우
                }
            }
            if (top>0)
                return false; //'('가 더 많은 경우
            else
                return true;
    }

    private:
    std::vector<std::string> arr;
    size_t size=100;
};

int main(){
    solver_4949 solver;
    solver.insert();
    solver.solver();

    return 0;
}