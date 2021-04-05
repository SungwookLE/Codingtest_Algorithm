#include <iostream>
#include <vector>

int main(){
    int n ;
    std::cin >> n;

    for (int i = 0 ; i < n ; ++i){
        int floor, room;
        std::cin >> floor >> room;
        /*
        0: 1  2   3   4   5  6   ...
        1: 1  3   6  10  15  ...
        2: 1  4  10  20  35  ...
        */

        std::vector<std::vector<int>> house;
        std::vector<int> res;
        for(int col =1 ; col <=14 ; ++col){
            res.push_back(col);
        }
        house.push_back(res);
        res.clear();

        for(int row = 1; row<=14; ++row){
            for(int col=1; col<=14; ++col){
                int sum=0;
                int idx = col-1;
                while( idx >= 0 ){
                    sum+=house[row-1][idx];                    
                    idx -=1;
                }
                res.push_back(sum);
            }

            house.push_back(res);
            res.clear();
        }

        std::cout << house[floor][room-1] <<"\n";

    }

    return 0;
}