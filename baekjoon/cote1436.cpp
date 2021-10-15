#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    int count =0;
    int start = 0;

    while ( n != count){

            start += 1;
            std::string num = std::to_string(start);
            int six_count = 0;
            int six_hold =0;
            for(int j = 0 ; j < num.length(); ++j){
                if ((num[j]) =='6'){
                    if ((six_hold == 1) || (j==0) )
                        six_count +=1;
                    else
                        six_count =1;

                    six_hold = 1;
                }
                else{
                    six_hold =0;
                    six_count = 0;
                }

                if (six_count >= 3){
                    count += 1;
                    break; 
                }
            }

    }
    std::cout << start << std::endl;



    
    return 0;
}