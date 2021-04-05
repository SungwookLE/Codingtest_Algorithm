#include <iostream>
#include <vector>

int han_soo(int n){
    int count =0;

    while(n >= 1){
        std::string k = std::to_string(n);
        std::vector<int> data(k.length());
        bool flag = true;
       
        for(int i =0 ; i<k.length(); ++i){
            data[i] = k[i] - '0';
        }

        if (k.length() <= 1){
            count +=1;
        }
        else{
            int diff = data[0]-data[1];
            for(int i =1 ; i<(data.size()-1) ; ++i){
                if ((diff == (data[i] - data[i+1])) && (flag == true)){
                    diff = data[i] - data[i+1];
                }
                else{
                    flag = false;
                }
            }

            if (flag == true)
                count +=1;

        }
        n-=1;
    }


    return count;
}

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n,ans;
    std::cin >> n;
    
    ans = han_soo(n);
    std::cout << ans << "\n";

    return 0;
}
