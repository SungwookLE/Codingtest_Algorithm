#include <iostream>
#include <vector>

void print_star(int n, std::vector<std::vector<char>>& basis){
    std::vector<std::vector<char>> star_map;
    int code;

    if ( n == 3 ){
        basis = { {'*','*','*'} , {'*',' ','*'}, {'*','*','*'}};
        for (int row =0 ; row < n ; ++row){
            std::vector<char> array;
            for(int col =0 ; col < n/3 ; ++col)
                array.insert(array.end(), basis[row%3].begin(), basis[row%3].end());

            star_map.push_back(array);

            if ((row >= n/3) && ( row < (2*n/3) )){
                for(int col = n/3 ; col < (2*n/3); ++col)
                    star_map[row][col] = ' ';
            }
        }
        basis = star_map;
    }
    else if ( n > 3){
        for (int row =0 ; row < n ; ++row){
            std::vector<char> array;
            for(int col =0 ; col < 3 ; ++col)
                array.insert(array.end(), basis[row%(n/3)].begin(), basis[row%(n/3)].end());

            star_map.push_back(array);

            if ((row >= n/3) && ( row < (2*n/3) )){
                for(int col = n/3 ; col < (2*n/3); ++col)
                    star_map[row][col] = ' ';
            }
        }
        basis = star_map;
    }
    
    return;
}

int main(){
    int n ;
    std::cin >> n;

    std::vector<std::vector<char>> ans;

    int idx = 3;
    while (idx <= n ){
        print_star(idx, ans);
        idx *=3;
    }
    for (auto row : ans){
            for (auto pt : row){
                std::cout << pt ;
            }
            std::cout << "\n";
    }
    return 0;
}