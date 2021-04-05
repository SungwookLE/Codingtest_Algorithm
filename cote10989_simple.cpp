#include <vector> 
#include <cstdio>

int main(){

    int N;
    scanf("%d",&N);

    std::vector<int> counting(10001,0);

    for(int i =0 ; i < N ; ++i){
        int a ;
        scanf("%d",&a);
        counting[a]+=1;
    }
    //여기서 비효율이 발생가능함 counting 배열이 굳이 0인데도 다 훓고 지나가야함    
    for (int i = 0 ; i <= 10001 ; ++i){
        while (counting[i] > 0){
            printf("%d\n", i);
            counting[i] -= 1;
        }
    }


    return 0;
}