#include <iostream>
#include <vector>


int main(){
    std::vector<std::vector<char>> alphabet={
        {'A','B','C'}, {'D','E','F'}, {'G','H','I'}
      , {'J','K','L'}, {'M','N','O'}, {'P','Q','R','S'}
      , {'T','U','V'}, {'W','X','Y','Z'}
    };

    std::string line;
    std::cin >> line;

    int number;
    int consume=0;

    for (int j = 0 ; j < line.length() ; ++j){
        number=2;        
        for(auto tray: alphabet){
            for(int i=0; i < tray.size() ; ++i){
                if (line[j] == tray[i])
                    consume += 2+(number-1);
            }
            number+=1;
        }
    }

    std::cout << consume;
    return 0;
}