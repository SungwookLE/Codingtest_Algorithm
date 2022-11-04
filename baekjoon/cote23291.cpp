#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class solver
{

public:
	solver(const int _A[], int _N, int _K) : N(_N), K(_K)
	{
		A.resize(N + 1, vector<int>(N + 1, 0));

		for (int i = 1; i <= N; ++i)
			A[N][i] = _A[i - 1];
	}
	void print()
	{
		for (auto a : A)
		{
			for (auto b : a)
			{
				cout << b << " ";
			}
			cout << endl;
		}
	}

	void roll()
	{
		int pivot = 1, w = 1, h = 1;
		int idx = 0;
		while (pivot - 1 + w + h <= N)
		{
			for (int c = pivot; c < pivot + w; ++c)
			{
				for (int r = N; r > N - h; --r)
				{
					int nextR = (N - w) + (c - pivot);
					int nextC = (pivot + w) + (N - r);
					A[nextR][nextC] = A[r][c];
					A[r][c] = 0;
				}
			}
			pivot += (idx / 2 + 1);
			if (idx % 2)
				w += 1;
			else
				h += 1;

			idx += 1;
		}
	}

	void find_min_max()
	{
		min_val = 100001;
		max_val = 0;
		for (int i = 1; i <= N; ++i)
		{
			min_val = min(A[N][i], min_val);
			max_val = max(A[N][i], max_val);
		}
	}

	vector<int> find_idx(int val)
	{
		vector<int> idx_arr;
		for (int i = 1; i <= N; ++i)
		{
			if (A[N][i] == val)
				idx_arr.push_back(i);
		}
		return idx_arr;
	}

	int diff_element()
	{
		find_min_max();
		return max_val - min_val;
	}

	void add_one()
	{
		find_min_max();
		vector<int> arr = find_idx(min_val);

		while (!arr.empty())
		{
			A[N][arr.back()] += 1;
			arr.pop_back();
		}
	}

	void control()
	{
		// BFS: 인접한 물고기의 수를 비교해서 분배
		vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		vector<vector<int>> copy_A(A);

		for (int row = 1; row <= N; ++row)
		{
			for (int col = 1; col <= N; ++col)
			{
				if (copy_A[row][col] != 0)
				{
					for (auto d : delta)
					{
						int nextRow = row + d.first;
						int nextCol = col + d.second;

						if (nextRow>N || nextCol>N)
							continue;

						if (copy_A[nextRow][nextCol] == 0)
							continue;

						//물고기가 많은 경우
						if (A[row][col] > A[nextRow][nextCol])
						{
							int diff = (A[row][col] - A[nextRow][nextCol]) / 5;
							copy_A[row][col] -= diff;
							copy_A[nextRow][nextCol] += diff;
						}
					}
				}
			}
		}
		A = copy_A;
	}

	void flat(){
		queue<int> que;
		for(int col=1 ; col <=N; ++col){
			if (A[N][col] ==0) continue;

			for(int row =N ; row>=1;--row){

				if (A[row][col] ==0)
					break;

				que.push(A[row][col]);
				A[row][col] = 0;
			}
		}

		int col =1;
		while(!que.empty()){
			A[N][col++] = que.front();
			que.pop();
		}
	}


private:
	vector<vector<int>> A;
	int N, K, min_val, max_val;
};

int N, K;
int main()
{
	int answer = 0;
	cin >> N >> K;
	int A[101] = {
		0,
	};
	for (int i = 0; i < N; ++i)
		cin >> A[i];

	solver solve(A, N, K);

	while(solve.diff_element() > K){

	solve.add_one();
	solve.roll();
	solve.control();
	solve.print();
	solve.flat();

	answer+=1;
	}

	cout << answer << endl;
	return 0;
}