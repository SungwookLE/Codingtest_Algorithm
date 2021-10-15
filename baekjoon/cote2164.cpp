#include <iostream>
#include <queue>

// #2164, 카드2

int main(){

    int N;
    std::cin >> N; 
    std::queue<int> card;

    for(int i  = 1 ; i <= N ; ++i)
        card.push(i);
    
    while( card.size() != 1){

        card.pop();
        card.push(card.front());
        card.pop();


    }

    std::cout << card.back() << std::endl;

    return 0;
}