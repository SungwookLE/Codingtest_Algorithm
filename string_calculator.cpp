#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/**
 * @brief String Calculator only works in integer expression
 * ref: https://penglog.tistory.com/99
 */
class string_calculator{
    public:
    double string_calc(string inputs){

        string process_input = tokenizer(inputs);
        stringstream ss(process_input);
        string token;

        while(ss >> token){
            if (token == "(")
                operations.push_back({0, "("});
            else if (token == ")"){

                while (operations.back().oper != "("){
                    calc();
                }
                operations.pop_back();
            }
            else if(token == "*" || token == "/" || token == "+" || token == "-"){
                int prior;
                if (token == "*")
                    prior = 2;
                else if (token == "/")
                    prior = 2;
                else if (token == "+")
                    prior = 1;
                else if (token == "-")
                    prior = 1;
                
                while (!operations.empty() && prior <= operations.back().prior)
                    calc();
                
                operations.push_back({prior, token});
            }
            else
                numbers.push_back(stod(token));
        }

        while(!operations.empty())
            calc();
        
        return numbers.back();
    }

    private:

    string tokenizer(string _input){
        string process_string;
        bool flag = false;
        for(int i= 0; i < _input.length() ; ++i){
            if (_input[i] >= '0' && _input[i] <= '9' || _input[i] == '.'){
                if (flag == false){
                    process_string += ' ';
                    process_string += _input[i];
                    flag = true;
                }
                else{
                    process_string += _input[i];
                }
            }
            else{
                flag = false;
                process_string+=' ';
                process_string+= _input[i];
            }
        }
        cout << process_string << endl;
        return process_string;
    }

    void calc(){
        double a, b, result;
        b = numbers.back();
        numbers.pop_back();
        a = numbers.back();
        numbers.pop_back();
        string o;
        o = operations.back().oper;
        operations.pop_back();

        if (o == "*")
            result = (double)a*b;
        else if ( o =="/")
            result = (double)a/b;
        else if ( o =="+")
            result = (double)a+b;
        else if ( o == "-")
            result = (double)a-b;
        
        iter+=1;

        numbers.push_back(result);
        cout << iter << "th intermediate: ";
        for (auto a : numbers)
            cout << a << " ";
        cout << endl;
    }
    struct op{
        int prior;
        string oper;
    };
    vector<double> numbers;
    vector<op> operations;
    int iter = 0;

    /**
     * @brief Not Use, just for showing operator priority
     */
    vector<op> operate_prior_example=  {{0,"("}, {0,")"}, {1,"+"}, {1,"-"}, {2,"*"}, {2,"/"}};
    
};

int main(int argc, char* argv[]){

    string_calculator calc;
    cout << calc.string_calc(argv[1]) <<endl;

}