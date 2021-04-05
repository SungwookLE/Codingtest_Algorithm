#include <iostream>

int main(){
    //std::cin.tie(NULL);
    //std::ios_base::sync_with_stdio(false);

    int A[10] = {0,};
    
    for(int i =0; i <10 ; ++i){
        std::cin >> A[i];
        A[i] = A[i]%42;
    }
  

    int count=0;
    int d_count[10] ={0,};

    for (int i=0; i < 10 ; ++i){
            
        d_count[i] =0;
        for (int j=0; j < 10 ; ++j){
            if (A[i]!=A[j])
                count+=1;
            else
                d_count[i] +=1;
        }
    }

    float ans_count =0;
    for (int i=0 ; i <10 ; ++i){
        
        ans_count += (float)1 / (d_count[i]);
        
    }

    std::cout << (int)ans_count << std::endl;

    return 0;
}