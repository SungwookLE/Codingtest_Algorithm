#include <iostream>
#include <vector>
#include <algorithm>

/*
REF: https://hwan-shell.tistory.com/299
('21.5/23) 하 일반화 점화식 유도가 어렵네 ㅠ 

문제>>
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력>>
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력>>
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

예제 입력 1>> 
6
10 20 10 30 20 50
예제 출력 1>>
4

고찰>>
동적계획법으로 푸는 문제인데, 동적계획법이 특별한게 아니고,
어떤 문제를 풀때 스텝스텝마다 아래서부터 풀어나가서 끝을 푸는 
방식을 동적프로그래밍이라고 부름

바로 코딩을 하는거 보단, 점화식(일반화식)을 유도해서 풀어야지만,
동적프로그래밍으로 문제를 풀 수 있고, 아래 문제는 점화식 까지는 아니지만,
어떤 조건에 만족하면 +1을 하고, 아니면 0을 넣는것도 일반화 식이라고 볼 수 있겠지

아래를 눈여겨 보며 익히자, 많은 DP문제를 풀려고하니까 계속 해답지만 찾게되네
*/


int main(){

    int T;
    int N, M, K, H;
    int X, Y;
    int answer = 0;

    std::vector<int> v;
    std::cin >> T;
    int dp[T];

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

    for (auto element : dp)
        std::cout << element << " ";
    std::cout << std::endl;


    std::cout << answer << std::endl;

    return 0;
}

