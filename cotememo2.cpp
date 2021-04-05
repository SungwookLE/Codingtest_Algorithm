#include <iostream>
#include <vector>

int d(std::string n){
    int ans= std::stoi(n);

    std::vector<int> data(n.length());

    for(int i =0 ; i < n.length() ; ++i){
        data[i] = n[i]-'0';
        ans += data[i];

    }
    return ans;
}

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    std::vector<bool> tray(10001,false);
    int i = 1;
    int ans;

    while ( i< 10000 ){
        ans = d(std::to_string(i));
        tray[ans] = true;
        i+=1;
    }


    for(int i = 1 ; i < tray.size(); ++i){
        if (tray[i] != true )
            std::cout << i << std::endl;
    }

    return 0;
}
