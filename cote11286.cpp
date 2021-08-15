#include <iostream>
#include <queue>

class solver_11286{

public:
    solver_11286(int _N): N(_N) {
        prior_queue = new std::priority_queue<int, std::vector<int>, comp>;
    }
    void solver(){
        int x;
        for(int i =0; i < N ; ++i){
            std::cin >> x;

            if(x==0){
                if (prior_queue->empty())
                    std::cout <<"0\n";
                else{
                    std::cout << prior_queue->top() << "\n";
                    prior_queue->pop();
                }
            }
            else
                prior_queue->push(x);
        }
    }


private:
    struct comp{
        bool operator()(int a , int b){
        if (abs(a) > abs(b))
            return true;
        else{
            if (abs(a) == abs(b)){
                if (a > b)
                    return true;
                else
                    return false;
            }
            else
                return false;
            }
        }
    };
    // 이렇게 선언을 해야 작은 수가 우선순위를 가지는 HEAP TREE가 선언이 된다.
    // https://travelbeeee.tistory.com/126
    
    std::priority_queue<int, std::vector<int>, comp> *prior_queue;
    int N;

};

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int N;
    std::cin >> N;

    solver_11286 solver(N);
    solver.solver();

    return 0;
}