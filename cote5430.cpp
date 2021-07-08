#include <deque>
#include <iostream>
#include <algorithm>
#include <sstream>

class solver_5430{};

int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    std::string func,arr;
    int n;

    for(int i =0 ; i < T ; ++i){
        std::cin >> func;
        std::cin >> n;

        std::cin >> arr;
        std::replace(arr.begin(), arr.end(), '[', ' ');
        std::replace(arr.begin(), arr.end(), ']', ' ');
        std::replace(arr.begin(), arr.end(), ',', ' ');

        std::deque<int> arr_deque(n);
            
        std::istringstream linestream(arr);
        for(int j=0; j < n ; ++j)
            linestream >> arr_deque[j];
        
        bool flag=true;
        bool reverse_flag =false;
        for(int k=0; k < func.size() ; ++k){
            if (func[k]=='R')
                reverse_flag = !reverse_flag;
            // 원래는 std::reverse(arr.begin(), arr.end()) 를 썼는데, 시간초과가 자꾸나서 바꿨더니 통과

            else if (func[k] =='D'){
                if (!arr_deque.empty()){
                    if (reverse_flag == false)
                        arr_deque.pop_front();
                    else
                        arr_deque.pop_back();
                }
                else{
                    flag=false;
                    break;
                }
            }
        }

        if (flag==true){
            std::cout << '[';
            if (!arr_deque.empty()){
                if (reverse_flag == false){
                    for(int p =0 ; p < (arr_deque.size()-1) ; ++p)
                        std::cout << arr_deque[p] << ','; 
                    std::cout << arr_deque.back(); 
                }
                else{
                    for(int p =arr_deque.size()-1 ; p >= 1 ; --p)
                        std::cout << arr_deque[p] << ','; 
                    std::cout << arr_deque.front(); 
                }
            }
            std::cout << "]\n";
        }
        else
            std::cout << "error\n";
    }

    return 0;
}