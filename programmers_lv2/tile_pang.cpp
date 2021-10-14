#include <string>
#include <vector>
#include <iostream>

using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/17679

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    for(auto row: board){
        for(auto col : row){
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }

    while(1){
        bool isDone = true;
        vector<vector<bool>> check;
        check.resize(m, vector<bool>(n,false));

        for (int i =0; i < (m-1) ; ++i){
            for(int j=0; j <(n-1); ++j){

                if(board[i][j] ==0) continue;
                if(board[i][j]==board[i][j+1]){
                    char target = board[i][j];
                    if((board[i+1][j] == target) && (board[i+1][j+1]==target)){
                        check[i][j] = true;
                        check[i][j+1] = true;
                        check[i+1][j] = true;
                        check[i+1][j+1] = true;
                        isDone = false;
                    }
                }
            }
        }

        if (isDone== true) break;

        for(int i =0 ; i <m; ++i){
            for(int j =0; j < n ; ++j){
                if (check[i][j] == true){
                    answer++;

                    for(int k = i ; k >0; k--){
                        board[k][j] = board[k-1][j]; // board 위에서 아래로 타일이 내려옴
                    }
                    board[0][j] = 0;
                }
            }
        }

        for(auto row: board){
            for(auto col : row){
                std::cout << col << " ";
            }
            std::cout << std::endl;
        }
        
    }
    
    return answer;
}

int main(){

    solution(4, 5,{"CCBAA", "AAAAA", "AAABB", "CCBBB"} );

    return 0;
}


/*
CCBAA
AAAAA
AAABB
CCBBB
*/