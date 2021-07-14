#include <iostream>
#include <vector>

//분할 정복
class solver_1629{
public:
void insert(){
    std::cin >> A>> B >> C;
}

long long int solver(long long int a, long long int b, long long int c){

    a = a % c;

    if ( b ==0 ) return 1;
    else if ( b==1) return a;
    else if ( b%2 ==0){
        long long int temp = solver(a, b/2, c);
        return temp*temp%c;
    }
    else{
        return a * solver(a, b-1, c)%c;
    }

}
    long long int A,B,C;

private:

};


int main(){
    solver_1629 solver;

    solver.insert();
    std::cout << solver.solver(solver.A, solver.B, solver.C) << std::endl;



    return 0;
}