#include <iostream>
#include <vector>

int main(){

    int n;
    std::cin >> n;
    std::vector<int> counting(8001);

    long int sum =0;
    int max_count =0;
    for(int i = 0 ; i < n ; ++i){
        int a;
        std::cin >> a;
        counting[4000+a] +=1;
        sum += a;

        if (max_count < counting[4000+a]){
            max_count = counting[4000+a];
        }
    }

    // sort: counting_sort simple way
    std::vector<int> ans;
    std::vector<int> freq_cand;
    for (int i =0 ; i < 8001 ; ++i ){

        if (max_count == counting[i]){
            freq_cand.push_back(i-4000);
        }

        while (counting[i]>0){
            ans.push_back ( i - 4000);
            counting[i]-=1;
        }
    }

    // mean using scaling for fixed point
    long int mu = sum * 10 / n;
    if (mu > 0) 
        mu = (mu + 5)/10;
    else
        mu = (mu -5)/10;

    std::cout << mu << "\n";
    
    // meadian value
    std::cout << ans[(n)/2] << "\n";

    // most frequent value
    if (freq_cand.size() == 1)
        std::cout << freq_cand[0] << "\n";
    else
        std::cout << freq_cand[1] << "\n";
    
    // range
    std::cout << ans[n-1] - ans[0] << "\n";

    return 0;
}