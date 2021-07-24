#include <iostream>
#include <vector>
// https://blog.naver.com/ndb796/221282210534, 구간합 트리
// 구간합 세그먼트 트리 O(logN)

class segment_tree{
    public:
        // 트리 클래스
        segment_tree(std::vector<int> _arr){
            given_arr = _arr;
            tree.resize(4*given_arr.size());
        }
        int init(int start, int end, int node);
        int sum(int start, int end, int node, int left, int right);
        void show_tree(){
            std::cout << "TREE: \n";
            for(int i = 1 ; i < tree.size(); i=i*2+1){
                for(int j =(i-1)/2+1; j <= i ; ++j)
                    std::cout << tree[j] << " ";
                std::cout << std::endl;
            }
        }
        void show_given_arr(){
            std::cout<<"Given arr: \n";
            for(auto a : given_arr)
                std::cout << a<< " ";
            std::cout << std::endl;
        }
        void update(int start, int end, int node, int index, int dif);
    private:
    std::vector<int> tree ={-1};
    std::vector<int> given_arr;
};

int main(){
    int N;
    std::cin>> N;
    std::vector<int> given(N);
    for(int i =0 ; i < N ; ++i)
        std::cin >> given[i];

    segment_tree st(given);

    

    st.init(0, given.size()-1, 1);
    st.show_given_arr();
    st.show_tree();

    std::cout << "\nSUM: idx[1~2] \n";
    std::cout << st.sum(0, given.size()-1, 1, 1, 2) << std::endl;

    std::cout << "UPDATE: idx[1] to 10 \n";
    st.update(0, given.size()-1, 1, 1, 10);
    st.show_tree();
    
    std::cout << "\nSUM: idx[1~2] \n";
    std::cout << st.sum(0, given.size()-1, 1, 1, 2) << std::endl;

    return 0;
}

// start: 시작 인덱스, end: 끝 인덱스
int segment_tree::init(int start, int end, int node){
    if (start == end){
        tree[node] = given_arr[start];
        return tree[node];
    }

    int mid = (start+end)/2;
    // 재귀적으로 두 부분을 나눈 뒤에 그 합을 자기 자신으로 합니다.
    tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);

    return tree[node];
}
// start: 시작 인덱스, end: 끝 인덱스
// left, right: 구간 합을 구하고자 하는 범위
int segment_tree::sum(int start, int end, int node, int left, int right){
    //범위 밖에 있는 경우
    if (left > end || right < start)
        return 0;
    // 범위 안에 있는 경우
    if (left <= start && end <=right)
        return tree[node];
    //그렇지 않다면 두 부분으로 나누어 합을 구하기
    int mid = (start+end) / 2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

// start: 시작 인덱스, end: 끝 인덱스
// index: 구간 합을 수정하고자 하는 노드
// dif: 수정할 값
void segment_tree::update(int start, int end, int node, int index, int dif){
    
    //범위 밖에 있는 경우
    if(index < start || index > end) return;
    //범위 안에 있으면 내려가며 다른 원소도 갱신
    tree[node] += dif;
    if (start ==end) return;
    int mid = (start+end) / 2;
    update(start, mid, node*2, index, dif);
    update(mid+1, end, node*2+1, index, dif);
}