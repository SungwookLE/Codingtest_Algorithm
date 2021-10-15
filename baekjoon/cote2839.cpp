#include <iostream>

int main(){
    int n;
    std::cin >> n;

    int count=0;
    while ( n > 2 ){
        if (n%5==0){
            count +=1;
            n-=5;
        }
        else if (n%3==0){
            count +=1;
            n-=3;
        }
        else{
            if (n>=5){
                count += 1;
                n-=5;
            }
            else if (n>=3){
                count += 1;
                n-=3;
            }
            
        }
    }
    if (n>0)
        std::cout << -1 << "\n";
    else
        std::cout << count << "\n";
    return 0;
}