#include <iostream>
#include <vector>


void quick_sort(std::vector<long int> &arr, int start, int end);

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int n ;
    std::cin >> n;

    std::vector<std::pair<int,std::vector<long int>>> counting(200001);
    
    for (int i = 0 ; i < n ; ++i){
        long int x,y;
        std::cin >> x >> y;
        counting[100000+x].first +=1;
        counting[100000+x].second.push_back(y);
    }

    for (int i =0 ; i < counting.size() ; ++i){
        if (counting[i].second.size() > 1)
            quick_sort(counting[i].second, 0, (counting[i].second.size()-1));
        while ( counting[i].first > 0) {
            std::cout << i-100000 << " " << counting[i].second.back() << std::endl;
            counting[i].second.pop_back();
            counting[i].first-=1;
        }
    }   
    return 0;
}

void quick_sort(std::vector<long int> &arr, int start, int end){

    if (start >= end)
        return;
    
    int pivot = start;
    int i = pivot+1;
    int j = end;

    while ( i <= j){

        while( (i <= end) && (arr[pivot] <= arr[i] )   )
            i +=1;
        while ( (j > start) && ( arr[pivot] >= arr[j]) )
            j -=1;

        if ( i > j){
            int temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        }
        else{
            int temp = arr[i];
            arr[i] =arr[j];
            arr[j] = temp;
        }
    }

    quick_sort(arr, start, j-1);
    quick_sort(arr, j+1, end);

    return;
}
