#include <iostream>
#include <vector>


void w(int in, int N, std::vector<int>& tile){
    if (in == N)
        return;

    for (int i =0 ; i < N ; ++i){
        tile[in] =i;
        w(in+1, N, tile);
    }

}


int main(){
    int N;
    std::cin >> N;

    std::vector<int> tile(N);

    w(0, N, tile);

    for(auto row: tile){
        std::cout << row << " ";
    }

    return 0;
}