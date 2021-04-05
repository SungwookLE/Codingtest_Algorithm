#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<std::string> list;
    for(int i =0 ; i < n ; ++i){
        std::string line;
        std::cin >> line;

        list.push_back(line);
    }

    auto compare = [](std::string a, std::string b){
        if ( a.length()<b.length() )
            return true;
        else if (a.length() == b.length()){
            int int_a, int_b;
            for(int i = 0 ; i < a.length() ; ++i){
                int_a = a[i];
                int_b = b[i];
                if (int_a != int_b)
                    break;
            }
            if (int_a < int_b)
                return true;
            else
                return false;
        }
        else
            return false;
    };
    std::sort(list.begin(), list.end(), compare);
    list.erase(std::unique(list.begin(), list.end()), list.end());

    for(auto a : list)
        std::cout << a << "\n";

    return 0;
}