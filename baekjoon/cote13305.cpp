#include <iostream>
#include <vector>

class solver_13305{
    public:
    solver_13305(std::vector<int> distance, std::vector<int> cost){
        distances = distance;
        costs = cost;
        N = costs.size();
    }

    long long solver(){
        long long total_cost = 0;
        int now_cost = costs[0];
        int next_cost;
        for(int i =1 ; i < N ; ++i){
            next_cost = costs[i];

            if (now_cost > next_cost){
                total_cost += (long long)distances[i-1] * now_cost;
                now_cost = costs[i];
            }
            else{
                total_cost += (long long)distances[i-1] * now_cost;
            }
        }
        
        return total_cost;
    }

    private:
    std::vector<int> distances, costs;
    int N;

};

int main(){

    int N; // 도시의 개수
    std::cin >> N;

    int distance;
    std::vector<int> distances;
    for(int i = 0 ; i < (N-1) ; ++i){
        std::cin >> distance;
        distances.push_back(distance);
    }

    int cost;
    std::vector<int> costs;
    for(int i =0 ; i < N ; ++i){
        std::cin >> cost;
        costs.push_back(cost);
    }

    solver_13305 solver(distances, costs);
    long long answer = solver.solver();

    std::cout << answer << std::endl;
    return 0;
}


/*
일단은, 지금 도시의 가격보다 다음 도시의 가겨이 싸면, 딱 이동할 거리만큼만 주유를 하고,
지금 도시의 가격이 더 싸면 다음 도시 + 다음 도시까지 주유를 하고 다음+다음도시와 가격비교
*/