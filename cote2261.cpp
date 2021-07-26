#include <iostream>
#include <vector>
#include <algorithm>

//REF: https://dhpark-blog.tistory.com/entry/BOJ-2261-%EA%B0%80%EC%9E%A5-%EA%B0%80%EA%B9%8C%EC%9A%B4-%EB%91%90-%EC%A0%90
//[반례모음](https://bingorithm.tistory.com/8)

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

        int solver(int start, int end){

            int count = end-start+1;

            if(count <=3){
                for(int i = start; i < end; ++i){
                    for(int j = i+1; j <=end ; ++j){
                        ans = std::min(ans, distance(mat[i], mat[j]));
                    }
                }
            }
            else{
                int mid =(start+end)/2;
                int left = solver(start, mid-1);
                int right = solver(mid+1, end);

                ans = std::min(left, right);

                std::vector<std::pair<int, int>> temp_mat;
                temp_mat.push_back(mat[mid]);

                for(int i = mid-1; i>=start; --i){
                    if (distance({mat[mid].first, 0}, {mat[i].first,0}) >= ans ) break;
                    temp_mat.push_back(mat[i]);
                }
                for(int i = mid+1; i <= end; ++i){
                    if (distance({mat[mid].first, 0}, {mat[i].first,0}) >= ans ) break;
                    temp_mat.push_back(mat[i]);
                }
                std::sort(temp_mat.begin(), temp_mat.end(), [](auto a, auto b){
                if (a.second < b.second)
                    return true;
                else
                    return false;
                });

                for(int i = 0 ; i < temp_mat.size()-1; ++i){
                    for(int j = i +1 ; j < temp_mat.size() ; ++j){
                        if (distance({temp_mat[i].second,0}, {temp_mat[j].second,0}) >= ans) break;
                        ans = std::min(ans, distance(temp_mat[i], temp_mat[j]));
                    }
                }
            }
            return ans;
        }
        int distance(std::pair<int, int> a, std::pair<int, int> b){
            return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second); 
        }
        void show_ans(){
            std::cout << ans << std::endl;
        }
        void show_mat(){
            std::cout << "MAT: \n";
            for(auto a : mat){
                std::cout << a.first << " " << a.second << "\n";
            }
        }

    private:
        std::vector<std::pair<int, int>> mat;
        int size = mat.size();
        int ans=1000000000;
};

int main(){
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