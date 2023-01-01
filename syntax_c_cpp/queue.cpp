
#include <iostream>
//큐의 개념을 익히고 실습하는 문제. 연산 당 시간 복잡도가 O(1)이어야 한다는 점에 유의하세요.
class solver_18258{

    public:
        solver_18258(){
            arr = new int[1]{-1};
        }    
        void push(int X){
            index+=1; // 1
            resize(arr, index+1); //2

            arr[index]=X;

        }
        int pop(){

            int front = -1;
            if (!empty()){
                front = arr[1];
                for(int i = 1 ; i < index ; ++i){
                    arr[i] = arr[i+1];
                }

                // std::cout << "IN POP: \n";
                // for (int i = 0; i <=index ; ++i)
                //     std::cout << arr[i] << " " ;
                // std::cout << std::endl;

                index -= 1;
                resize(arr, index+1); 
            }

            return front;
        }
        int size(){
            return index;
        }
        int empty(){
            if (index == 0) 
                return 1;
            else
                return 0;
        };
        int front(){
            if (!empty())
                return arr[1];
            else
                return -1;
        }
        int back(){

            if (!empty())
                return arr[index];
            else
                return -1;
        }

        void monitoring(){

            std::cout << "IN QUEUE: \n";
            for (int i = 0; i <=index ; ++i)
                std::cout << arr[i] << " " ;
            std::cout << std::endl;
        }

    private:
        int* arr;
        int index=0;

        void resize(int*& arr, int N){ // N = 2
            
            int* new_arr = new int[N]{-1,};
            for(int i =0 ; i < N ; ++i)
                new_arr[i] = arr[i];

            delete [] arr;
            arr = new_arr;
        }
};
