#include <iostream>
#include <vector>
#include <stack>

// STACK : LAST IN, FIRST OUT
class solver_1874{
    public:
    void solver(){
        int n;
        std::cin >> n;

        std::stack<int> s;
        std::vector<char> ans;

        int count = 1;
        int temp;
        for(int i =0 ; i < n ; ++i){
            std::cin >> temp;

            while (count <= temp){
                s.push(count);
                ans.push_back('+');
                count++;
            }

            if (s.top() == temp){
                s.pop();
                ans.push_back('-');
            }
            else{
                std::cout << "NO" <<"\n";
                exit(0);
            }
        }

        for(int i =0 ; i< ans.size() ; ++i)
            std::cout << ans[i] << "\n";
    }

    private:

};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solver_1874 solver;
    solver.solver();

    return 0;
}