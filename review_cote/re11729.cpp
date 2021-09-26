#include <iostream>
#include <vector>

// recursion
// hanoi tower
// <== 좀 더 보다 잘것 ,, rvalue ref 까먹었네 요긴하게 쓸 수 있는건데 이거
// rvalue를 참조로 걸어버릴 수 있다. 변수 없이 근데 언제 효과적이엇더라?? (9/26)


class prob_11729{

public:
    prob_11729(){
        std::cin >> N;
    }

    void solver(){

        recursion(N, '1','2','3', ans);
        
        std::cout << ans << std::endl;
        for (auto row: log){
            for(auto col : row)
                std::cout << col << " ";
            std::cout << std::endl;
        }

    }

    void recursion(int n, char start, char via, char to, int& count){
        if (n==1){
            log.push_back({start, to});
        }
        else{
            recursion(n-1, start, to, via, count);
            log.push_back({start, to});
            recursion(n-1, via, start, to, count);
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