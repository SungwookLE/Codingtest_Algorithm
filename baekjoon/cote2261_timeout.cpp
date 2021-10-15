#include <iostream>
#include <vector>
#include <algorithm>

class solver_2261{
    public:
        solver_2261(std::vector<std::pair<int,int>> _mat){
            mat = _mat;
            std::sort(mat.begin(), mat.end(), [](auto a, auto b){
                if (a.first < b.first)
                    return true;
                else
                    return false;
            });
            size = mat.size();
        }

        void show_mat(){
            std::cout << "MAT: \n";
            for(auto a : mat){
                std::cout << a.first << " " << a.second << "\n";
            }
        }

        void solver(int start, int end){
            if (start == end) return;

            int temp = distance(mat[start], mat[end]); 
            ans=std::min(ans, temp);

            int mid = (start+end)/2;
            near_comp(start, end, mid);
            //std::cout << mid << std::endl;
            solver(start, mid);
            solver(mid+1, end);

            return;
        }

        int distance(std::pair<int, int> a, std::pair<int, int> b){
            return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second); 
        }

        void near_comp(int start, int end, int mid){
            std::vector<std::pair<int, int>> temp_mat;
            for(int i = mid ; i >= start; --i){
                if(distance({mat[mid].first,0}, {mat[i].first,0}) >= ans) break;
                temp_mat.push_back(mat[i]);
            }
            
            for(int i = mid+1 ; i <= end; ++i){
                if(distance({mat[mid].first,0}, {mat[i].first,0}) >= ans) break;
                temp_mat.push_back(mat[i]);
            }

            if (!temp_mat.empty()){
                std::sort(temp_mat.begin(), temp_mat.end(), [](auto a, auto b){
                    if (a.second < b.second)
                        return true;
                    else
                        return false;
                });

                for(int i = 0 ; i < temp_mat.size()-1 ; ++i){
                    for(int j = i+1; j < temp_mat.size() ; ++j){
                        if (distance({temp_mat[i].second, 0}, {temp_mat[j].second, 0}) >= ans ) break;
                        ans = std::min(ans, distance(temp_mat[i], temp_mat[j]));
                    }
                }
            }

            return;
        }

        void show_ans(){
            std::cout << ans << std::endl;
        }

    private:
        std::vector<std::pair<int, int>> mat;
        int size = mat.size();
        int ans=1000000000;

};


int main(){
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int n;
    int x,y;
    std::cin >> n;
    std::vector<std::pair<int, int>> mat;

    for (int i=0 ; i < n ; ++i){
        std::cin >> x >> y;
        mat.push_back(std::make_pair(x,y));
    }

    solver_2261 solver(mat);
    solver.solver(0, n-1);
    solver.show_ans();

    return 0;
}