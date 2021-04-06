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
    


int main(){
    int N;
    std::cin >> N;
    
    std::vector<int> col(N);
    int cnt =0;

    queens(N, col, 0, cnt);
    std::cout << cnt << "\n";
    return 0;
}