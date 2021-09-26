#include <iostream>
#include <vector>
#include <queue>

class garage_game{
    public:
    garage_game(){
        std::cin >> N;

        tetris.resize(3*N, std::vector<int>(N,0));
        for(int i =0 ; i < 3*N ; ++i){
            for (int j =0 ; j < N ; ++j)
                std::cin >> tetris[i][j];
        }
        for(int i =0 ; i < N ; ++i){
            handle.insert(handle.begin(), tetris.back());
            tetris.pop_back();
        }

        checker.resize(0, std::vector<int>(N,0));
    }

    void print_all(){
        std::cout << "print all: \n";
        for(auto row: tetris){
            for(auto col : row)
                std::cout << col << " ";
            std::cout << std::endl;
        }
    }

    void print_handle(){
        std::cout << "print handle: \n";
        for(auto row: handle){
            for(auto col : row)
                std::cout << col << " ";
            std::cout << std::endl;
        }
    }


    void solver(){

        while (iter<3){
            erase_tetris();
            iter++;
        }
    }

    void erase_tetris(){

        

    }

    void check(){

        for(int row = 0 ; row < N; ++row){
            for(int col = 0 ; col < N ; ++col){


                int temp = handle[row][col];
                int hori = true, vert = true;

                for(int i = 0; i < N ; ++i){
                    if (temp != handle[row][i])
                        hori = false;

                    if (temp != handle[i][col])
                        vert = false;
                }

                if (hori==true)
                    checker[row][col] = 1;

                if (vert == true)
                    checker[row][col] = 2;

                if (hori && vert)
                    checker[row][col] = 3;   

            // 이거 어떻게 체크해나갈수 있지? 백트래킹 쓰면 될거 같은데... (9/25)
            // https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=540

            }
        }

    }

    private:
    int N, iter=0, score=0;
    std::vector<std::vector<int>> tetris;
    std::vector<std::vector<int>> handle, checker;


};

int main(){

    garage_game solver;
    solver.solver();


    return 0;
}