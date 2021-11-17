#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class finder{

    public:
    finder(vector<vector<char>> _map, int R, int C){
        row = R;
        col = C;
        map = _map;
        visited.resize(R, vector<int>(C,0));
        heuris.resize(R, vector<int>(C,0));



        for(int i =0 ; i < row ; ++i){
            for (int j =0 ; j < col ; ++j){

                if (map[i][j] == 'W')
                    start = {i, j};
                else if (map[i][j] == 'H')
                    end = {i,j};

                else if (map[i][j] == 'X')
                    visited[i][j] = 1;
                
                else if (map[i][j] == '*'){
                    rain_init = {i,j};
                    visited[i][j] = 2;
                }    

            }
        }

        heuristic_map();


        return;
    }

    void print_visited(){
        cout << endl;
        for(int i =0 ; i < row ; ++i){
            for(int j =0 ; j < col ; ++j){
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }


    }


    void rain_mover(){

        for(int i = 0 ; i < row ; ++i){
            for(int j =0 ; j < col; ++j){


                if (visited[i][j] == 2){
                    for(int k =0 ; k < delta.size() ; ++k){
                        int x2 = i + delta[k][0];
                        int y2 = j + delta[k][1];
                        if ( x2 >= 0 && y2>=0 && x2 < row && y2<col ){
                            if (visited[x2][y2] == 0)
                               visited[x2][y2] = 3; 

                            if ((x2 == start[0] && y2==start[1])||(x2 ==end[0] && y2==end[1]))
                                visited[x2][y2] = 0; 

                        }
                    }
                }
            }
        }

        for(int i = 0 ; i < row ; ++i){
            for(int j =0 ; j < col; ++j){
                if (visited[i][j] == 3)
                    visited[i][j] = 2; 
            }
        }

    }


    int search(){


        bool resign = false;
        bool find = false;


        int x = start[0];
        int y = start[1];
        visited[x][y]=1;


        int h = heuris[x][y];
        int f = g+h;


        opens.push_back({f, h, g, x, y});


        while(resign != true && find != true){

            print_visited();

            sort(opens.begin(), opens.end(), [](auto a, auto b){
                if ( a[0] > b[0])
                    return true;
                else
                    return false;
            });
            vector<int> cur = opens.back();
            opens.pop_back();


            f = cur[0];
            g = cur[2];
            x = cur[3];
            y = cur[4];

            if ( x == end[0] && y == end[1]){
                find = true;
            }

            

            for(int i =0 ; i < delta.size() ; ++i){

                int x2 =  x + delta[i][0];
                int y2 = y + delta[i][1];
                int g2 = g+1;

                if ( x2>=0 && y2 >= 0 && x2 < row && y2 <col){
                    int h2 = heuris[x2][y2];
                    int f2 = g2 + h2;

                    if (visited[x2][y2] == 0){
                        opens.push_back({f2, h2, g2, x2, y2});
                        visited[x2][y2]=1;
                    }
                } 

            }

            if ( opens.empty()){
                resign = true;
                cout << "FAIL" << endl;
                exit(0);
            }

            rain_mover();
        }

        return g;
    }


    void heuristic_map(){



        for(int i =0 ; i < row ; ++i){
            for(int j =0 ; j < col ; ++ j){
                int manhatan = abs(i - end[0]) + abs(j-end[1]);
                heuris[i][j] = manhatan;
            }
        }


    }


    private:
    vector<int> start, end, rain_init;
    vector<vector<char>> map;
    int row, col;
    vector<vector<int>> opens;
    vector<vector<int>> delta = {
                        
                        {-1,0}, // up
                        {1,0}, // down
                        {0, 1}, // right
                        {0, -1} // left
                            };
    int g=0;
    vector<vector<int>> visited;  
    vector<vector<int>> heuris;                       


};

int main(int argc, char** argv)
{

    int R, C;
    cin >> R >> C;
    vector<vector<char>> map(R, vector<char>(C,' '));

    for(int i =0; i < R ; ++i){
        for(int j = 0; j <C ; ++j){
            cin >> map[i][j];
        }
    }


    finder path(map, R, C);
    cout << path.search() << endl;




 return 0;
}