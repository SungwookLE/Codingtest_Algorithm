#include <iostream>
#include <vector>

void quick_sort(std::vector<std::pair<long int,long int>> &arr , int start_idx, int end_idx);

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    int n ;
    std::cin >> n;
    std::vector<std::pair<long int, long int>> list;
    for (int i = 0 ; i < n ; ++i){
        long int x,y;
        std::cin >> x >> y;
        list.push_back(std::make_pair(x,y));
    }

    
   
    quick_sort (list, 0, (list.size()-1));

    for (auto a : list)
        std::cout << a.first << " " << a.second << "\n";
    
    return 0;
}

void quick_sort(std::vector<std::pair<long int,long int>> &arr , int start_idx, int end_idx){
    if ( end_idx <= start_idx) 
        return;  // if element is one, recursion exits
    static int k = 0;
    int pivot = start_idx;
    int i = pivot+1;
    int j = end_idx;
    
    while ( i <= j){
        k+=1;
        auto compare_i = [](std::vector<std::pair<long int,long int>> arr, int i,int pivot)->bool{
            if (arr[i].first <= arr[pivot].first){
                if ( arr[i].first == arr[pivot].first){
                    if ( arr[i].second < arr[pivot].second)
                        return true;
                    else
                        return false;
                    }
                else
                    return true;
            }    
            else
                return false;
        };
        auto compare_j = [](std::vector<std::pair<long int,long int>> arr, int j,int pivot){
            if (arr[j].first >= arr[pivot].first){
                if ( arr[j].first == arr[pivot].first){
                    if ( arr[j].second > arr[pivot].second)
                        return true;
                    else
                        return false;
                    }
                else
                    return true;
            }
            else
                return false;
        };

        if ( k > 1000)
            break;

        while (( i <= end_idx) && compare_i(arr, i,pivot) )
            i +=1;
        while ((j > start_idx) && compare_j(arr, j,pivot) )
            j -=1;

        if ( i <= j ){
            std::pair<long int,long int> temp = arr[i];
            arr[i]= arr[j];
            arr[j]= temp;
        }
        else{
            std::pair<long int,long int> temp = arr[j];
            arr[j] =arr[pivot];
            arr[pivot] = temp;
        }
    }

    quick_sort(arr, start_idx, j-1);
    quick_sort(arr, j+1, end_idx);
 
    return;
}