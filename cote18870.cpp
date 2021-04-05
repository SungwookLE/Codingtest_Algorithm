#include <iostream>
#include <vector>
//만약 정확한 값이 필요 없고 값의 대소 관계만 필요하다면, 모든 수를 0 이상 N 미만의 수로 바꿀 수 있습니다.
//좌표 압축
/*
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.
Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.
X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.
*/

#include <algorithm>

int main(){

    int n;
    std::cin >> n;

    std::vector<int> idx;
    std::vector<int> value;
    for (int i =0 ; i < n ; ++i){
        int num;
        std::cin >> num;
        idx.push_back(num);
        value.push_back(num);
    }

    std::sort(idx.begin(), idx.end(), [](int a, int b){
        if (a<b)
            return true;
        else
            return false;
    });

    idx.erase(std::unique(idx.begin(), idx.end()), idx.end());

    for(int i =0 ; i < value.size() ; ++i){
        int pos = std::lower_bound(idx.begin(), idx.end(), value[i]) - idx.begin();
        std::cout << pos << " ";
    }

    return 0;
}

// 근데 이렇게 푸는건 stl을 써서 통과한거지 내가 직접 어떤 알고리즘을 짜야 코딩테스트인거 아잉교?? (4/5)
// ref: https://hoho325.tistory.com/243