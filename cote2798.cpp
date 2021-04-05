#include <iostream>
#include <vector>

// 브루트포스

int main(){

    int N, M;
    std::cin >> N >> M;

    std::vector<int> set;
    for(int i =0 ; i < N ; ++i){
        int num;
        std::cin >> num;

        set.push_back(num);
    }
    int max_num =0;

    int one_idx=0;
    for(int one: set){
        int two_idx =0;
        for(int two: set){
            int three_idx=0;
            for(int three:set){

                int res = one + two + three;
                if ((max_num < res) && (res <=M) &&(one_idx != two_idx) && (one_idx != three_idx) && (two_idx != three_idx)){
                    max_num = res;
                }
                three_idx+=1;
            }
            two_idx+=1;
        }
        one_idx+=1;
    }

    std::cout << max_num;

    return 0;
}