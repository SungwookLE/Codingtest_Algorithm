#include <iostream>
#include <algorithm>
#include <vector>


bool compare(std::pair<int, int> a, std::pair<int, int> b){

    if (a.second < b.second)
        return true;

    else if (a.second == b.second){
        if (a.first < b.first)
            return true;
        else
            return false;
    }
    
    else
        return false;
}

int main(){
    int n;
    std::cin >> n;

    std::vector<std::pair<int,int>> list;
    for (int i = 0 ; i < n ; ++i){
        int x,y;
        std::cin >> x >> y;

        list.push_back(std::make_pair(x,y));
    }

    std::sort(list.begin(), list.end(), compare);

    for ( auto a : list)
        std::cout << a.first << " " << a.second << "\n";

    return 0;
}