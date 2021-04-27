#include <iostream>
#include <vector>

void find_answer(int num, std::vector<long long> &triangle){
    int start = triangle.size();

    for(int i =start ; i < num ; ++i){
        long long temp ;
        temp = triangle[i-3] + triangle[i-2];
        triangle.push_back(temp);
    }
}

int main(){
    int n;
    std::cin >> n;
    std::vector<long long> triangle ={1,1,1}; // P(N-3) + P(N-2) // 2, 2, 3, (2+2=4), (2+3=5)
    for (int i =0 ; i < n ; ++i){
        int num;
        std::cin >> num;

        find_answer(num, triangle);
        std::cout << triangle[num-1] << std::endl;
    }
    return 0;
}