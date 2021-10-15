#include <iostream>
#include <vector>

class solver_1934{
    public:

    void feed_and_solve(){
        int n;
        std::cin >> n;
        int a, b;
        for(int i =0 ; i < n ; ++i){
            std::cin >> a >> b;
            solver(a,b);
        }


    }
    void solver(int a, int b){

        int answer = lcm(a, b, gcd(a,b));

        std::cout << answer << std::endl;
        
    }

    int gcd(int a, int b){ // 최대공약수
        while (b > 0 ){
            int temp = b;

            b = a % b;
            a = temp;
        }
        //REF: https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=writer0713&logNo=221133124302
        //유클리드호제법
        return a;
    }

    int lcm(int a, int b, int gcd_value){ // 최대공약수

        int answer = a*b / gcd_value;
        return answer;
    }


    private:


};

int main(){
    solver_1934 solver;
    solver.feed_and_solve();


    return 0;
}

// 최소공배수구하기, 유클리드 알고리즘 이용하여 빠르게