#include <iostream>
#include <memory>

template<typename T>
class Queue{
    public:
        Queue(){}

        void print(){
            for(int i = 1 ; i <= index ; ++i)
                std::cout << this->array[i] << " ";
            std::cout << std::endl;
        }

        int size(){
            return this->index;
        }

        void push(T d){
            index +=1;
            resize(this->array, index);
            this->array[index] = d;
        }

        bool empty(){
            if (this->index == 0)
                return true;
            else
                return false;
        }

        void pop(){
            for(int i =1 ; i <= index ; ++i)
                this->array[i] = this->array[i+1];

            index-=1;
            resize(this->array, Queue::index);
        }

        T front(){
            return this->array[1];
        }

        T back(){
            return this->array[index];
        }

    private:
        T *array = new T[1]{-1,}; 
        int index =0;
        void resize(T*& arr, int N){ // !!! 주소값도 바꾸어 주기 위해서 call by reference 한 부분 --> 주의할것!
            // std::cout << "Before: " << arr << std::endl;
            T* new_arr = new T[N+1]{-1,};
            for(int i = 1; i <= N ; ++i)
                new_arr[i] = arr[i];
            delete[] arr;
            arr = new_arr;
            // std::cout << "Aftere: " << arr << std::endl;
        }
};

int main(){
    Queue<int> queue;
    queue.push(3);
    queue.push(6);
    queue.push(9);

    queue.print();

    queue.pop();
    queue.pop();
    queue.push(12);
    queue.print();

    std::cout <<queue.front() << std::endl;
    std::cout <<queue.back() << std::endl;
    std::cout <<queue.empty() << std::endl;


    return 0;
}

