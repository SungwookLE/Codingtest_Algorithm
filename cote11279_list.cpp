#include <iostream>
#include <algorithm>
#include <vector>

// 우선순위 큐

class prior_queue{
    public:
    prior_queue(){
        size = 0;
        queue_arr = new int[1]{0,};
    }

    prior_queue(int n): size(n){
        queue_arr = new int[size]{0,};
    }

    bool empty(){
        if (size ==0)
            return true;
        else
            return false;
    }
    void push(int x){
        size +=1;
        resize(queue_arr, size);
        queue_arr[size-1] = x;
    }

    void pop(){
        //sort_queue(); // 지워도됨
        size -=1;
        if (size != 0)
            resize(queue_arr, size);
    }
    int top(){
        sort_queue();
        return queue_arr[size-1];
    }

    private:
    int* queue_arr;
    int size=0;
    void resize(int* &arr, int new_N){
        int *new_arr = new int[new_N]{0,};
        for(int i = 0 ; i < std::min(int(size), new_N) ; ++i)
            new_arr[i] = arr[i];
        delete [] arr;
        arr = new_arr;
    }
    void sort_queue(){
        std::sort(queue_arr, queue_arr+size, [](int a, int b){
            if ( a< b)
                return true;
            else
                return false;
        });
    }

};


class solver_11279{
    public: 
    solver_11279(){
        queue = new prior_queue;
    }
    void solver(){
        int N ;
        std::cin >> N;

        int x;
        for (int i =0 ; i < N ; ++i){
            std::cin >> x;
            if ( x == 0){
                if (queue->empty())
                    std::cout << "0\n";
                else{
                    // ans.push_back(queue->top());
                    std::cout << queue->top() <<"\n";
                    queue->pop();
                }
            }
            else
                queue->push(x);
        }
        // for(auto  a : ans)
        //     std::cout << a << std::endl;
    }

    private:
        int N;
        prior_queue* queue;
        std::vector<int> ans;
};

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    solver_11279 solver;
    solver.solver();

    return 0;
}