#include <iostream>

#define summ(n) (double)1.0/2.0*n*(n+1)

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;

    for (int i =0 ; i < n ; ++i){

        int s, e;
        std::cin >> s >> e ;

        int dist = e - s ;
        int count =0;
        int step_size;

        while (dist != 0 ){
            if (count ==0)
                step_size =1;
            else if (dist == 1)
                step_size =1;
            else if (dist > summ(dist/2)+1)
                step_size +=1;
            else if (dist == summ(dist/2)+1)
                step_size = step_size;
            else
                step_size-=1;

            if (step_size <= 0 )
                break;

            dist -= step_size;
            count +=1;

        }
        std::cout << count << "\n";
    }

    return 0;
}