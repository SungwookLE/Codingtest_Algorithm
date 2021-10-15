#include <iostream>
#include <vector>
#include <algorithm>


class solver_10816{
    public:
    solver_10816(std::vector<int> _card1, std::vector<int> _card2){

        card1 = _card1;
        card2 = _card2;
    }

    void solver(){

        std::sort(card1.begin(), card1.end(), [](int a, int b){
            if(a<b)
                return true;
            else
                return false;            
        });

        std::vector<std::pair<int, int>> card1_dict;
        for(int i = 0 ; i < card1.size(); ++i){
            int count =1;
            bool is_continu = false;
            for(int j = i+1 ; j < card1.size() ; ++j){

                if (card1[i] != card1[j]){
                    if (is_continu == true)
                        break;
                    else{
                        count = 1;
                        break;
                    }
                }
                else{
                    is_continu = true;
                    count +=1;
                }
            }
            if (card1_dict.empty())
                card1_dict.push_back({card1[i], count});
            else if (card1_dict.back().first != card1[i])
                card1_dict.push_back({card1[i], count});
        }


        for(int i = 0 ; i < card2.size() ; ++i){
            int target = card2[i];

            int start = 0;
            int end = card1_dict.size()-1;

            int mid;
            int ans=0;

            while ( start <= end){
                mid = (start+end)/2;

                if (card1_dict[mid].first < target)
                    start = mid+1;
                else if (card1_dict[mid].first > target)
                    end = mid-1;
                else{
                    break;
                }
            }
            if (target == card1_dict[mid].first)
                std::cout << card1_dict[mid].second << " ";
            else
                std::cout << "0 ";
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