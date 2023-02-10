/**
 * @file cote9251_LCS_withDP.cpp
 * @brief Longest Common Subsequence 를 찾는 백준 문제(#9251), Dynamic Programming
 * @date 2023-02-10
 */


#include <iostream>
#include <vector>

using namespace std;

class solver_LTS{
    public:

    solver_LTS(string _str1, string _str2): str1(_str1), str2(_str2){
        DP = vector<vector<int>>(str1.length()+1, vector<int>(str2.length()+1, 0));
    }

    int solve(){

        for(int i = 1 ; i <= str1.length(); ++i){
            for(int j =1 ; j <=str2.length(); ++j){

                if(str1[i-1] == str2[j-1]){
                    DP[i][j] = DP[i-1][j-1]+1;
                }
                else{
                    DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
                }
            }
        }

        return DP[str1.length()][str2.length()];
    }



    private:
    string str1, str2;
    vector<vector<int>> DP;


};

int main(){

    string str1, str2;
    cin >> str1 >> str2;

    solver_LTS solver(str1, str2);
    cout << solver.solve() << endl;



    return 0;
}