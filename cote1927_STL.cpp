#include <iostream>
#include <queue>

// USING STL
template<typename T>
class prior_queue{
    public:
        void push(T x){
            datas.push(x);
        }
        void pop(){
            datas.pop();
        }
        T top(){
            return datas.top();
        }
        bool empty(){
            return datas.empty();
        }
    private:
        int size;
        std::priority_queue<T, std::vector<T>, std::greater<T>> datas;
};

template<typename T>
class solver_1927{
    public:
    solver_1927(int _N){
        N=_N;
        prior_que = new prior_queue<T>;
    }

    void solver(){
        T x;
        for (int i =0; i < N ; ++i){
            std::cin >> x;

            if ( x== 0){
                if(prior_que->empty())
                    std::cout << "0\n";
                else{
                    std::cout << prior_que->top() << "\n";
                    prior_que->pop();
                }
            }
            else
                prior_que->push(x);
        }
    }

    private:
        int N;
        prior_queue<T> *prior_que;
};

int main(){
    int N;
    std::cin >> N;
    solver_1927<int> solver(N);
    solver.solver();


    return 0;
}