#include <iostream>
#include <vector>

class solver_1010{
    public:
    void insert_array(){
        std::cin >> N;
        std::vector<int> res(2.0);
        for(int i =0 ; i < N ; ++i){
            std::cin >> res[0] >> res[1];
            array.push_back(res);
        }
    }

    void solver(){
        // M Comination N 이 정답이네
        std::vector<int> res;
        for(int i =0 ; i < N ; ++i){
            res = array[i];
            
            DP.clear();
            std::vector<int> v(31,0);
            DP.resize(31,v);

            for(int j = 1 ; j <= res[1] ; ++j){
                for(int k = 0 ; k <= j ; ++k){
                    if ( j == k | k == 0)
                        DP[j][k] = 1;
                    else{

                        DP[j][k] = DP[j-1][k] + DP[j-1][k-1];
                    }
                }
            }
            std::cout << DP[res[1]][res[0]] << std::endl;
        }
    }

    private:
    int N;
    std::vector<std::vector<int>> array;
    std::vector<std::vector<int>> DP;

};

int main(){
    solver_1010 solver;
    solver.insert_array();
    solver.solver();

    return 0;
}