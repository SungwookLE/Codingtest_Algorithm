#include <iostream>
//#include <queue>
//#include <vector>

class solver_11866{
public:
    solver_11866(int N_in, int K_in){
        N =N_in;
        K= K_in;
        arr = new int[N]{0,};
        for (int i =1 ; i <= N ; ++i)
            arr[i-1] = i;
    }

    void solver(){
        for(int i =0 ; i < K ; ++i){
            idx+=1;
            idx %= N;
            while(arr[idx] == -1){
                idx += 1;
                idx %= N;
            }
            //std::cout << "IDX: " << idx+1 << "  val: " << arr[idx] << std::endl;
        }    

        std::cout  << arr[idx] ;
        arr[idx] = -1;
    }

private:
    int *arr;
    int N, K;
    int idx=-1;
};

int main(){

    int N, K;
    std::cin >> N >> K;
    solver_11866 solver(N,K);

    std::cout << "<";
    for (int i = 0 ; i < N ; ++i){
        solver.solver();
        if (i != (N-1))
            std::cout << ", ";
    }    
    std::cout << ">\n";

    return 0;
}