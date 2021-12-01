#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
//REF:https://lipcoder.tistory.com/entry/%EC%84%AC-%EC%97%B0%EA%B2%B0%ED%95%98%EA%B8%B0-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4


using namespace std;

class kruskal_greedy{
    public:
    kruskal_greedy(vector<int> _parents): parents(_parents) {}
    int getParents(int x){
        if (parents[x] == x) return x;
        else return getParents(parents[x]);
    }

    void mergeParent(int a, int b){

        a = getParents(a);
        b = getParents(b);

        if ( a > b)
            parents[a] = b;
        else
            parents[b] = a;
        
        return;
    }

    bool find(int a , int b){
        a = getParents(a);
        b = getParents(b);
        return a==b;
    }

    private:
    vector<int> parents;
};


int solution(int n, vector<vector<int>> costs) {
    int answer = 0, max =0;
    
    sort(costs.begin(), costs.end(), [](auto a , auto b){
        if ( a[2] < b[2])
            return true;
        else
            return false;
    });

    
    //부모노드용 리스트 생성 및 초기화
    vector<int> parents;
    for(int i =0 ; i < n ; ++i) parents.push_back(i);
    kruskal_greedy solver(parents);

    //costs를 처음부터 순회
    for(auto a : costs){
        //두개의 부모노드가 같지않다면 -> 사이클이 생성 안된다면
        if (!solver.find(a[0], a[1])){


            //결과에 가중치 추가
            answer += a[2];
            //부모노드 병합하기
            solver.mergeParent(a[0], a[1]);
        }
    }
    
    return answer;
}

int main(int argc, char* argv[]){

    int n = 4;
    vector<vector<int>> costs = {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}};


    cout<< solution(5, costs) << endl;


    return 0;
}