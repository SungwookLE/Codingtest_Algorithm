// 구현해보기 (8/8)
// REF: https://junstar92.tistory.com/63

#include <iostream>

template<typename T>
class Heap{
public:
    Heap(int maxSize = 100): n(0), maxSize(maxSize), heapData(new T[0]) {}
    ~Heap(){ delete[] heapData; }

    void push(const T data){
        resize(heapData, n+1);
        heapData[n] = data;
        int parent = (n-1)/2;
        int child = n;

        while (parent >= 0 && heapData[parent] < heapData[child]){

            T tmp = heapData[parent];
            heapData[parent] = heapData[child];
            heapData[child] = tmp;

            child = parent;
            parent = (child-1)/2;
        }
        ++n;

        // 왜 new 가 없지 heap배열이 늘어남에 따라 new 해서 잡아주어야 함: resize 함수 필요: 있어야함 잘못된 사용임 (8/9) #############################################################################
    }

    void pop(){
        if (!empty()){
            heapData[0] = heapData[--n];
            resize(heapData, n);

            int parent = 0;
            int child = parent*2 +1;
            bool placed = false;

            while (!placed && child < n){
                if (child < (n-1) && heapData[child] < heapData[child+1] )
                    child+=1;

                if (heapData[parent] >= heapData[child])
                    placed = true;
                else{
                    T tmp = heapData[parent];
                    heapData[parent] = heapData[child];
                    heapData[child] = tmp;
                }

                parent = child;
                child = parent*2 +1;
            }
        }
        else
            std::cout << "EMPTY!\n";

    }

    T top(){
        if (!empty())   
            return heapData[0];
        else
            return 0;
    }

    int size(){
        return n;
    }

    bool empty(){
        return (n==0);
    }

    void print(){
        std::cout << "[";
        for(int i =0 ; i < n ; ++i)
            std::cout << heapData[i] << " ";
        std::cout <<"]";
    }

private:
    int n;
    int maxSize;
    T* heapData;

    void resize(int* &arr, int new_N){
        int *new_arr = new int[new_N];
        for(int i = 0 ; i < std::min(n, new_N) ; ++i)
            new_arr[i] = arr[i];
        delete [] arr;
        arr = new_arr;
    }
};

template<typename T>
class solver_11279{
public:
    solver_11279(){
        heap = new Heap<T>;
    }
    ~solver_11279(){
        delete heap;
    }

    void solver(){
        std::cin >> N;
        int x;
        for(int i =0 ; i < N ; ++i){
            std::cin >> x;

            if (x==0){
                if (!heap->empty()){
                    std::cout<< heap->top() <<std::endl;
                    heap->pop();
                }
                else
                    std::cout << heap->top() <<std::endl;
            }
            else
                heap->push(x);
        }

        // for(auto a : ans)
        //     std::cout << a << std::endl;

    }

private:
    Heap<T>* heap;
    int N;
    // std::vector<int> ans;

};

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    solver_11279<int> solver;
    solver.solver();

    return 0;
}