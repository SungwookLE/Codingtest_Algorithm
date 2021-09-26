#include <iostream>
#include <vector>

// recursion
// hanoi tower
// https://shoark7.github.io/programming/algorithm/tower-of-hanoi
// 하노이 = 재귀, 재귀-> iteration마다 반복되는 구조를 파악해라..
// 하노이는 원반 두개 그려서 파악해보면 일반식은 유도가 되긴 되네 (9/27)


class prob_11729{

public:
    prob_11729(){
        std::cin >> N;
    }
    void solver(){
        hanoi(N, '1','2','3', ans);
        std::cout << ans << std::endl;

        for (auto row: log){
            for(auto col : row)
                std::cout << col << " ";
            std::cout << std::endl;
        }
    }

    void hanoi(int n, char start, char via, char to, int& count){
        if (n==1){
            log.push_back({start, to});
        }
        else{
            hanoi(n-1, start, to, via, count);
            log.push_back({start, to});
            hanoi(n-1, via, start, to, count);
        }
        count+=1;
    }

private:
    int N;
    std::vector<std::vector<char>> log;
    int ans=0;

};

int main(){
    prob_11729 solver;
    solver.solver();

    return 0;
}