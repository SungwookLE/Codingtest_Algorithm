#include <iostream>
#include <vector>
#define MAX 9
// REF: https://yabmoons.tistory.com/88
void DFS(int Cnt, std::vector<std::vector<int>> &MAP, std::vector<std::vector<bool>> &Col, std::vector<std::vector<bool>> &Row, std::vector<std::vector<bool>>&Square){
    int x = Cnt / MAX; // x 좌표
    int y = Cnt % MAX; // y 좌표
    if (Cnt == 81){
        //PRINT SOLUTION
        for(auto row: MAP){
            for(auto col: row)
                std::cout << col << " ";
            std::cout << "\n";
        }
        exit(0);
        return;
    }
    if (MAP[x][y] == 0){
        for (int i =1 ; i <=9 ; ++i){
            if ( Row[x][i] == false && Col[y][i] == false && Square[(x/3)*3 + (y/3)][i] == false){ // 중복되지 않은 숫자를 찾았으면, 
                Row[x][i] = true;
                Col[y][i] = true;
                Square[(x/3)*3 + (y/3)][i] = true;
                MAP[x][y] = i;
                DFS(Cnt+1, MAP, Col, Row, Square);
                MAP[x][y] = 0;
                Row[x][i] = false;
                Col[y][i] = false;
                Square[(x/3)*3 + (y/3)][i] = false;
            }
            // 아무 숫자도 넣을 수 없으면 for문을 그냥 빠져나가게 되고 DFS 함수는 종료되고 그 칸은 비워지게 되겠지.!!!
        }
    }
    else
        DFS(Cnt+1, MAP, Col, Row, Square);
    return;
}
int main(){
    std::vector<int> res(MAX,0);
    std::vector<std::vector<int>> MAP(MAX, res);
    std::vector<bool> res_bool(MAX+1,0); // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    std::vector<std::vector<bool>> Row(MAX, res_bool);
    std::vector<std::vector<bool>> Col(MAX, res_bool);
    std::vector<std::vector<bool>> Square(MAX, res_bool);
    for(int i =0 ; i <MAX ; ++i){
        for(int j =0; j < MAX ; ++j){
            std::cin >> MAP[i][j];
            if (MAP[i][j] != 0){
                Row[i][MAP[i][j]] = true;
                Col[j][MAP[i][j]] = true;
                Square[(i/3)*3 +(j/3)][MAP[i][j]] = true;
            }
        }
    }
    DFS(0, MAP, Col, Row, Square);
    return 0;
}