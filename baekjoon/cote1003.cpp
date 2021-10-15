#include <iostream>
#include <vector>
// 1003번 동적계획법? 

int fibonacci_ea(int n, std::vector<int>& ans) {
    if (n == 0) {
        ans[0] +=1;
        return 0;
    } else if (n == 1) {
        ans[1] +=1;
        return 1;
    } else {
        return fibonacci_ea(n-1, ans) + fibonacci_ea(n-2, ans);
    }
}



int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    //Dynamic Programming: 이름이 이거인거지, 다 구해놓는것
    std::vector<std::vector<int>> dp(41, {0,0});
    
    dp[0]= {1,0};
    dp[1]= {0,1};

    for(int i = 2 ; i < 41 ; ++i){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }

    int n;
    std::cin >> n;

    for(int i = 0 ; i < n ; ++i){
        int num;
        std::cin >> num;
        std::cout << dp[num][0] << " " << dp[num][1]  << "\n";
    }
    
    return 0;
}