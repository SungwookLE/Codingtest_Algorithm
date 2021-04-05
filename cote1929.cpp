#include <iostream>
#include <vector>

int main(){
    int upper, under;
    std::cin >> under >> upper;

    if ((under > upper) || (upper<2))
        return 0;

    std::vector<bool> prime_array(upper-2+1, true);

    for(int i =2 ; (i*i) <= upper ; ++i){

        if (prime_array[i-2] == true){
            for (int j=i*i ; j <= upper ; j+=i){
                prime_array[j-2] = false;
            }
        }
    }

    int idx = 2;
    for(bool num:prime_array){
        if ( (num == true) && (idx>=under)){
            std::cout << idx << "\n";
        }
        idx+=1;
    }
    return 0;
}