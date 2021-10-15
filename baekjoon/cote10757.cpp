#include <iostream>
#include <vector>


int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::string A,B;
    std::cin >> A >> B;

    int leng=std::max(A.length()+1,B.length()+1);

    std::vector<int> A_arr(leng), B_arr(leng);

    int idx=0;
    for(int i = (A.length()-1) ; i >= 0 ; -- i){
        int res =A[i]-'0';
        A_arr[idx]=res;
        idx+=1;
    }

    idx=0;
    for(int i = (B.length()-1) ; i >= 0 ; -- i){
        int res =B[i]-'0';
        B_arr[idx]=res;
        idx+=1;
    }

    std::vector<int> Sum_arr;

    for(int i =0 ; i<leng ; ++i ){
        int res = A_arr[i] + B_arr[i];
        int num, den;
        if (res >= 10){
            num = res/10;
            den = res%10;
            A_arr[i+1] += num;
        }
        else{
            den = res;
        }
        Sum_arr.push_back(den);
    }

    for(int i = (Sum_arr.size()-1); i >=0 ; --i){
        if ( i == (Sum_arr.size()-1)){
            if (Sum_arr[i] != 0)
                std::cout << Sum_arr[i] ;
        }
        else
            std::cout << Sum_arr[i] ;
    }

    return 0;
}