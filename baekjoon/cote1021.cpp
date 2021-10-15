#include <iostream>
#include <deque>

class solver_1021{
};

int main(){
    int N, M;
    std::cin >> N >> M;

    std::deque<int> circle(N);
    for(int i = 0 ; i < N ; ++i)
        circle[i] = i+1;
    
    std::deque<int> pops(M);
    for(int i = 0; i < M; ++i)
        std::cin >> pops[i];
    
    int case_total = 0;
    while(!pops.empty()){

        int temp = pops.front();
        if (temp == circle.front()){
            pops.pop_front();
            circle.pop_front();
        }
        else{
            int case2=0, case3=0;
            std::deque<int> case2_circle=circle;
            std::deque<int> case3_circle=circle;
            while(temp != case2_circle.front()) {
                case2_circle.push_back(case2_circle.front());
                case2_circle.pop_front();
                case2+=1;
            }
            while(temp != case3_circle.front()) {
                case3_circle.push_front(case3_circle.back());
                case3_circle.pop_back();
                case3+=1;
            }

            if ( case2 < case3 ){
                case_total += case2;
                circle=case2_circle;
            }
            else{
                case_total += case3;    
                circle=case3_circle;
            }

            pops.pop_front();
            circle.pop_front();
        }

    }
    std::cout << case_total << std::endl;

    return 0;
}