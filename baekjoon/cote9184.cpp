#include <iostream>
#include <vector>
const int size = 21;

int w(int a, int b, int c, int val_map[][size][size]){
    if ( a<=0 || b<=0 || c<=0)
        return 1;
    
    if ( a > 20 || b > 20 || c > 20 )
        return w(20,20,20, val_map);

    int& results = val_map[a][b][c];

    if (results != 0 )
        return results;

    if ( a< b && b < c)
        results= ( w(a,b,c-1, val_map) + w(a,b-1,c-1, val_map) - w(a,b-1,c, val_map));
    else
        results= ( w(a-1,b,c, val_map) + w(a-1,b-1,c, val_map) + w(a-1,b,c-1, val_map) - w(a-1,b-1,c-1, val_map));

    return results;
}

int main(){
    // Dynamic Programming 
    int val_map[size][size][size]={0,};

    while (1){
        int a, b, c;
        std::cin >> a >> b >> c;
        if ( a==-1 && b==-1 && c==-1)
            break;

        std::cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a,b,c, val_map) << std::endl;

    }
    return 0;
}