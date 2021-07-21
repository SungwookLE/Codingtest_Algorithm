#include <iostream>
#include <vector>


typedef std::vector<std::vector<long long int>> matrix;

class MAT{
    public:
    MAT(int n){
        size = n;
        m.resize(n, std::vector<long long int>(n,0));
        init_M.resize(n, std::vector<long long int>(n,0));
    }
    
    void insert_matrix(){
        for(int i =0 ; i < size ; ++i){
            long long int temp;
            for(int j =0 ; j < size ; ++j){
                std::cin >> temp;
                m[i][j]=temp;
                init_M[i][j] = temp;
            }
        }
    }

    MAT& operator=(MAT A){
        for(int i = 0 ; i < size ; ++i){
            for(int j =0 ; j< size ; ++j){
                this->m[i][j] = A.m[i][j];
            }    
        }
        return *this;
    }

    MAT& operator+(MAT A){
        for(int i = 0 ; i < size ; ++i){
            for(int j =0 ; j< size ; ++j)
                this->m[i][j] += A.m[i][j];
        }
        return *this;
    }

    MAT& operator*(MAT A){
        MAT *temp = new MAT(size);
        for(int i = 0 ; i < size ; ++i){
            for(int j =0 ; j< size ; ++j){
                for (int k = 0 ; k < size ; ++k)
                    temp->m[i][j] += this->m[i][k]*A.m[k][j];
                
                temp->m[i][j] %= mod;
                temp->init_M[i][j] = this->m[i][j];
            }
        }
        *this = *temp;
        delete temp;

        return *this;
    }

    MAT& operator^(long long int B){
        if (B == 0){
            for(int i = 0 ; i < size ; ++i)
                for(int j =0 ; j< size ; ++j)
                    this->m[i][j] =1;
            return *this;
        }
        else if ( B ==1 ){
            return *this;
        }

        else if ( B % 2 ==1 ){
            MAT *temp1 = new MAT(size);
            MAT *temp2 = new MAT(size);
            MAT *init = new MAT(size);
            for(int i = 0 ; i < size ; ++i)
                for(int j =0 ; j< size ; ++j)
                    init->m[i][j] = this->init_M[i][j];

            B-=1;
            *temp1 = (*this)^B;
            *temp2 = (*init)*(*temp1);

            delete temp1, init;
            return *temp2;
        }
        else{
            MAT *temp1 = new MAT(size);
            MAT *temp2 = new MAT(size);

            B/=2;
            *temp1 = *this^B;
            *temp2 = (*temp1)*(*temp1);

            delete temp1;
            return *temp2;
        }
    }

    void show_matrix(){
        for(auto row: m){
            for(auto col : row)
            std::cout << col%mod << " ";
        std::cout << std::endl;
        }
    }

    private:
        matrix m;
        int size;
        long long int mod= 1000;
        matrix init_M;
};

int main(){
    int N;
    long long int B;

    std::cin >> N >> B;
    MAT A(N);
    A.insert_matrix();
    A = A^B;

    A.show_matrix();
}