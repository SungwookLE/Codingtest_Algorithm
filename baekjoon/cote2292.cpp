#include <iostream>

int main(){
    int n;
    std::cin >> n;
    //1 --(1)--> 2 --(7 )--> 9  --(13)--> 22 --(19)--> 41 --> 61
    //1 --(2)--> 3 --(8 )--> 11 --(14)--> 25 --(20)--> 45
    //1 --(3)--> 4 --(9 )--> 13 --(15)--> 28 --(21)--> 49
    //1 --(4)--> 5 --(10)--> 15 --(16)--> 31 --(22)--> 53
    //1 --(5)--> 6 --(11)--> 17 --(17)--> 34 --(23)--> 57
    //1 --(6)--> 7 --(12)--> 19 --(18)--> 37 --(24)--> 61
    // 아 등차가 6씩 증가하네.

    int diff = 6;
    int idx=1;
    int origin = 1;

    while(n > origin ){
        diff = idx*6;
        origin = diff + origin;
        idx += 1;
    }

    std::cout << idx;
    return 0;
}