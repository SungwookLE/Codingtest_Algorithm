#include <iostream>
#include <queue>

// 7/6: 아 priority_queue라는게 있었구나,, 괜히 뻘짓했네 timeout 으로,, 

int main(){

    int t;
    std::cin >> t;

    for(int i =0 ; i < t; ++i){

        int n,m;
        std::cin >> n >> m;

        std::queue<std::pair<int, int>> docList;
        std::priority_queue<int> maxImportance;

        int printCount =0;

        for (int i =0 ; i < n ; ++i){
            int val;
            std::cin >> val;

            docList.push(std::make_pair(i, val));
            maxImportance.push(val);

        }

        while(!docList.empty()){
            int index = docList.front().first;
            int importance = docList.front().second;

            // 중요도가 더 높은 문서가 있을 경우 맨 뒤로 보냄
            if (maxImportance.top() > importance){
                docList.push(docList.front());
                docList.pop();
            }
            // 그렇지 않으면 인쇄
            else{
                docList.pop();
                maxImportance.pop();

                printCount+=1;

                if (index == m){
                    std::cout << printCount << std::endl;
                    break;
                }
            }
        }
    }


    return 0;
}