#include <iostream>
#include <vector>

class solver_12015{
public:
solver_12015(int _N, std::vector<int> _A){
    N = _N;
    A = _A;
    LIS={0};
}

void solver(){
    int left =0 ;
    int right =0;
    int mid = 0;
    int length = 0 ;
    
    for(int i = 0 ; i < N ; ++i){
        if (A[i] > LIS.back()){
            LIS.push_back(A[i]);
            length++;
        }
        else{
            left = 0 ;
            right = LIS.size();

            while ( left < right ){
                mid = (left+right)/2;

                if (LIS[mid] < A[i])
                    left = mid + 1;
                else if (LIS[mid] >= A[i] )
                    right = mid;
            }
            LIS[right] = A[i];
        }
        debug_LIS();
    }
    std::cout << length << std::endl;

    return;
}

void debug_LIS(){
    std::cout << "LIS: \n";
    for (auto a : LIS)
        std::cout << a << " ";
    std::cout << std::endl;
}

private:
    int N;
    std::vector<int> A;
    std::vector<int> LIS;
};

int main(){
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i =0 ; i < N ; ++i)
        std::cin >> A[i];
    
    solver_12015 solver(N, A);
    solver.solver();

    return 0;
}