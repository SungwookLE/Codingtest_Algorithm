#include <iostream>
#include <vector>
//브루트포스

int main(){

    int constructor;
    int n;
    int candi;
    std::cin >> n;

    std::vector<std::vector<int>> arr;
    for(int i = 0 ; i < 7 ; ++i){
        std::vector<int> res = {0,1,2,3,4,5,6,7,8,9};
        arr.push_back(res);
    }
    int idx =0;
    for (int one : arr[0]){
        for (int two: arr[1]){
            for (int three: arr[2]){
                for (int four : arr[3]){
                    for (int five : arr[4]){
                        for (int six : arr[5]){
                            for (int seven: arr[6]){
                                constructor = one + two + three +four + five + six+ seven + one + two*10 + three*100 + four*1000 + five * 10000 + six * 100000 + seven* 1000000; 
                                if (constructor == n){
                                    candi = seven*1000000+six*100000 + five*10000 + four * 1000 + three*100 + two*10 + one;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << candi << "\n";
    return 0;
}