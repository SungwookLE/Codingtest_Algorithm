#include <iostream>
#include <vector>
// 세그먼트 트리를 이용한 문제

// 내가 원하는 답을 가지고 있는 트리를 구하고
// 트리에서 액션을 하는 쿼리 함수를 짠다음에
// 솔버에서 쿼리를 호출해서 O(logN) 의 복잡도로 함수를 짜는 것

// '21.7/24

class solver_6549{

    public:
    solver_6549(std::vector<long long> _arr){
        arr = _arr;
        tree.resize(arr.size()*4);
    }

    int init(int start, int end, int node){

        if (start == end){
            tree[node] = start;
            return tree[node];
        }

        int mid = (start+end)/ 2;
        int left_index = init(start, mid, node*2);
        int right_index = init(mid+1, end, node*2+1);

        if (arr[left_index] < arr[right_index])
            tree[node] = left_index;
        else
            tree[node] = right_index;

        return tree[node];
    }

    int query(int start, int end, int node, int left, int right){

        if ( end < left || start > right) return -1;
        if ( start >= left && end <= right) return tree[node];

        int mid = (start+end)/2;
        int left_index = query(start, mid, node*2, left, right);
        int right_index = query(mid+1, end, node*2+1, left, right);

        if(left_index == -1) return right_index;
        else if (right_index == -1) return left_index;
        else{
            if ( arr[left_index] < arr[right_index])
                return left_index;
            else
                return right_index;
        }
    }

    void solve(int left, int right){
        if (left > right) return;

        int index = query(0, arr.size()-1, 1, left, right);
        ans = std::max(ans, arr[index] * (right-left+1) );

        //분할정복
        solve(left, index-1);
        solve(index+1, right);
    }

    void show_arr(){
        std::cout << "ARRAY: \n";
        for(int i: arr )
            std::cout << i << " " ;
        std::cout<<std::endl;
    }

    void show_tree(){
        std::cout << "TREE: \n";
        for(int i = 1 ; i < tree.size(); i=i*2+1){
            for(int j =(i-1)/2+1; j <= i ; ++j)
                std::cout << tree[j] << " ";
            std::cout << std::endl;
        }
    }

    long long ans=0;

    private:
    std::vector<long long> arr;
    std::vector<int> tree;

};

int main()
{
    int n;
    while (true)
    {
        std::cin >> n;
        if (n == 0)
            break;

        std::vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            std::cin >> arr[i];
        
        solver_6549 solver(arr);
        solver.init(0, arr.size()-1, 1);

        solver.solve(0, arr.size()-1);
        std::cout << solver.ans << std::endl;

    }
    return 0;
}