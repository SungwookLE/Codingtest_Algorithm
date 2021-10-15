#include <iostream>

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int A,B,V;
    std::cin >> A >> B >> V;

    int day ;
    int distance ;
    
    if ( A > B){
        if ( (V/(A-B)-B) > 0 )
            day = V/(A-B)-B;
        else
            day = 1;
    }
    else
        day = 1;
    
    distance = A*day - B*(day-1);
    while ( distance< V ){
        day+=1;
        distance = A*day - B*(day-1);
    }

    std::cout <<day;
    return 0;
}