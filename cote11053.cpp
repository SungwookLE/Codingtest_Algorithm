#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int T;
    int N, M, K, H;
    int X, Y;
    int answer = 0;

    int dp[1001];
    std::vector<int> v;
    std::cin >> T;

    for (int i = 0 ; i < T; ++i){
        std::cin >> K;
        v.push_back(K);

        int dp_max = 0;
        for(int j = 0 ; j < v.size() ; ++j){
            if (v[i] > v[j]){
                if (dp_max < dp[j])
                    dp_max = dp[j];
            }
        }

        dp[i] = dp_max + 1;
        answer = std::max(answer, dp[i]);

    }

    std::cout << answer << std::endl;



    return 0;
}


// REF: https://hwan-shell.tistory.com/299
// ('21.5/23) 하 일반화 점화식 유도가 어렵네 ㅠ 
