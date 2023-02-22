#include <iostream>
#include <vector>
#include <cmath>

/**
 * @brief 세그먼트 트리(완전이진트리 Complete Binary Tree): 구간 최대값
 * @brief 구간 최대값을 구하는 세그먼트 트리
 * @brief 구현 방식: Top-Down
 * @brief https://www.crocus.co.kr/648
 */

using namespace std;

class Segment_Tree
{

public:
    Segment_Tree(int _N) : N(_N)
    {
        tree = vector<int>(4 * N, 0);
        vector<int> inputs(N + 1, 0); // 1번부터 시작함, inputs 배열은 처음에 입력받아 생성된 배열이다.
        for (int i = 1; i <= N; ++i)
            cin >> inputs[i];
        init(inputs, 1, 1, N); // 노드는 1번부터 시작함: tree[0]은 비워져 있음
    }

    void update(int node, int start, int end, int index, int val)
    {

        if (!(start <= index && index <= end))
            return;

        tree[node] = max(tree[node], val);

        if (start != end)
        {
            int mid = (start + end) / 2;
            update(node * 2, start, mid, index, val);
            update(node * 2 + 1, mid + 1, end, index, val);
        }
    }

    int query(int node, int start, int end, int left, int right)
    {
        if (left > end || right < start)
            return 0;
        if (left <= start && end <= right)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
    }

    /*
    재귀적으로 아래 영역으로 호출되면서 함수 스택이 쌓인 순서대로 연산되면서 최종 결과값 출력
    1. Example: left: 3 , right: 6

    query(1, start=1, end=5, left=3, right=5) return max(0, tree[5], tree[3])

    query(2, start=1, end=3, left=3, right=5) return max(0, tree[5])
    query(3, start=4, end=5, left=3, right=5) return tree[3]

    query(4, start=1, end=2, left=3, right=5) return 0
    query(5, start=3, end=3, left=3, right=5) return tree[5]
    */

    void debug()
    {
        int a = 1;
        bool indent = false;
        for (int i = 1; i < tree.size(); ++i)
        {
            if (i % (int)pow(2, a) == 0)
            {
                cout << endl;
                a++;
                indent = true;
            }
            if (indent || i == 1)
            {
                for (int j = 0; j < 2 * N - a; ++j)
                    cout << " ";
                cout << tree[i];
                indent = false;
            }
            else
                cout << " " << tree[i];
        }
        cout << endl;
    }

private:
    int N;
    vector<int> tree; // tree: 배열은 세그먼트 트리를 저장한 배열

    int init(const vector<int> &inputs, int node, int start, int end)
    {
        if (start == end)
            return tree[node] = inputs[start];

        int mid = (start + end) / 2;
        return tree[node] = max(init(inputs, node * 2, start, mid), init(inputs, node * 2 + 1, mid + 1, end));
    };
};

int main()
{
    int N;
    cin >> N;
    Segment_Tree sTree(N);
    sTree.debug();
    sTree.update(1, 1, N, 2, 19);
    sTree.debug();

    cout << sTree.query(1, 1, N, 3, N) << endl;

    return 0;
}