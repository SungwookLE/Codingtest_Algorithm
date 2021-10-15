#include <iostream>
#include <vector>

// N-Queen 문제: 크기가 NxN인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제
// N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램
// 퀸의 행마법: https://namu.wiki/w/%ED%80%B8(%EC%B2%B4%EC%8A%A4)
// 백트래킹 문제 = N-queen 


void n_queen(int N, std::vector<std::vector<int>>& chess_board, int position_x, int position_y, int &ans){

    if (( N == position_x ) || ( N == position_y)){
        return;
    }

    position_x %= N;
    position_y %= N;

    if (chess_board[position_y][position_x] == 0){
        for(int col =0 ; col < N ; ++col)
            chess_board[position_y][col] = 1;
        for(int row =0 ; row < N ; ++row)
            chess_board[row][position_x] = 1;
        for(int cross_x =position_x, cross_y=position_y; (cross_x<N && cross_y<N); (++cross_x, ++cross_y))
            chess_board[cross_y][cross_x] = 1;
        for(int cross_x =position_x, cross_y=position_y; (cross_x<N && cross_y>=0); (++cross_x, --cross_y))
            chess_board[cross_y][cross_x] = 1;
        for(int cross_x =position_x, cross_y=position_y; (cross_x>=0 && cross_y<N); (--cross_x, ++cross_y))
            chess_board[cross_y][cross_x] = 1;
        for(int cross_x =position_x, cross_y=position_y; (cross_x>=0 && cross_y>=0); (--cross_x, --cross_y))
            chess_board[cross_y][cross_x] = 1;

        ans +=1;
    }
    
    n_queen(N, chess_board, position_x+2 , position_y+1, ans);
    //실패

}

int main(){
    
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    std::vector<std::vector<int>> chess_board(N,arr);
    int ans=0;

    n_queen(N, chess_board, 0,0, ans);

    for(auto row: chess_board){
        for(auto col : row)
            std::cout << col << " ";
        std::cout << "\n";
    }

    std::cout << ans << "\n";

    return 0;
}