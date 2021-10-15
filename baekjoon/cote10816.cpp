#include <iostream>
#include <vector>
#include <algorithm>


class solver_10816{
    public:
    solver_10816(std::vector<int> _card1, std::vector<int> _card2){

        card1 = _card1;
        card2 = _card2;
    }

    int lower_search(int target){
        int start = 0;
        int end = card1.size()-1;

        int mid;
        int ans=-1;

        while ( start <= end){
            mid = (start+end)/2;

            if (card1[mid] < target)
                start = mid+1;
            else if (card1[mid] > target)
                end = mid-1;
            else{
                ans = mid;
                end= mid-1;
            }
        }
        return ans;
    }

    int upper_search(int target){
        int start = 0;
        int end = card1.size()-1;

        int mid;
        int ans=-1;

        while ( start <= end){
            mid = (start+end)/2;

            if (card1[mid] < target)
                start = mid+1;
            else if (card1[mid] > target)
                end = mid-1;
            else{
                ans = mid;
                start= mid+1;
            }
        }
        return ans;
    }

    void solver(){

        std::sort(card1.begin(), card1.end(), [](int a, int b){
            if(a<b)
                return true;
            else
                return false;            
        });

        for(int i =0 ; i < card2.size() ; ++i){
            int target = card2[i];

            int lower_idx = lower_search(target);
            int upper_idx = upper_search(target);

            if (lower_idx == -1 || upper_idx == -1)
                std::cout << "0 ";
            else
                std::cout << upper_idx - lower_idx +1 << " " ;
        }
    }

    private:
    std::vector<int> card1, card2;

};

int main(){
    int N,M;
    std::cin >> N;

    std::vector<int> card1(N);
    for(int i = 0 ; i < N ; ++i)
        std::cin >> card1[i];
    
    std::cin >> M;
    std::vector<int> card2(M);
    for(int i =0 ; i < M ; ++i)
        std::cin >> card2[i];

    solver_10816 solver(card1, card2);
    solver.solver();
    


    return 0;
}