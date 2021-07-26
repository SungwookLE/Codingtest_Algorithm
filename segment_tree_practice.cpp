#include <iostream>
#include <vector>

class range_sum_tree{
    public:
    range_sum_tree(std::vector<int> _arr){
        arr=_arr;
        size = arr.size();
        tree.resize(size*4);
    }

    int init(int start, int end, int node){
        
        if (start == end){
            tree[node] = arr[start];
            return tree[node];
        }
        int mid = (start+end)/2;
        tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
        return tree[node];
    }
    int sum(int start, int end, int node, int left, int right){

        if ( right < start || left > end)
            return 0;
        if ( left <= start && right >= end){
            return tree[node];
        }
        int mid = (start+end)/2;
        return sum(start, mid, node*2, left, right) + sum (mid+1, end, node*2+1, left, right);

    }
    void update(int start, int end, int node, int index, int dif){
        if(index < start || index > end) return;
        
        tree[node] += dif;
        if (start ==end) return;
        int mid = (start+end) / 2;
        update(start, mid, node*2, index, dif);
        update(mid+1, end, node*2+1, index, dif);

    }

    void show_tree(){
        std::cout << "TREE: \n";
        for(int i = 1 ; i < tree.size(); i=i*2+1){
            for(int j =(i-1)/2+1; j <= i ; ++j)
                std::cout << tree[j] << " ";
            std::cout << std::endl;
        }
    }

    private:
    std::vector<int> arr;
    int size ;
    std::vector<int> tree;
};

int main(){
    int N;
    std::cin >> N;
    std::vector<int> arr(N);

    for(int i = 0 ; i < N ; ++i)
        std::cin >> arr[i];
    
    range_sum_tree tree(arr);
    tree.init(0, N-1, 1);
    tree.show_tree();

    std::cout << "\nBEFORE UPDATE SUM idx(0~3)\n";
    std::cout << tree.sum(0, N-1, 1, 0, 3) << std::endl;


    tree.update(0, N-1, 1, 2 , 10); // update --> adding +10
    std::cout << "\nAFTER UPDATE SUM idx(0~3)\n";
    std::cout << tree.sum(0, N-1, 1, 0, 3) << std::endl;
    tree.show_tree();


}