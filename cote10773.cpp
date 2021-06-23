#include <iostream>
#include <vector>

class solver_10773_STL{
    public:
    void insert_num(){
        std::cin >> K;
        int num;
        for(int i =0 ; i < K ; ++i){
            std::cin >> num;
            number.push_back(num);

            if (number.back() == 0){
                number.pop_back();
                int temp = number.back();
                number.pop_back();
                //std::cout <<"POP: "<< temp << std::endl;
            }
        }
    }

    void solver(){
        for(int i = 0 ; i < number.size() ; ++i){
            sum+= number[i];
        }
        std::cout << sum << std::endl;
    }

    private:
    int K;
    std::vector<int> number;
    int sum =0;
};


class solver_10773{
    public:
    solver_10773(){
        numbers = new int[1]{};
    }

    void insert_num(){
        std::cin >> K;
        int num;
        for(int i =0 ; i < K ; ++i){
            std::cin >> num;
            push_back(num);

            if (back() == 0){
                pop_back();
                pop_back();
                //debug();
            }
        }
    }

    void pop_back(){
        arr_size-=1;
        if (arr_size ==0)
            numbers[0] = 0;
        else
            resize(numbers, arr_size);
    }

    void resize(int *& arr, int n){
        int* new_arr = new int[n]{};
        std::copy(arr, arr+n, new_arr);
        delete[] arr;
        arr = new_arr;
    }

    void push_back(int x){

        arr_size+=1;
        resize(numbers, arr_size);
        numbers[arr_size-1] = x;

    }
    int back(){
        return numbers[arr_size-1];
    }

    void solver(){
        for(int i = 0 ; i < arr_size ; ++i){
            sum+= numbers[i];
        }
        std::cout << sum << std::endl;
    }

    void debug(){
        std::cout <<"DEBUG: ";
        for(int i = 0 ; i < arr_size ; ++i){
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
    }

    private:
    int arr_size=0;
    int K;
    int sum =0;
    int* numbers;
};

int main(){
    solver_10773 solver;
    solver.insert_num();
    solver.solver();

    return 0;
}