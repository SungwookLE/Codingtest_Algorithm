#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class solver
{
public:
    solver()
    {
        readmaze();
        printmaze();
    }

    void bfs(){
        visited.resize(maze.size(), vector<int>(maze[0].size(), 0));
        bool found = false;
        bool resign = false;
        opens.push_back({start.first, start.second});

        while (found != true && resign != true){

            if (opens.empty()){
                resign = true;
                cout << "no route!\n";
                break;
            }

            vector<int> now = opens.back();
            opens.pop_back();
            visited[now[0]][now[1]] = 1;

            if (now[0] == end.first && now[1] == end.second){
                found = true;
                cout << "found route!\n";
                break;
            }
            
            for(auto d : deltas){
                pair<int, int> next;
                next.first = now[0] + d.first;
                next.second = now[1] + d.second;

                if (next.first >= 0 && next.second >= 0 && next.first < maze.size() && next.second < maze[0].size()){
                    if (maze[next.first][next.second] != '#' && visited[next.first][next.second] == 0){
                        opens.push_back({next.first, next.second});
                    }
                }
            }
        }
        return;
    }

private:
    void printmaze()
    {
        cout << "Start: " << start.first << ", " << start.second << endl;
        cout << "Goal: " << end.first << ", " << end.second << endl;

        for (auto row: maze){
            for (auto col : row)
                cout << col ;
            cout << endl;
        }
    }
    void readmaze()
    {
        std::ifstream readFile("./maze.txt"); // 읽을 목적의 파일 선언
        std::string line;
        std::string value;
        try
        {
            if (!readFile.is_open())
            { // 파일이 열렸는지 확인
                throw("No exist maze file..");
            }

            int row = 0;
            while (!readFile.eof())
            { // 파일 끝까지 읽었는지 확인
                std::getline(readFile, line);
                std::istringstream linestream(line);

                std::vector<char> temp;
                int col = 0;
                while (std::getline(linestream, value))
                {
                    for (int i = 0 ; i < value.length(); ++i){
                        
                        if (value[i] == 'S'){
                            start = std::make_pair(row, col);
                        }
                        if (value[i] == 'G'){
                            end = std::make_pair(row, col);
                        }

                        temp.push_back(value[i]);
                        col++;
                    }
                }
                maze.push_back(temp);
                row++;
            }
        }
        catch (std::string e)
        {
            std::cout << e << std::endl;
        }
    }
    pair<int, int> start, end;
    vector<vector<char>> maze;
    vector<vector<int>> visited;
    
    vector<vector<int>> map;
    vector<vector<int>> opens;
    vector<pair<int, int>> deltas = { {-1,0}, {1,0}, {0,-1}, {0,1} };

};

int main()
{
    solver solve;
    solve.bfs();

    return 0;
}