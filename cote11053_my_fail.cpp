#include <iostream>
#include <vector> 
/*
    #11053: 동적계획법
    문제>>
    수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
    예를 들어, 수열 A = {10,20,10,30,20,50}인 경우에 가장 긴 증가하는
    부분 수열은 A = {10, 20, 30, 50} 이고 길이는 4이다.

    입력>>
    첫째 줄에 수열 A의 크기 N (1<= N <= 1000)이 주어지고,
    둘째 줄에는 수열 A를 이루고 있는 A_ele가 주어진다.

    출력>>
    첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다. 
    */

   /*
    SOLVE>>
    점화식 유도를 해보자

    ex)
    A = {10,20,10,30,20,50}
    DP[0][0] = 10
    DP[1][0] = 20
    DP[2][0] = 10
    DP[3][0] = 30
    DP[4][0] = 20
    DP[5][0] = 50
    // DP[A 의 원소 순서][쌓인 인덱스]
    
    
    if (A[1] > A[0])
        DP[0][1] = A[0], A[1]
    else
        DP[0][1] = DP[0][0]

    if (A[2] > A[1])
        DP[1][1] = A[1], A[2]
    else
        DP[1][1] = DP[1][0]

    if (A[3] > A[2])
        DP[2][1] = A[2], A[3]
    else
        DP[2][1] = DP[2][0]
    */

int main(){

    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0 ; i < N ; ++i)
        std::cin>>A[i];

    std::vector<int> res(N,-1);
    std::vector<std::vector<int>> DP(N,res);

    for (int i =0 ; i < N; ++i)
        DP[i][0]=A[i];
    
    for (int idx = 1 ; idx < N ; ++idx){
        for (int j = 0; j < N ; ++j){
            if (idx+j < N){
                int k = idx-1;
                while (DP[j][k] == -1){
                    k-=1;
                }
                if ( A[idx+j] > DP[j][k])
                    DP[j][idx]=A[idx+j];
            }
        }

    }

    std::cout <<"DEBUG: \n";
    for (auto row: DP){
        for (auto col : row)
            std::cout << col << " ";
        std::cout << std::endl;
    }

    int max_count = 0, count;
    for (auto row: DP){
        count = 0;
        for (auto col: row){
            if (col != -1)
                count +=1;
        }
        if (max_count < count)
            max_count = count;
    }

    std::cout << max_count << std::endl;
    return 0;
}