#include <iostream>

int main(){

    int x, y, w, h;
    std::cin >> x >> y >> w >> h;
    int min_w = 0, min_h =0;
    int horizontal;

    if (abs((x-w)) > abs((x-min_w)))
        horizontal=abs((x-min_w));
    else
        horizontal=abs((x-w));

    int vertical = (abs((y-h))>abs((y-min_h)))? abs((y-min_h)):abs((y-h));

    if (horizontal > vertical)
        std::cout << vertical <<"\n";
    else
        std::cout << horizontal<<"\n";


    return 0;
}