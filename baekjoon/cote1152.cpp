#include <iostream>
#include <vector>

int main(){

    char line[1000001];
    std::cin.getline(line, 1000001);

    int idx =0;
    int count =0;
    bool cont_flag = false;
    while(line[idx] != '\0'){
        if (cont_flag == false){
        if (line[idx] != ' ' ){
            cont_flag = true;
           // std::cout << line[idx] << std::endl;
            }
        }
        else{
         if (line[idx] == ' '){
            cont_flag = false;
            count += 1;
            }
        }
        idx++;
    }

    if (line[idx-1] == ' ')
        std::cout << count << std::endl;
    else
        std::cout << count+1 << std::endl;
    return 0;
}