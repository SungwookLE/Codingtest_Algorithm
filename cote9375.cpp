#include <iostream>
#include <vector>
#include <unordered_map>

class solver_9375{
    public:
    void insert_array_and_solve(){
        std::cin >> N;
        int ea;
        for(int i =0 ; i < N ; ++i){
            std::cin >> ea;
            std::vector<std::string> res(2);
            array.clear();
            for(int j =0 ; j < ea ; ++j){
                std::cin >> res[0] >> res[1];
                array[res[1]].push_back(res[0]);
            }
            solver(array);
        }
    }

    void solver(std::unordered_map<std::string, std::vector<std::string>> a){
        std::vector<int> ea;
        int answer =1;
        for(auto res =a.begin(); res != a.end(); ++res){
            ea.push_back(res->second.size());
        }
        for(int j =0; j <ea.size() ; ++j){
            answer *= (ea[j] +1);
        }
        answer -= 1;
        answers.push_back(answer);
    }

    void print_answer(){
        for(auto ans : answers)
            std::cout << ans << std::endl;
    }

    private:
    std::unordered_map<std::string, std::vector<std::string>> array;
    std::vector<int> answers;
    int N;
};

int main(){
    solver_9375 solver;
    solver.insert_array_and_solve();
    solver.print_answer();
    return 0;
}