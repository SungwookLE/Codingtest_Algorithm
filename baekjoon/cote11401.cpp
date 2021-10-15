#include <iostream>
#include <vector>

// REF: 페르마의 소정리 (https://okayoki2484.tistory.com/129)

class solver_11401{
public:
void insert(){
    std::cin >> N >> K;
}


// 페르마의 소정리는 모른다고 해도, w제곱을 아래와 같이 하면 안티오버플로우 처리하면서 계산할 수 있곘네,,,(7/14)
long long int power(long long int a, long long int b){
    long long int result =1;
    while(b>0){
        if ( b%2 != 0){
            result = (result*a) % mod;
        }
        a = (a*a)%mod;
        b/=2;
    }
    return result;
}


long long int comb(){

    long long int facn = 1;
    long long int other = 1;

    // n!의 modulo 연산 결과 facn에 저장
    for (long long int i =1 ; i <=N ; i++){
        facn = (facn*i)%mod;
    }

    // k!의 modulo 연산 결과 other에 저장
    for (long long int i = 1; i <=K; i++){
        other = (other*i) % mod;
    }

    // (n-k)!의 modulo 연산 결과 other에 누적 저장
    for (long long int i = 1; i <= (N-K); i++){
        other = (other*i)%mod;
    }

    // n! * (k!(n-k)!) ^ mod-2 의 modulo 연산 결과 리턴
    return (facn*power(other, mod-2))%mod;
}


private:
long long int N, K;
long long int mod = 1000000007;

};

int main(){

    solver_11401 solver;
    solver.insert();
    std::cout << solver.comb()<<std::endl;


    return 0;
}