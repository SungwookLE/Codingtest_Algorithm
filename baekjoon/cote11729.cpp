#include <iostream>
#include <vector>
// hanoi

void hanoi(int n, char start,  char via, char to, int &count, std::vector<std::vector<char>>& log){
    if (n==1){
        //std::cout << start << " "<< to << "\n";
        log.push_back({start, to});
    }
    else{
        hanoi(n-1, start, to, via, count, log);
        log.push_back({start, to});
        //std::cout << start << " "<< to << "\n";
        hanoi(n-1, via, start, to, count, log);
    }
    count+=1;
}

int main(){
    int n ;
    std::cin >> n;

    int ans_count=0;
    std::vector<std::vector<char>> log;
    hanoi(n, '1', '2','3', ans_count, log);

    std::cout << ans_count << "\n";
    for (auto row : log){
        for (auto col : row)
            std::cout << col << " ";
        std::cout << "\n";
    }

    return 0;
}