#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    // 먼저 카메라 1개는 최소조건으로 있어야 하니 배치해두고
    int answer = 1;
    sort(routes.begin(), routes.end());

    int prev_end = routes[0][1];
    for(int i =0 ; i < routes.size() ; ++i){
      
        // stream이 이어있지 않으면 카메라 1대를 더 추가하고,
        if (prev_end < routes[i][0]){
            answer+=1;
            prev_end = routes[i][1];
        }

        // stream이 안에 이어져 있으니까, stream의 뒷 부분을 새로운 stream의 끝으로 설정해 둔다.
        // 이 때, 카메라 추가는 필요 없음
        if (prev_end >= routes[i][1])
            prev_end = routes[i][1];
    }
    
    return answer;
}