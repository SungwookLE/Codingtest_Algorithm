#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> data;
    std::vector<int> rank(n, 0);

    for (int i =0 ; i < n ; ++i){
        int w, h;
        std::cin >> w >>h;
        data.push_back(std::make_pair(w,h));
    }

    for (int  i =0  ; i < n ; ++i){
        for (int j = 0 ; j < n ; ++j){
            if ( i != j){
                if ((data[i].first < data[j].first)  && (data[i].second < data[j].second)  )
                    rank[i]+=1;       
            }
        }
    }

    for(int i =0 ; i < n ; ++i){
        std::cout << rank[i]+1 << " " ;
    }

}
