#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

class A_Star{

    public:
        A_Star(){
            readmaze();
            printmaze();
            heuristic();
        }

        void Search(){
            x = start.first;
            y = start.second;
            visited[x][y]=1;


            g = 0;
            h = heuristic_map[start.first][start.second];
            f = g+ h;

            opens_cand({f,h,x,y});

            while (!opens_cand.empty()){

                std::sort(opens_cand.begin(), opens_cand.end(), [](std::vector<int> a , std::vector<int> b){
                    if ( a[0] < b[0])
                        return true;
                    else if( a[0] == b[0]){
                        if ( a[1] < b[1])
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

                if ( x== end.first && y == end.second){
                    std::cout << "FIND IT\n";
                    break;
                }
                else{
                    for(int i =0 ; i < delta.szie() ; ++i){
                        int x2, y2, g2, f2;
                        x2 = x+delta[i][0];
                        y2 = y+delta[i][1];

                        if ( x2  >= 0 && y2>=0 && x2< maze.size() && y2 < maze.size()){
                            if (std::stoi(x2) 길이 막혓는지 아닌지 체큰)
                            g2 = g + 1;
                            f2 = g2 + heuristic_map[x2][y2];
                            
                            visited[x2][y2] = 1;
                        }





                    }
                }





            }

        }



    private:
        int x, y;
        int f=0, g=0, h=0;
        std::vector<std::vector<int>> opens_cand;
        std::vector<std::pair<int, int>> visited;
        std::vector<std::pair<int, int>> delta = {
            {0,1}, //right
            {0,-1}, // left
            {1,0}, // up
            {-1,0} // down
        };
        void heuristic(){
            for(int row =0 ; row < maze.size() ; ++row){
                std::vector<int> heuris_temp;
                for(int col = 0 ; col < maze[0].size() ; ++col){
                    heuris_temp.push_back(heuristic_calc(std::make_pair(row,col)));
                }
                heuristic_map.push_back(heuris_temp);
            }
        }

        int heuristic_calc(std::pair<int, int> target){
            int res= abs(target.first - end.first) + abs(target.second - end.second);
            return res;
        }

        std::pair<int,int> start, end;
        std::vector<std::vector<std::string>> maze;
        std::vector<std::vector<int>> heuristic_map;

        void readmaze(){
            std::ifstream readFile("./A_star/maze.txt");       //읽을 목적의 파일 선언
            std::string line;
            std::string value;
        
            if(readFile.is_open()){       //파일이 열렸는지 확인
                int row =0  ;
                while(!readFile.eof()){   //파일 끝까지 읽었는지 확인
                    std::getline(readFile, line);
                    std::replace(line.begin(), line.end(), ' ', ',');
                    std::istringstream linestream(line);
                    std::vector<std::string> temp_vector;
                    int col =0;    
                    while (std::getline(linestream, value, ',')){
                        if (value == "S")
                            start = std::make_pair(row,col);
                        if (value == "E")
                            end = std::make_pair(row,col);
                        temp_vector.push_back(value);
                        col ++;
                    }
                    maze.push_back(temp_vector);
                    row++;
                }    
            }
            else
                std::cout << "NO file\n";
            readFile.close();
        }

        void printmaze(){
            std::cout << "MAZE is: \n";
            for (auto row : maze){
                for (auto col: row)
                    std::cout << col << " ";
                std::cout << std::endl;
            }
            std::cout << "START coord is: " << start.first << " "<< start.second << std::endl;
            std::cout << "END coord is: " << end.first << " "<< end.second << std::endl;

        }


};

int main(){

    A_Star a;

    return 0;
}