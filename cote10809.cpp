#include <iostream>
#include <vector>

// CODING TEST #10809, In my thought, That code is correct, but it returns fail.. (3/11)

int main(){
  // std::cin.tie(NULL);
   // std::ios_base::sync_with_stdio(false);

    char A[101]={0,};
    std::cin.getline(A,101);

    std::vector<int> tray 
                    = {'a', 'b', 'c', 'd' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j','k' ,'l' ,'m' ,'n' ,'o', 'p', 'q' ,'r', 's' ,'t', 'u' ,'v' ,'w' ,'x', 'y','z'};

    for(int i =0 ; i<101 ; ++i){
        for (int j =0 ;  j < tray.size() ;  ++ j){
            if (int(A[i]) ==  tray[j]){
                if ( A[i] != '\0'){
                    tray[j] = i;
                }
            }
        }
    }

    for(int j = 0 ; j < tray.size(); ++j){
        if (tray[j] >= int('a')){
            tray[j] = -1;
        }
        
        std::cout << tray[j] << " " ;
    }
   
    return 0;
}
