#include <iostream>
#include <vector>
#include <cmath>

// 세그먼트 트리: https://www.crocus.co.kr/648
// 최대값 트리

/**
 * @brief 최대값을 구하는 세그먼트 트리 만드는 중(공부중 2/21)
 * 
 */

using namespace std;

class Segment_Tree{

    public:
    Segment_Tree(int _N): N(_N){
        tree = vector<int>(4*N,0);

        vector<int> inputs(N,0);
        for(int i =0 ; i < N ; ++i)
            cin >> inputs[i];

        init(inputs, tree, 1, 0, N-1);
        debug();
    }

    void debug(){
        int a = 1;
        bool indent = false;
        for(int i =1 ; i < tree.size(); ++i){
            if (i%(int)pow(2,a) == 0){
                cout << endl;
                a++;
                indent = true;
            }
            if(indent || i == 1){
                for(int j = 0 ; j < 2*N-a; ++j)
                    cout << " ";
                cout  << tree[i];
                indent = false;
            }
            else
                cout << " " << tree[i];
        }    
        cout << endl;
    }

    private:
    int N;
    vector<int> tree;

    // node가 tree
    int init(const vector<int> &inputs, vector<int> &tree, int node, int start, int end){
        if (start == end)
            return tree[node] = inputs[start];
        
        int mid = (start + end)/2;
        return tree[node] = max(init(inputs, tree, node*2, start, mid), init(inputs, tree, node*2+1, mid+1, end));
    };

};

int main(){
    int N;
    cin >> N ;
    Segment_Tree sTree(N);


    return 0;
}