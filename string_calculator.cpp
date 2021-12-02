#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/**
 * @brief String Calculator only works in integer expression
 */
class string_calculator{
    public:
    int string_calc(string inputs){

        stringstream ss(inputs);
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
                numbers.push_back(stoi(token));

        }

        while(!operations.empty())
            calc();
        
        return numbers.back();
    }

    private:
    
    void calc(){
        int a, b, result;
        b = numbers.back();
        numbers.pop_back();
        a = numbers.back();
        numbers.pop_back();
        string o;
        o = operations.back().oper;
        operations.pop_back();

        if (o == "*")
            result = a*b;
        else if ( o =="/")
            result = a/b;
        else if ( o =="+")
            result = a+b;
        else if ( o == "-")
            result = a-b;
        
        numbers.push_back(result);
        cout << "intermediate calc:\n";
        for (auto a : numbers)
            cout << a << " ";
        cout << endl;
    }
    struct op{
        int prior;
        string oper;
    };
    vector<int> numbers;
    vector<op> operations;

    /**
     * @brief Not Use, just for showing operator priority
     */
    vector<op> operate_prior_example=  {{0,"("}, {0,")"}, {1,"+"}, {1,"-"}, {2,"*"}, {2,"/"}};
    
};

int main(int argc, char* argv[]){

    string_calculator calc;
    cout << calc.string_calc(argv[1]) <<endl;

}