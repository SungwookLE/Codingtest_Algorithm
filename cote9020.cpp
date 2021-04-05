#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    for (int i =0 ; i<n ; ++i){
        int num;
        std::cin >> num;

        if (( num > 2 ) && (num%2==0)){
            std::vector<bool> prime_arr(num-2+1, true);
            std::vector<int> prime_list;

            for(int i =2 ; i*i <= num ; ++i){
                if ( prime_arr[i-2] ==true){
                    for (int j = i*i ; j <= num ; j+=i)
                        prime_arr[j-2] = false;
                }
            }
            int idx =2;
            for (bool data: prime_arr){
                if (data == true){
                    prime_list.push_back(idx);
                }    
                idx+=1;
            }

            int start=prime_list.size()-1;
            int move_idx = start;
            int sum_val = prime_list[start] + prime_list[move_idx] ;

            while (sum_val != num){
                move_idx +=1;

                if (move_idx > (prime_list.size()-1)){
                    start-=1;
                    move_idx = start;
                }

                sum_val = prime_list[start] + prime_list[move_idx] ;

                if (start < 0){
                    std::cout << "FAIL";
                    break;
                }    
            }
            
            std::cout << prime_list[start] << " " << prime_list[move_idx]<<"\n";

        }
    }
    return 0;
}