#include <iostream>
#include <vector>

int a[100001];
int n;
int count = 0;
void init(std::vector<int> &tree, int node, int start, int end){
    if (start == end)
    {
        tree[node] = start;
        return;
    }
    init(tree, node * 2, start, (start + end) / 2);
    init(tree, node * 2 + 1, (start + end) / 2 + 1, end);
    if (a[tree[node * 2]] < a[tree[node * 2 + 1]])
    {
        tree[node] = tree[node * 2];
    }
    else
    {
        tree[node] = tree[node * 2 + 1];
    }
    return;
}

int query(std::vector<int> &tree, int node, int start, int end, int i, int j)
{
    if (j < start || i > end)
        return -1;
    if (i <= start && j >= end)
        return tree[node];
    int left = query(tree, node * 2, start, (start + end) / 2, i, j);
    int right = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
    if (left == -1)
    {
        return right;
    }
    if (right == -1)
    {
        return left;
    }
    if (a[left] < a[right])
    {
        return left;
    }
    else
    {
        return right;
    }
}

long long largest(std::vector<int> &tree, int start, int end)
{
    long long answer = 0;
    int minIdx = query(tree, 1, 0, n - 1, start, end);
    answer = (long long)a[minIdx] * (long long)(end - start + 1);
    if (minIdx > start)
    {
        answer = std::max(answer, largest(tree, start, minIdx - 1));
    }
    if (minIdx < end)
    {
        answer = std::max(answer, largest(tree, minIdx + 1, end));
    }
    return answer;
}

int main()
{
    while (true)
    {
        std::cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }
        std::vector<int> tree(300003);
        init(tree, 1, 0, n - 1);
        std::cout << largest(tree, 0, n - 1) << '\n';
    }
    return 0;
}