#include <iostream>
#include <vector>

int main(){

    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<char>> map(N);

    //1. Set the given data
    for(int row =0 ; row < N ; ++row){
        std::string line;
        std::cin >> line;
        for(int col =0 ; col < M ; ++col){
            map[row].push_back(line[col]);
        }
    }

    std::vector<std::vector<char>> map_W;
    std::vector<std::vector<char>> map_B;
    std::vector<char> WW = {'W','B','W','B','W','B','W','B'};
    std::vector<char> BB = {'B','W','B','W','B','W','B','W'};


    for (int i = 0; i < 8 ; ++i){
        if ( i%2 ==0){
            map_W.push_back(WW);
            map_B.push_back(BB);
        }
        else{
            map_W.push_back(BB);
            map_B.push_back(WW);
        }
    }



    //2.SOLVE

    int count_w ;
    int count_b ;
    int init_row =0, init_col=0;
    int min_ans = 999;
    int cand ;

    for(init_row = 0 ; init_row < (N-7) ; ++init_row){
        for(init_col =0 ; init_col < (M-7) ; ++init_col){

            count_w =0, count_b=0;
            for(int row =init_row ; row < (8+init_row) ; ++row){
                for(int col =init_col; col < (8+init_col) ; ++col){

                    if ( map[row][col] != map_W[row%8][col%8])
                        count_w +=1;
                    
                    if ( map[row][col] != map_B[row%8][col%8])
                        count_b +=1;
                }
            }

            if (count_w > count_b)
                cand = count_b;
            else
                cand = count_w;
            
            if (min_ans > cand)
                min_ans = cand;

            if (min_ans ==0){
                std::cout << min_ans ;
                return 0;
            }
        }
    }
    std::cout << min_ans;



    //3. DEBUG PRINT


    return 0;
}