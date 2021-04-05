#include <iostream>
#include <vector>


void quick_sort(std::vector<std::string> &list, int start, int end);

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<std::string> list;
    for(int i =0 ; i < n ; ++i){
        std::string line;
        std::cin >> line;

        bool check = false;
        for( auto msg : list){
            if (msg == line){
                check = true;
                break;
            }
        }

        if (check == false)
            list.push_back(line);
    }

    quick_sort(list, 0, (list.size()-1));

    for(auto a : list)
        std::cout << a << "\n";

    return 0;
}

void quick_sort(std::vector<std::string> &list, int start, int end){

    if (start >= end)
        return;

    int pivot = start;
    int i = pivot+1;
    int j = end;

    while ( i <= j){

        auto compare_i = [](std::vector<std::string> arr, int i,int pivot){

            if (arr[i].length() <= arr[pivot].length() ){
                if ( arr[i].length() == arr[pivot].length()){

                    int int_i, int_pivot;
                    for (int idx =0 ; idx < arr[i].length() ; ++idx){
                        int_i= arr[i][idx];
                        int_pivot = arr[pivot][idx];

                        if (int_i != int_pivot)
                            break;
                    }
                    if (int_i > int_pivot){   
                        return false;
                    }    
                    else
                        return true;
                }
                else
                    return true;
            }
            else
                return false;
        };

        auto compare_j = [](std::vector<std::string> arr, int j,int pivot){

            if (arr[j].length() >= arr[pivot].length() ){
                if ( arr[j].length() == arr[pivot].length()){

                    int int_j, int_pivot;
                    for (int idx =0 ; idx < arr[j].length() ; ++idx){
                        int_j= arr[j][idx];
                        int_pivot = arr[pivot][idx];

                        if (int_j != int_pivot)
                            break;
                    }
                    if (int_j < int_pivot){
                        return false;
                    }
                    else
                        return true;
                }
                else
                    return true;
            }
            else
                return false;
        };


        while ((i <= end) && (compare_i(list, i, pivot)) )
            i+=1;
        
        while ((j>start) && (compare_j(list, j, pivot)) )
            j-=1;

        if ( i <= j ){
            auto temp = list[j];
            list[j] = list[i];
            list[i] = temp;
            
        }

        else{
            auto temp = list[j];
            list[j] = list[pivot];
            list[pivot] = temp;
        }
    }

    quick_sort(list, start, j-1);
    quick_sort(list, j+1, end);

    return;
}


