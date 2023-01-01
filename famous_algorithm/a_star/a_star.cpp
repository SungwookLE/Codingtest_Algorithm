#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

class A_Star
{

public:
    A_Star()
    {
        readmaze();
        printmaze();
        heuristic();
    }

    void Search()
    {
        bool found = false, resign = false;

        x = start.first;
        y = start.second;
        visited[x][y] = 1;

        g = 0;
        h = heuristic_map[start.first][start.second];
        f = g + h;

        opens_cand.push_back({f, h, x, y});

        while (found != true && resign != true)
        {
            std::sort(opens_cand.begin(), opens_cand.end(), [](std::vector<int> a, std::vector<int> b)
                      {
                          if (a[0] < b[0]) //오타다 정렬 거꾸로 했다;; (10/8)
                              return true;
                          else if (a[0] == b[0])
                          {
                              if (a[1] < b[1])
                                  return true;
                              else
                                  return false;
                          }
                          else
                              return false;
                      });

            std::vector<int> selected = opens_cand.back();
            opens_cand.pop_back();

            x = selected[2];
            y = selected[3];

            if (x == end.first && y == end.second)
            {
                std::cout << "\nFinding route to exit is:\n";
                found = true;
                print_solution();
            }
            else
            {
                for (int i = 0; i < delta.size(); ++i)
                {
                    int x2, y2, g2, f2, h2;
                    x2 = x + delta[i].first;
                    y2 = y + delta[i].second;

                    if (x2 >= 0 && y2 >= 0 && x2 < maze.size() && y2 < maze.size())
                    {
                        if (maze[x2][y2] != "1" && visited[x2][y2] != 1)
                        {
                            g2 = g + 1;
                            h2 = heuristic_map[x2][y2];
                            f2 = g2 + h2;
                            visited[x2][y2] = 1;
                            opens_cand.push_back({f2, h2, x2, y2});
                            navigation[x2][y2] = i;
                        }
                    }
                }
            }
            if (found == false && opens_cand.empty())
            {
                resign = true;
                std::cout << "\nNo route to exit......\n";
                print_solution();
            }
        }
    }

private:
    int x, y;
    int f = 0, g = 0, h = 0;
    std::vector<std::vector<int>> opens_cand;
    std::vector<std::vector<int>> visited, navigation;
    std::vector<std::vector<std::string>> results;
    std::vector<std::pair<int, int>> delta = {
        {0, 1},  // right
        {0, -1}, // left
        {1, 0},  // down
        {-1, 0}  // up
    };
    std::vector<std::string> arrow = {">", "<", "∨", "^"};

    void heuristic()
    {
        for (int row = 0; row < maze.size(); ++row)
        {
            std::vector<int> heuris_temp;
            for (int col = 0; col < maze[0].size(); ++col)
            {
                heuris_temp.push_back(heuristic_calc(std::make_pair(row, col)));
            }
            heuristic_map.push_back(heuris_temp);
        }
    }

    void print_solution()
    {
        while (x != start.first || y != start.second)
        {
            if (navigation[x][y] == 0)
            {
                results[x][y] = arrow[0];
                y -= 1;
            }
            else if (navigation[x][y] == 1)
            {
                results[x][y] = arrow[1];
                y += 1;
            }
            else if (navigation[x][y] == 2)
            {
                results[x][y] = arrow[2];
                x -= 1;
            }
            else if (navigation[x][y] == 3)
            {
                results[x][y] = arrow[3];
                x += 1;
            }
        }
        results[start.first][start.second] = "S";
        results[end.first][end.second] = "E";

        for (auto row : results)
        {
            for (auto col : row)
                std::cout << col << " ";
            std::cout << std::endl;
        }
    }

    int heuristic_calc(std::pair<int, int> target)
    {
        int res = abs(target.first - end.first) + abs(target.second - end.second);
        return res;
    }

    std::pair<int, int> start, end;
    std::vector<std::vector<std::string>> maze;
    std::vector<std::vector<int>> heuristic_map;
    void readmaze()
    {
        std::ifstream readFile("./A_star/maze.txt"); //읽을 목적의 파일 선언
        std::string line;
        std::string value;

        try
        {
            if (!readFile.is_open())
            { //파일이 열렸는지 확인
                throw("No exist maze file..");
            }

            int row = 0;
            while (!readFile.eof())
            { //파일 끝까지 읽었는지 확인
                std::getline(readFile, line);
                std::replace(line.begin(), line.end(), ' ', ',');
                std::istringstream linestream(line);
                std::vector<std::string> temp_vector;
                int col = 0;
                while (std::getline(linestream, value, ','))
                {
                    if (value == "S")
                    {
                        start = std::make_pair(row, col);
                    }
                    if (value == "E")
                    {
                        end = std::make_pair(row, col);
                    }
                    temp_vector.push_back(value);
                    col++;
                }
                maze.push_back(temp_vector);
                row++;
            }
            std::vector<int> temp_visited(maze[0].size(), 0);
            visited.resize(maze.size(), temp_visited);
            navigation.resize(maze.size(), temp_visited);
            std::vector<std::string> temp_results(maze[0].size(), " ");
            results.resize(maze.size(), temp_results);
        }
        catch (std::string e)
        {
            std::cout << e << std::endl;
        }
    }
    void printmaze()
    {
        std::cout << "MAZE is: \n";
        for (auto row : maze)
        {
            for (auto col : row)
                std::cout << col << " ";
            std::cout << std::endl;
        }
        // std::cout << "START coord is: " << start.first << " "<< start.second << std::endl;
        // std::cout << "END coord is: " << end.first << " "<< end.second << std::endl;
    }
};

int main()
{

    A_Star solver;
    solver.Search();

    return 0;
}