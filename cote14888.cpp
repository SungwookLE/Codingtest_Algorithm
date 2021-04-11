#include <iostream>
#include <vector>
#include <algorithm>

void DFS(int total, int& level, long int &cal_val, std::vector<long int > number, std::vector<int>&operate, int idx, std::vector<long int > &answer){
    

    if( number.size() == idx+1 ){
        //std::cout << "TEMP: " << cal_val << std::endl;
        level+=1;
        answer.push_back(cal_val);
        if (total == level){
            std::sort(answer.begin(), answer.end(), [](auto a, auto b){ if (a<b) return true; else return false;});
            std::cout << answer.back() << "\n" << answer[0]<< "\n";
            exit(0);
            return;
        }
        return;
    }
    
    long int  prev_num = cal_val;
    int i = idx+1;

    //for(int i = (idx+1) ; i < number.size(); ++i){
        for(int j =0 ; j < operate.size() ; ++j)
            if (operate[j] > 0){
                operate[j]-=1;
                
                switch(j){
                    case(0):
                        prev_num += number[i];
                        break;
                        
                    case(1):
                        prev_num -= number[i];
                        break;

                    case(2):
                        prev_num *= number[i];
                        break;

                    case(3):
                        prev_num /= number[i];
                        break;

                }
                
                cal_val = prev_num;
                //std::cout << "DEBUG: " << cal_val << std::endl;
                DFS(total, level, cal_val, number, operate, idx+1,answer);
                operate[j]+=1;

                switch(j){
                    case(0):
                        prev_num -= number[i];
                        break;

                    case(1):
                        prev_num += number[i];
                        break;

                    case(2):
                        prev_num /= number[i];
                        break;

                    case(3):
                        prev_num *= number[i];
                        break;
                }
            }
    //}
    return;
}


int main(){
    int n;
    std::cin >> n;

    std::vector<long int > number(n);
    for(int i =0 ; i < n ; ++i)
        std::cin >> number[i];
    std::vector<int> operate(4);
    int sum=0;
    int den=1;
    for(int i =0 ; i < 4 ; ++i){
        std::cin >> operate[i];
        sum+=operate[i];
        if (operate[i] > 1)
            den *= operate[i];
    }
    int total_cnt = 1;
    for (int i =1 ; i <= sum ; ++i)
        total_cnt*= i;
    total_cnt /= den;

    //std::cout << "COUNT: " << total_cnt << std::endl;
    //backtracking
    long int cal_val=number[0];
    int level =0;
    std::vector<long int> answer ; 
    DFS(total_cnt, level, cal_val, number, operate, 0, answer);

    return 0;
}