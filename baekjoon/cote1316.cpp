#include <iostream>
#include <vector>

int main(){
    int n;

    std::cin >> n;

    std::vector<char> alphabet = {
        'a','b','c','d','e','f','g',
        'h','i','j','k','l','m','n',
        'o','p','q','r','s','t','u',
        'v','w','x','y','z'
    };

    int ans =0;
    bool flag ;
    bool conti;

    for(int i =0 ; i < n ; ++i){
        std::string line;
        std::cin >> line;

        flag = true;
        std::vector<char> tray = {
        'a','b','c','d','e','f','g',
        'h','i','j','k','l','m','n',
        'o','p','q','r','s','t','u',
        'v','w','x','y','z'
        };

        for(int j=  0 ; j < line.length() ; ++j){
            for(int k = 0 ; k < alphabet.size() ; ++k){
                if (line[j] == alphabet[k]){
                    if (tray[k] == '+'){
                        if (line[j] != line[j-1])
                            tray[k] = '*';
                    }
                    else
                        tray[k] = '+';
                }
            }
        }

        for(auto msg : tray){
            if (msg == '*')
                flag = false;
            else{
                if (flag == false)
                    flag = false;
                else
                    flag = true;
            }
        }
        if (flag == true)
            ans+=1;
    }
    std::cout << ans ;

    return 0;
}