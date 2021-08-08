#include <iostream>
#include <vector>
#include <queue>

// 우선순위 큐

class solver_11279{
    public: 
    void solver(){
        std::cin >> N;
        int x;
        for (int i =0 ; i < N ; ++i){
            std::cin >> x;
            if (x==0){
                if (arr.empty())
                    // ans.push_back(0);
                    std::cout << "0\n"; 
                else{
                    std::cout << arr.top() << "\n";
                    arr.pop();
                }
            }
            else
                arr.push(x);
        }

        // for(auto a : ans)
            // std::cout << a << std::endl;
    }


    private:
        int N;
        std::priority_queue<int> arr;
        std::vector<int> ans;
};

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    solver_11279 solver;
    solver.solver();

    return 0;
}