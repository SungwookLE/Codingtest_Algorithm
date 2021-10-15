#include <iostream>
#include <vector>

void find_answer(std::vector<long long>& answer, int N){

    long long tmp;

    for(int i = 3; i <= N ; ++i){
        tmp = 0;
        tmp = answer[i-1] + answer[i-2];
        answer.push_back(tmp%15746);
    }
}

int main(){
    int N;
    std::cin >> N;

    std::vector<long long> answer = {0,1,2};

    find_answer(answer, N);
    std::cout << answer[N] << std::endl;

    return 0;
}