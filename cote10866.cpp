#include <iostream>
//덱의 개념을 익히고 실습하는 문제. (입력 크기가 너무 작아서 비효율적인 구현으로도 통과가 되지만, 가급적이면 연산 당 시간 복잡도가 O(1)이도록 구현해 주세요.)

class solver_10866{
    public:

    solver_10866(){
        arr = new int[1]{0};
        size = 0;
    }

    void push_front(int X){
        resize(arr, size+1);
        size +=1;

        for(int i = (size-1)  ; i >=1 ; --i)
            arr[i] = arr[i-1];
        arr[0] = X;
    }
    void push_back(int X){
        resize(arr, size+1);
        size+=1;

        arr[size-1]=X;
    }
    int pop_front(){
        if (empty())
            return -1;
        int temp = arr[0];

        for(int i = 0 ; i < (size-1) ; ++i)
            arr[i] = arr[i+1];
        
        if (size == 1){
            arr[0] = 0;
            size=0;
        }
        else{
            resize(arr, size-1);
            size-=1;
        }
        return temp;
    }
    int pop_back(){
        if (empty())
            return -1;
        int temp =arr[size-1];

        if (size == 1){
            arr[0] = 0;
            size=0;
        }
        else{
            resize(arr, size-1);
            size-=1;
        }

        return temp;
    }
    int size_arr(){
        return size;
    }
    int empty(){
        if (size ==0)
            return 1;
        else
            return 0;
    }
    int front(){
        if (empty())
            return -1;
        return arr[0];
    }
    int back(){
        if (empty())
            return -1;
        return arr[size-1];
    }

    void monitoring_deque(){
        std::cout << "MONITOR: \n";
        for (int i =0 ; i < size ; ++i){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    private:
    void resize(int* &arr, int new_N){
        int *new_arr = new int[new_N]{0,};
        for(int i = 0 ; i < std::min(int(size), new_N) ; ++i)
            new_arr[i] = arr[i];
        delete [] arr;
        arr = new_arr;
    }
    int *arr;
    size_t size;
};

int main(){

    solver_10866 solver;
    int N;
    std::cin >> N;

    std::string tok;
    for(int i =0 ; i < N ; ++i){
        std::cin >> tok;

        int num=0;
        if (tok == "push_back"){
            std::cin >> num;
            solver.push_back(num);
        }

        else if (tok == "push_front"){
            std::cin >> num;
            solver.push_front(num);
        }

        else if (tok == "front")
            std::cout << solver.front() << std::endl;

        else if (tok == "back")
            std::cout << solver.back() << std::endl;

        else if (tok == "size")
            std::cout << solver.size_arr() << std::endl;

        else if (tok == "pop_front")
            std::cout << solver.pop_front() << std::endl;

        else if (tok == "pop_back")
            std::cout << solver.pop_back() << std::endl;

        else if (tok == "empty")
            std::cout << solver.empty() << std::endl;
        else
            solver.monitoring_deque();

    }

    return 0;
}