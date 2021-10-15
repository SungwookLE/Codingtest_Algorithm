#include <iostream>
#include <vector>

//브루트 포스 (all search)

class prob_2798{
    public:
    prob_2798(){
        std::cin >> N >> M;
        cards.resize(N,0);
        for(int i =0 ; i < N ; ++i)
            std::cin >> cards[i];
    }

    void solver(){

        for(int i = 0 ; i < N ; ++i){
            for(int j =0 ; j < N ; ++j){
                for(int k =0; k < N ; ++k){
                    ans = 0;
                    if (i != j && i != k && j != k){
                        ans = cards[i] + cards[j] + cards[k];
                        candi.push_back(ans);
                        if (ans == M){
                            std::cout << ans << std::endl;
                            return;
                        }
                    }
                
                }
            }
        }

        int min_diff = M;
        for(auto element: candi){
            if (M > element){
                int diff = abs(element-M);
                if (min_diff> diff){
                    min_diff = diff;
                    ans = element;
                }
            }
        }

        std::cout << ans << std::endl;
        return;
    }

    private:
    int N, M;
    std::vector<int> cards, candi;
    int ans;


};

int main(){

    prob_2798 solver;
    solver.solver();

    return 0;
}