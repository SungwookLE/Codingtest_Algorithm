#include <iostream>

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    double fix, flo, cost;
    std::cin >> fix >> flo >> cost;
    int idx = 0;

    if ( flo >= cost){
        std::cout << -1 ;
        return 0;
    }
    bool judge=true;
    while(judge){
        idx++;
        judge = (idx*flo + fix)>=(idx*cost);
    }
    std::cout << idx ;
    return 0;
}