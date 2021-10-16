#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(vector<vector<int> > monsters, vector<vector<int> > bullets)
{
    int answer = 0;

    sort(bullets.begin(), bullets.end());
    sort(monsters.begin(), monsters.end());

    bool isFind = false;
    for(int i =0 ; i < bullets.size(); ++i){

        int x_dir = bullets[i][0];
        int y_dir = bullets[i][1];
        double ratio;
        bool on_y_axis = false, on_x_axis = false;

        if (x_dir != 0 && y_dir !=0)
            ratio = (double)y_dir / x_dir;
        else{
            if (x_dir ==0){
                ratio =0;
                on_y_axis = true;   
            }    
            else{
                ratio =0;
                on_x_axis = true;
            }
        }        

        vector<int> checked (monsters.size(),0);
        for(int j =0 ; j < monsters.size(); ++j){

            if (checked[j] == 0){

                int incremental_x = (monsters[j][0]);
                double incremental_y;
                if (ratio > 0){
                    if (incremental_x < 0 )
                        incremental_y = 0;
                    else
                        incremental_y = (double)incremental_x*ratio;
                }    
                else if (ratio <0){
                    if(incremental_x > 0)
                        incremental_y = 0;
                    else
                        incremental_y = (double)incremental_x*ratio;
                }

                if (on_y_axis){
                    if(monsters[j][0] ==0){
                        isFind = true;
                        answer+=1;
                        checked[j] = 1;

                        break;
                    }
                }
                else if(on_x_axis){
                    if(monsters[j][1] == 0){
                        isFind = true;
                        answer+=1;
                        checked[j] = 1;

                        break;
                    }
                }
                else{
                    if (incremental_y == (double)monsters[j][1]){
                        isFind = true;
                        answer+=1;
                        checked[j] = 1;

                        break;
                    }
                }
            }
        }
    }

    if (!isFind)
        answer = -1;


    return answer;
}
