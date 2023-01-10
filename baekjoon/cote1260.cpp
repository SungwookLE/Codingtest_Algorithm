/**
 * @date 2023-01-10
 * @brief @DFS는 바로 푼것 같은데, BFS가 좀 꼬였다. 다시 풀쟈 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class sovler1260
{

public:
    sovler1260(int _n_vertex, int _n_node, int _start) : n_vertex(_n_vertex), n_node(_n_node), start(_start)
    {
        for (int i = 0; i < _n_node; ++i)
        {
            int x, y;
            cin >> x >> y;
            graph.push_back(make_pair(x, y));
            graph.push_back(make_pair(y, x));
        }

        visited = vector<int>(_n_vertex + 1, 0);
        sort(graph.begin(), graph.end());
    }

    void DFS(int from)
    {
        // call stack
        visited[from] = 1;
        cout << from << " ";

        for (int idx = 0; idx < graph.size(); ++idx)
        {
            int to = graph[idx].second;
            if (graph[idx].first == from && visited[to] == 0)
            {
                DFS(to);
            }
        }
    }

    void BFS()
    {

        visited = vector<int>(n_vertex + 1, 0);
        int start_bfs = start;
        answer_bfs.push_back(start_bfs);
        visited[start_bfs]= 1;

        while(!isAllVisited()){
            for (int idx = 0; idx < graph.size(); ++idx)
            {
                int to = graph[idx].second;

                if (graph[idx].first == start_bfs && visited[to] == 0)
                {
                    candidates.push_back(graph[idx].second);
                    visited[to] = 1;
                }
                for(auto a: candidates){
                    cout << a << " ";
                }
                cout << endl;

                if (!candidates.empty())
                {
                    start_bfs = candidates.front();
                    answer_bfs.push_back(start_bfs);
                    candidates.erase(candidates.begin());
                }
            }
        }

        for(auto a : answer_bfs){
            cout << a << " " ;
        }

    }


    bool isAllVisited(){
        int count=0;
        for(int i: visited){
            count+=i;
        }

        return n_vertex == count;
    }

private:
    int n_vertex, n_node, start;
    vector<pair<int, int>> graph;
    vector<int> visited;
    vector<int> candidates;
    vector<int> answer_bfs;
};

int main(int argc, char **argv)
{
    int n_vertex, n_node, start;
    cin >> n_vertex >> n_node >> start;

    sovler1260 solver(n_vertex, n_node, start);
    // solver.DFS(start);
    cout << endl;
    solver.BFS();

    return 0;
}
