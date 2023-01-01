#include <iostream>
#include <vector>

// 정렬: 이건 알고리즘 문제라기 보단 그냥 sort에 대한 학습임
// 전역 search 해서 sort하는 방법 외에도 quick sort, bubble방법 등 여러가지 방법이 있음, 카운팅정렬 등

class prob_2750{
    public:
    prob_2750(){
        std::cin >> N;
        arr.resize(N,0);
        for(int i = 0 ; i < N ; ++i)
            std::cin >> arr[i];
    }

    void sort(){

        // upscent order
        for(int i =0 ; i < N; ++i){
            for(int j= (i+1) ; j < N ; ++j){
                if (arr[i] > arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        for(auto element: arr){
            std::cout << element << std::endl;
        }

        return;
    }

    private:
    int N;
    std::vector<int> arr;

};

int main(){
    prob_2750 solver;
    solver.sort();


    return 0;
}