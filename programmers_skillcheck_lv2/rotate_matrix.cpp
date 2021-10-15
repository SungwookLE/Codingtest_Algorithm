#include <string>
#include <vector>
#include <iostream>
// https://programmers.co.kr/learn/courses/30/lessons/77485
// 이런 노가다도 이런 노가다가 없는데 패스는 했네?
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    vector<vector<int>> map(rows, vector<int>(columns,0));

    for(int i =1 ; i <= columns ; ++i){
        for(int j = 1 ; j <= rows; ++j){
            map[j-1][i-1] = (j-1)*columns + (i);
        }
    }

    for(int i =0 ; i < queries.size() ; ++i){
        int min_val = 10000;
        std::vector<int> temp;
        int row1 = queries[i][0]-1, col1 = queries[i][1]-1;
        int row2 = queries[i][2]-1, col2 = queries[i][3]-1;


        int key4 = map[row1][col1];
        int key1 = map[row1][col2]; // 상단 오른쪽으로
        temp.push_back(key4);
        temp.push_back(key1);



        for(int p = col2; p > col1; --p){
            map[row1][p] = map[row1][p-1];
            temp.push_back(map[row1][p]);
        }
        map[row1][col1] = key4;

        int key2 = map[row2][col2]; // 우측 아래로
        temp.push_back(key2);

        for(int p = row2; p > row1; --p){
            map[p][col2] = map[p-1][col2];
            temp.push_back(map[p][col2]);
        }    
        map[row1+1][col2] = key1;


        // 하단 왼쪽으로
        int key3 = map[row2][col1];
        temp.push_back(key3);

        for(int p = col1 ; p < col2; ++p){
            map[row2][p] = map[row2][p+1];
            temp.push_back(map[row2][p]);
        }    
        map[row2][col2-1] = key2;


        // 좌측 위로
        for(int p = row1; p < row2; ++p){
            map[p][col1] = map[p+1][col1];
            temp.push_back(map[p][col1]);
        }
        map[row2-1][col1] = key3;



        for(auto g: temp){
            if ( g < min_val)
                min_val = g;
        }
        answer.push_back(min_val);


    }


    
    return answer;
}



int main(){

    vector<int> ans = solution(6, 6, {{2,2,5,4}, {3,3,6,6}, {5,1,6,3}});
    for(auto a : ans)
        std::cout << a <<" ";
    return 0;
}
