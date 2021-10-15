#include <iostream>
#include <vector>

// #2579

int main(){
    int N;
    std::cin >> N;

    std::vector<int> step(N+1);
    std::vector<int> sum(N+1);

    for(int i=1; i <= N; ++i)
        std::cin >> step[i];

    sum[1] = step[1];
    sum[2] = step[1] + step[2];
    sum[3] = std::max(step[1] + step[3] , step[2] +step[3]);

    for(int i =4 ; i <= N; ++i)
        sum[i] = std::max(sum[i-2]+step[i], sum[i-3]+step[i-1]+step[i]);
    std::cout << sum[N] << std::endl;

    return 0;
}

// 아 이런게 점화식 문제인데, 이런거 풀기가 힘드네용,, (210503)