#include <iostream>

int main(){

    int ea;
    std::cin >> ea;
    
    int H,W,N;
    

    for(int i = 0 ; i < ea ; ++i){
        std::cin >> H >> W >> N;
        int cols = N/H+1;
        int rows = N-((cols-1)*H);

        if (rows < 0 || H <= 0 || W <= 0 || N <=0 ){
            std::cout << -1 << "\n";
        }
        else if ( rows ==0){
            cols -= 1;
            rows = H;
            int res = (rows)*100 + cols;
            std::cout << res << "\n";
        }
        else{
            int res = (rows)*100 + cols;
            std::cout << res << "\n";
        }
    }

    return 0;
}