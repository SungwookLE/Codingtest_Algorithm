#include <iostream>
#include <vector>

// STACK은 First In Last Out 인 구조이고,
// 이거를 동적 할당해서 진짜 vector STL처럼 하려고 햇는데,
// 동적 메모리 할당하고 이런 과정에서 문제를 만나 시간 소모를 크게 하다가
// 그냥 쉬운방식으로 풀었음.
// int *arr = new int[10]{};
// 이렇게 해서 resize해나가면서 풀려고 햇는데,, 

class solver_10828{

public:
void insert_solve(){
    int n;
    std::cin >> n;
    std::string order;
    for(int i =0 ; i < n ; ++i){
        std::cin >> order ;

        if (order == "push")
            push();
        else if (order == "pop")
            pop();
        else if (order == "size")
            size();
        else if (order == "top")
            top_f();
        else if (order =="empty")
            empty();
    }
}


void push(){
    int x;
    std::cin >> x;
    top +=1;
    arr[top] = x;
}
void pop(){
    if (top==0)
        std::cout << -1 << std::endl;
    else{
        std::cout << arr[top] << std::endl;
        top-=1;
    }
}
void size(){
    std::cout << top << std::endl;
}

void top_f(){
    if (top == 0)
        std::cout << -1 << std::endl;
    else
        std::cout << arr[top] << std::endl;
}
void empty(){
    if (top == 0)
        std::cout << 1 << std::endl;
    else
        std::cout << 0 << std::endl;
}

private:
    int arr[100001];
    int top =0;

};

int main(){
    solver_10828 solver;
    solver.insert_solve();

    return 0;

}