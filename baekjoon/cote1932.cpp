#include <iostream>
#include <vector>

int main(){
    int N;
    std::cin >> N;
    
    std::vector<int> triangle_row(N+1);
    std::vector<std::vector<int>> triangle(N+1,triangle_row);
    
    for(int row = 1 ; row <= N ; ++row){
        for(int col =1 ; col <= row ; ++col){
            std::cin >> triangle[row][col];
        }
    }

    for(int i =1 ; i <= N ; ++i){
        for(int j =0 ; j <= i ; ++j){
            triangle[i][j] += std::max(triangle[i-1][j-1], triangle[i-1][j]);
        }
    }

    int res = 0;
    for (int i =1 ; i <= N; ++i)
        if (res < triangle[N][i])
            res = triangle[N][i];
        
    std::cout <<res << "\n";

    return 0;
}