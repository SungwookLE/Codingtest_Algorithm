#include <iostream>
#include <vector>

class solver_11050{
    public:
    void insert_array(){
        std::cin >> N >> K;
    }

    void solver(){
        // nCk 가 이항계수를 말하는 것

        int num=1, den =1;
        for(int i = N ; i > (N-K) ; --i)
            num *=i;

        for(int i = K ; i>0 ; --i)
            den *=i;
        
        std::cout << num / den << std::endl;

    }

    private:
    int N, K;

};

int main(){
    solver_11050 solver;
    solver.insert_array();
    solver.solver();

    return 0;
}