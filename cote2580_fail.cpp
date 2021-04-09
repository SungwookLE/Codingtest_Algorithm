#include <iostream>
#include <vector>
#include <algorithm>

bool check_sudoku(int dim, int idx, std::vector<std::vector<int>> sudoku){

    int region_row = dim/3;
    int region_col = idx/3;

    //std::cout << "THIS" <<"("<<dim<<","<<idx<<"): " << sudoku[dim][idx] << std::endl;

    std::vector<int> counting_arr_box(10,0);
    bool flag_box = true;
    for (int j = region_row*3 ; j < region_row*3+3 ; ++j){
        for (int k = region_col*3 ; k <region_col*3+3 ; ++k){
            counting_arr_box[sudoku[j][k]]+=1;
        }
    }
    for (int i = 1 ; i < 10 ; ++i){
        if (counting_arr_box[i] > 1){
            flag_box = false;
            break;
        }
    }

    std::vector<int> counting_arr_row(10,0);
    bool flag_row = true;
    for (int j = 0 ; j<9 ; ++j){
        counting_arr_row[sudoku[dim][j]]+=1;
    }
    for (int i = 1 ; i < 10 ; ++i){
        if (counting_arr_row[i] > 1){
            flag_row = false;
            break;
        }
    }
    
    std::vector<int> counting_arr_col(10,0);
    bool flag_col = true;
    for (int j = 0 ; j<9 ; ++j){
        counting_arr_col[sudoku[j][idx]]+=1;
    }
    for (int i = 1 ; i < 10 ; ++i){
        if (counting_arr_col[i] > 1){
            flag_col = false;
            break;
        }
    }
    
    //std::cout << flag_box << " " << flag_row << " " << flag_col << "\n";

    if ( flag_box && flag_row && flag_col) {
        return true;
    }
    else
        return false;
}

void sudoku_finder(int dim, std::vector<std::vector<int>>& sudoku){

    if (dim ==9){
        
        return;
    }
    
    for(int i = 0 ; i < 9 ; ++i){
        if (sudoku[dim][i]==0){
            for (int j =0 ; j<9 ; ++j){
                sudoku[dim][i] = j+1;
                if (check_sudoku(dim, i, sudoku)){
                    // std::cout << std::endl << "DEBUG"<<std::endl;
                    // for(auto row: sudoku){
                    //     for(auto col : row)
                    //         std::cout << col << " ";
                    //     std::cout << "\n";
                    // }
                    sudoku_finder(dim, sudoku);
                    break;
                }
                else
                    sudoku[dim][i]=0;
            }
        }
    }
    sudoku_finder(dim+1, sudoku);
}

int main(){
    std::vector<std::vector<int>> sudoku;

    for(int row =0 ; row<9 ; ++row){
        std::vector<int> arr;
        for(int col =0  ; col < 9 ; ++col){
            int n;
            std::cin >> n;
            arr.push_back(n);
        }
        sudoku.push_back(arr);
    }

    sudoku_finder(0,sudoku);
    // Print Answer
    std::cout << std::endl << "ANSWER"<<std::endl;
    for(auto row: sudoku){
        for(auto col : row)
            std::cout << col << " ";
        std::cout << "\n";
    }

    return 0;
}