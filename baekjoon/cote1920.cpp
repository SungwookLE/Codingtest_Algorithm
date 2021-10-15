#include <iostream>
#include <vector>
#include <algorithm>

class solver_1920{
    public:
    solver_1920(std::vector<int> _arr1, std::vector<int> _arr2){
        std::sort(_arr1.begin(), _arr1.end(), [](int a , int b){
                if (a < b)
                    return true;
                else
                    return false;                
            }
        );
        arr1 = _arr1;
        arr2=_arr2;
    }

    void solver(){
        for(int i =0 ; i < arr2.size() ; ++i){

            int target = arr2[i];
            int start =0;
            int end = arr1.size()-1;
            int mid;

            while(start <= end ){
                mid = (start+end)/2;

                if (arr1[mid] < target)
                    start = mid+1;
                else if (arr1[mid] > target)
                    end = mid-1;
                else{
                    break;
                }
            }
            if (arr1[mid] == target)
                std::cout << "1\n";
            else
                std::cout << "0\n";                    
        }
    }  
    private:
    std::vector<int> arr1, arr2;
};

int main(){
    int N,M;
    std::cin >> N;

    std::vector<int> arr1(N);
    for(int i =0 ; i < N ; ++i)
        std::cin >> arr1[i];

    std::cin >> M;
    std::vector<int> arr2(M);
    for(int i =0 ; i < M ; ++i)
        std::cin >> arr2[i];

    solver_1920 solver(arr1, arr2);
    solver.solver();

    return 0;
}