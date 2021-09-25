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
            print_handle();
            iter++;
        }
    }

    void erase_tetris(){

        std::vector<bool> horizontal_checker, vertical_checker;

        // 가로
        for(int row =0 ; row < N ; ++row){
            int temp  = handle[row][0];
            bool horizontal = true;
            for(int col = 1 ; col < N ; ++col){
                if(temp != handle[row][col]){
                    horizontal = false;
                }
            }
            horizontal_checker.push_back(horizontal);
        }

        // 세로
        for(int col = 0 ; col < N ; ++col){
            int temp = handle[0][col];
            bool vertical = true;
            for(int row =0 ; row < N ; ++row){
                if (temp != handle[row][col]){
                    vertical = false;
                }
            }
            vertical_checker.push_back(vertical);
        }


        for(int row = 0 ; row<horizontal_checker.size() ; ++row){
            if (horizontal_checker[row] == true){
                handle.erase(handle.begin()+row);
                score +=N;

                auto temp = tetris.back();
                tetris.pop_back();
                handle.insert(handle.begin(), temp);
            }
        }


        for(int col = 0 ; col < vertical_checker.size(); ++col){
            if(vertical_checker[col] == true){

                score += N;
                for(int i =1 ; i <=N ; ++i){

                    print_all();
                    int temp = tetris[tetris.size()-i][col];
                    handle[handle.size()-i][col]=temp;

                    if ( (tetris.size()-(i+N)) >= 0 )
                        tetris[tetris.size()-i][col] = tetris[tetris.size()-(i+N)][col];
                }
            }
        }


    }

    private:
    int N, iter=0, score=0;
    std::vector<std::vector<int>> tetris;
    std::vector<std::vector<int>> handle;


};

int main(){

    garage_game solver;
    solver.solver();


    return 0;
}