#include <iostream>
#include <vector>
#include <algorithm>
bool compare(std::pair<std::pair<int, std::string>, int> a, std::pair<std::pair<int, std::string>, int> b){

    if ( a.first.first < b.first.first)
        return true;
    else if ( a.first.first == b.first.first){
        if ( a.second < b.second)
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


    std::vector<std::pair<std::pair<int, std::string>, int>> list;
    for(int i =0; i < n ; ++i){
        int age;
        std::string name;
        std::cin >> age >> name;
        list.push_back(std::make_pair(std::make_pair(age, name), i));
    }

    std::sort(list.begin(), list.end(), compare);

    for (auto a : list)
        std::cout << a.first.first << " " << a.first.second << "\n";

    return 0;
}