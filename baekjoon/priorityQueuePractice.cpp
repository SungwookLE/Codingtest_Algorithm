//priority Queue 연습, custom Compaer 함수 추가

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Container{
    int from, to;
    int cost;
    int idx;
    Container(int _from, int _to, int _cost, int _idx): from(_from), to(_to), cost(_cost), idx(_idx) {}
};

// cost 기준으로 작은값이 Top 을 유지 하도록 한다.
struct cmp {
    bool operator()(Container a, Container b) {
        return a.cost > b.cost;
    }
};


int main(){

    priority_queue<Container, vector<Container>, cmp> pq;

    pq.push(Container(1,2,1,5));
    pq.push(Container(1,2,3,5));
    pq.push(Container(1,2,-1,5));

    while(!pq.empty()){
        cout << pq.top().cost << "\n";
        pq.pop();
    }

    return 0;

}