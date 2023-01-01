#include <vector>
#include <iostream>

// Quick Sort 를 만들어보자
// https://hongku.tistory.com/149

template <typename T>
class quick_sort
{

public:
    quick_sort(std::vector<T> _array) : array(_array) {}

    void sort(int start, int end)
    {
        if (start >= end)
            return;

        int pivot = start;
        int i = pivot + 1;
        int j = end;

        // 오름차순 정렬
        while (i <= j)
        {
            while (array[pivot] >= array[i] && i <= end)
                i++;
            while (array[pivot] <= array[j] && j > start)
                j--;
            if (i < j)
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            else if (i >= j)
            {
                int temp = array[j];
                array[j] = array[pivot];
                array[pivot] = temp;
            }
        }
        sort(start, j - 1);
        sort(j + 1, end);
    }

    void result()
    {
        for (auto a : array)
            std::cout << a << "std::endl";
    }

private:
    std::vector<T> array;
};

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> array(N, 0);
    for (int i = 0; i < N; ++i)
        std::cin >> array[i];

    quick_sort<int> sort(array);
    sort.sort(0, N - 1);
    sort.result();

    return 0;
}