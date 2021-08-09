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
                    std::cout << "0\n"; 
                else{
                    std::cout << arr.top() << "\n";
                    arr.pop();
                }
            }
            else
                arr.push(x);
        }
    }


    private:
        int N;
        std::priority_queue<int> arr;
};

int main(){


    solver_11279 solver;
    solver.solver();

    return 0;
}