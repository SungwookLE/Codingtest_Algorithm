#include <iostream>
#include <vector>


int main(){
    std::vector<std::vector<int>> pts;


    for(int i =0 ; i<3 ; ++i){
        int x, y;
        std::cin >> x >> y;
        std::vector<int> res_pt = {x, y};
        pts.push_back(res_pt);
    }

    std::vector<std::vector<int>> x_pt, y_pt;
    for(int i = 0; i < pts.size(); ++i){
        int count_x =0, count_y=0;
        for(int j =0 ; j < pts.size(); ++j){
            if (pts[i][0] == pts[j][0])
                count_x+=1;
                   
                
            if (pts[i][1] == pts[j][1])
                count_y+=1;
        }
        x_pt.push_back({pts[i][0], count_x});
        y_pt.push_back({pts[i][1], count_y});
    }

    for (auto data : x_pt){
        if (data[1] == 1)
            std::cout << data[0] <<" ";
    }

    for (auto data: y_pt){
        if (data[1] == 1)
            std::cout << data[0] ;
    }
    
    return 0;
}