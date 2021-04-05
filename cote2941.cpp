#include <iostream>

int main(){
    std::string line;
    std::cin >> line;

    int count = 0;
    int i;

    for(i = 0 ; i < (line.length()-1) ; ++i){
        if (line[i] == 'c'){
            if (line[i+1] == '='){
                //std::cout << "č";
                count+=1;
                i+=1;
            }
            else if (line[i+1]=='-'){
                //std::cout << "ć";
                count+=1;
                i+=1;
            }
            else{
                count+=1;
                //std::cout << "c";
            }    
        }
        else if (line[i] == 'd'){
            if (line[i+1] == '-'){
                count+=1;
                i+=1;
                //std::cout << "đ";
            }
            else if (line[i+1] =='z'){
                if(i<(line.length()-2)){
                    if (line[i+2] == '='){
                        count+=1;
                        i+=2;
                        //std::cout << "dž";
                    }
                }
            }
            else{
                count+=1;
                //std::cout << 'd';
            }    
        }
        else if (line[i] == 'l'){
            if (line[i+1] == 'j'){
                count+=1;
                i+=1;
                //std::cout << "lj";
            }
            else{
                count+=1;
                //std::cout<<'l';
            }
        }
        else if (line[i] == 'n'){
            if (line[i+1] == 'j'){
                count+=1;
                i+=1;
                //std::cout << "nj";
            }
            else{
                count+=1;
                //std::cout << 'n';
                }
        }
        else if (line[i] == 's'){
            if (line[i+1] == '='){
                count+=1;
                i+=1;
                //std::cout << "š";
            }
            else{
                count+=1;
                //std::cout << 's';
                }
        }
        else if (line[i] == 'z'){
            if (line[i+1] == '='){
                count+=1;
                i+=1;
                //std::cout << "ž";
            }
            else{
                count+=1;
                //std::cout << 'z';
                }
        }
        else{
            if ((line[i] != '=') && (line[i] != '-')){
                count +=1;
                //std::cout<< line[i] ;
            }
        }
            
    }

    if (i < line.length()){
        if ((line[i] != '=') && (line[i] != '-')){
            count +=(line.length() - (i));
            //std::cout << line[i];
        }
    }
    std::cout << count ;
    return 0;
}