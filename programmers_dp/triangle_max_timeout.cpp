#include <string>
#include <vector>
#include <iostream>

using namespace std;

class solver{
  public:
    solver(vector<vector<int>> triangle_): triangle(triangle_) {height = triangle.size(); }
    
    void dp(int iter, vector<int> path, int last_col, int sum, int& answer){
        if (iter == height){
            path_all.push_back(path);
            if (sum > answer)
                answer = sum;
        }
        else{
            
            for(int col =0 ; col < triangle[iter].size() ; ++col){
                if ( col >=last_col && col <= last_col+1){
                    path.push_back(triangle[iter][col]);
                    sum += triangle[iter][col];
                    dp(iter+1, path, col, sum, answer);
                    sum -= triangle[iter][col];
                    path.pop_back();
                }
            }
        }
    }
    
    void debug(){
        for(auto p : path_all){
            for(auto a : p)
                cout << a << " " ;
            cout << endl ;
        }
    }
  
    
  private:
    vector<vector<int>> triangle;
    vector<vector<int>> path_all;
    int height;
    
};

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    solver solve(triangle);
    int iter =0;
    int last_col=0;
    int sum =0;  
    vector<int> path;
    
    solve.dp(iter, path, last_col, sum, answer);
    //answer = solve.get_answer();
    //solve.debug();
    
    return answer;
}