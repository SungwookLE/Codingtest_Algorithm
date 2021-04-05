#include <iostream>
#include <vector>

int main(){
    int a,b,c;
    std::cin >> a >> b >> c;


    while ((a>0) && (b>0) && (c>0)){
        int try_sum;
        try_sum = a*a + b*b;
        if (try_sum == c*c)
            std::cout << "right" << "\n";
        
        else{
            try_sum = b*b + c*c;
            if (try_sum == a*a)
                std::cout << "right" <<"\n";

            else{
                try_sum = a*a + c*c;
                if (try_sum == b*b)
                    std::cout <<"right" <<"\n";
                else
                    std::cout <<"wrong" <<"\n";
            }
        }
        std::cin >> a >> b >> c;
    }

    return 0;
}