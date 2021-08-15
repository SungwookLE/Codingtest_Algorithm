#include <iostream>

// Using Heap(Hand coding)
template<typename T>
class custom_queue{

    public:
    custom_queue(int _size=0): size_data(_size) {
        heapdata = new T[size_data];
    }

    void push(T x){

        resize(heapdata, size_data+1);
        heapdata[size_data] = x;
        int parent = (size_data-1)/2;
        int child = size_data;

        while (parent >= 0 && heapdata[child] < heapdata[parent] ){

            T temp= heapdata[child];;
            heapdata[child]= heapdata[parent];
            heapdata[parent] = temp;

            child = parent;
            parent = (child-1)/2;
        }
        size_data+=1;
    }

    void pop(){

        heapdata[0] = heapdata[size_data-1];
        resize(heapdata, size_data-1);
        size_data-=1;

        int parent = 0;
        int child = parent*2+1;
        bool placed = false;

        while(!placed && child < size_data){
            if (child < (size_data-1) && heapdata[child] > heapdata[child+1] )
                child +=1;
            
            if (heapdata[parent] <= heapdata[child])
                placed = true;
            else{
                T temp = heapdata[child];
                heapdata[child] = heapdata[parent];
                heapdata[parent] = temp;
            }

            parent = child;
            child = parent*2+1;
        }

    }

    T top(){
        return heapdata[0];
    }

    bool empty(){
        if (size_data == 0)
            return true;
        else
            return false;
    }

    int size(){
        return size_data;
    }

    private:
    T* heapdata;
    int size_data;
    void resize(T* &arr, int new_size){
        T* new_arr = new T[new_size];
        for(int i = 0; i < std::min(size_data,new_size) ; ++i)
            new_arr[i] = arr[i];
        delete [] arr;
        arr = new_arr;
    }
};

template<typename T>
class solver_1927{

    public:
    solver_1927(int _N): N(_N) {
        prior_queue = new custom_queue<T>;}

    void solver(){

        int x;
        for (int i = 0 ; i < N ; ++i){
            std::cin >> x;
            if ( x== 0 ){
                if (prior_queue->empty())
                    std::cout << "0\n";
                else{
                    std::cout << prior_queue->top() << "\n";
                    prior_queue->pop();
                }

            }
            else{
                prior_queue->push(x);
            }
        }
    }

    private:
    int N;
    custom_queue<T> *prior_queue;
};

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int N;
    std::cin >>N;

    solver_1927<int> solver(N);
    solver.solver();

    return 0;
}