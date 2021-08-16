#include <iostream>
#include <queue>
// REF: https://life-with-coding.tistory.com/365
template <typename T>
class solver_1655{
public:
    solver_1655(int _N): N(_N){
        MaxHeap = new std::priority_queue<T>;
        MinHeap = new std::priority_queue<T, std::vector<T>, comp>;
    }
    void solver(){
        T x;
        for(int i = 0 ; i < N ; ++i){
            std::cin >> x;
            MaxHeap->push(x);
            
            if ( (!MinHeap->empty()) && (MaxHeap->top() > MinHeap->top() )  ){
                MinHeap->push(MaxHeap->top());
                MaxHeap->pop();

                MaxHeap->push(MinHeap->top());
                MinHeap->pop();
            }

            if ( (MaxHeap->size() -1 ) > MinHeap->size()){

                MinHeap->push(MaxHeap->top());
                MaxHeap->pop();
            }

            //홀수
            if (i & 1){
                std::cout << std::min(MaxHeap->top(), MinHeap->top()) << "\n";    
            }
            else
                std::cout << MaxHeap->top() << "\n";
        }
    }

private:
    int N;
    struct comp{
        bool operator()(T a, T b){
            if ( a > b )
                return true;
            else
                return false;
        }
    };

    std::priority_queue<T>* MaxHeap;
    std::priority_queue<T, std::vector<T>, comp>* MinHeap;
};

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int N;
    std::cin >> N;
    solver_1655<int> solver(N);
    solver.solver();

    return 0;
}