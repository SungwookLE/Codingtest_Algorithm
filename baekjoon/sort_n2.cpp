#include <iostream>
#include <vector>

// full_search_sort: n^2

int main(){
    std::vector<std::vector<int>> data;
    int n;
    std::cin >> n;
    
    for (int i = 0 ; i < n ; ++i){
        int w, h ;
        std::cin >> w >> h;
        data.push_back({w,h, i+1, 0});
    }
   
    for(int i = 0 ; i < data.size() ; ++i){
        for ( int j = i+1 ; j < data.size() ; ++j){
            if((data[i][0] < data[j][0]) && (data[i][1] < data[j][1])){
                int w_temp=data[i][0], h_temp=data[i][1], idx_temp = data[i][2];
                data[i][0] = data[j][0];
                data[i][1] = data[j][1];
                data[i][2] = data[j][2];
                data[i][3] = 1;

                data[j][0]=w_temp;
                data[j][1]=h_temp;
                data[j][2]=idx_temp;
            }
        }
    }

    std::cout << std::endl << "SORTING DONE." << std::endl;
    for (auto dat : data)
        std::cout << "ID: " << dat[2] <<", W: " << dat[0] << ", H: " << dat[1] << std::endl;

    return 0;
}