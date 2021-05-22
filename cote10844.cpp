#include <iostream>
#include <vector>

int main(){



    /*
    다이나믹 프로그래밍이 앞에서 부터 채워나가는 형태의 답찾기 형태를 말하는 거거든,
    그래서 점화식(일반화된) 형태를 찾아서 연쇄법칙으로 답을 찾는 식을 유도해서 채워나가야함
    REF: https://giantpark197cm.tistory.com/245


    #10844 : DP 점화식 유도를 해야하네
    >> 45656이란 수를 보자.
    이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.
    
    세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

    N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오.
    (0으로 시작하는 수는 없다.)
    
    입력>> 첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

    출력>> 첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.
    */

    int n;
    std::cin >> n;

    std::vector<int> res(10,0);
    std::vector<std::vector<int>> DP(101,res);


    for(int i = 1; i < 10 ; ++i)
        DP[1][i] = 1;

    for(int i=2; i<=n ; ++i){
        DP[i][0] = DP[i-1][1];
        DP[i][9] = DP[i-1][8];

        for (int j = 1; j < 9 ; ++j)
            DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1])%1000000000;
            
    }

    int sum =0;
    for(int i =0 ; i<=9; ++i){
        sum+= DP[n][i];
        sum %= 1000000000;
    }

    std::cout << sum << std::endl;


    return 0;
}