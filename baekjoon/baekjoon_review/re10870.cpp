#include <iostream>
#include <vector>

//recursion

class prob_10870{
public:
prob_10870(){
    std::cin >> n;
}

int solver(int count){
    int ans;
    if (count >= 2 ){
        ans = solver(count-1) + solver(count-2); // 이렇게 푸는건 점화식 풀이에 가까운 풀이이긴 함
    }
    else{
        if (count == 0)
            ans = 0;
        else if (count ==1)
            ans =1;
    }
    return ans;
}

void solver2(int count){
    if (count > n){
        std::cout << arr2.back() << std::endl;
        return;
    }
    else{
        if(count == 0 )
            arr2.push_back(0);
        else if (count ==1)
            arr2.push_back(1);
        else
            arr2.push_back(arr2[arr2.size()-1] + arr2[arr2.size()-2]);
    
        solver2(count+1);
    }
}


int n;
    
private:
    std::vector<int> arr2;
};

int main(){
    prob_10870 solver;
    std::cout << solver.solver(solver.n) << std::endl;
    solver.solver2(0);


    return 0;
}