#include <iostream>
#include <vector>
//https://cryptosalamander.tistory.com/58

bool check(int N, int level, std::vector<int> &col){

    for (int idx=0; idx < level; ++idx)
        if (col[idx] == col[level] || abs(col[level] - col[idx]) == level-idx )
            return false;
    return true;
}

void queens(int N, std::vector<int> &col, int level, int& cnt){

    if (level == N ){
        cnt++;
        
        // VISUALIZATION
        std::vector<int> res(N);
        std::vector<std::vector<int>> list(N, res);
        int i =0;
        for (auto a : col){
            list[a][i] = 1;
            i++;
        }
        for (auto row : list){
            for (auto col : row)
                std::cout << col << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        return;
    }
    else{
        for(int idx =0 ; idx < N ; idx++){
            col[level] = idx;
            if (check(N, level, col))
                queens(N, col, level+1, cnt);
        }
    }
}

/*
N-queen 문제 풀이가 잘 이해가 되지 않아서, pseudo review 해봄(4/7)

call `queens(N, col, 0, cnt)`

column[0] = 0; 을 채워넣고, 이 의미가 (0행 0열에 퀸을 놓겠다는 의미)
check(N, 0, col)을 해보면, level이 0이 들어왔기 때문에 바로 `true` set 이 되고, (첫번째 트라이니까 다 빈 행렬이기 때문에 따질 것이 없다)

call `queens(N, col, 1, cnt)` 

column[1] = 0; 을 채워넣고, 이 의미가 (0행 1열에 퀸을 놓겠다는 의미)
check(N, 1, col)을 해보면, level이 1이기 때문에 if (col[idx]  == col[1]) 를 하게 되면 col[idx=0] 일 때, 이미 앞단에서 0이 채워져 있기 때문에 col[1] =0 이어서 same value 로서 false
그러면 곧바로 column[1] = 1; 을 채워넣게 되고 (1행 1열에 퀸을 놓겠다는 의미)
check(N, 1, col)을 해보면, level이 1이기 때문에 if (col[idx=0] == col[1])에서는 same value가 아니긴 하나, (col[level] - col[idx=0]) 가 level(1) - idx(0) 와 same value 이기 때문에
false
그러면 곧바로 column[1]=2;를 채워넣고, 이 의미가 (2행 1열에 퀸을 놓겠다는 의미)
check(N, 1, col) 을 해보면, 동일한 열에도 있지 않고, 동일 대각선에도 있지 않아서 true가 되어 그 위치에 퀸을 놓게 되고
call `queens(N, col, 2, cnt)` 를 수행하게 된다.

이러다 보면 모든 열을 훓었다는 의미는 queen을 다 배치했다는 의미가 되고 cnt++ 이 되면서 종료되는 것이다.
*/
    


int main(){
    int N;
    std::cin >> N;
    
    std::vector<int> col(N);
    int cnt =0;

    queens(N, col, 0, cnt);
    std::cout << cnt << "\n";
    return 0;
}