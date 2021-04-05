#include <iostream>

int main(){
    int n ;
    std::cin >> n;
    for (int i =0 ; i < n ; ++i){
        int x1,y1,r1,x2,y2,r2;
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double rr= (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        double r_max = (r1+r2)*(r1+r2);
        double r_min = (r1-r2)*(r1-r2);


        if ((x1==x2) && (y1==y2) && (r1==r2))
            std::cout << -1 << "\n";
        else if (r_max == rr)
            std::cout << 1 <<"\n";
        else if (r_min == rr)
            std::cout << 1 << "\n";
        else if ( rr > r_max)
            std::cout << 0 << "\n";
        else{
            if ( rr < r_min)
                std::cout << 0 << "\n";
            else
                std::cout << 2 << "\n";
        }
    }
    return 0;
}