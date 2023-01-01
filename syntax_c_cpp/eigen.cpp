#include <iostream>
#include <vector>
#include "Eigen/Dense"

int main(){



    Eigen::MatrixXd M = Eigen::MatrixXd::Zero(4,3);

    M << 1,2,3,4,5,6,7,8,9,10,11,12;

    std::cout << M.col(0) << std::endl; //1, 4, 7,10
    std::cout << M.row(0) << std::endl; //1,2,3

    std::cout << M.cols() << std::endl; // 3
    std::cout << M.rows() << std::endl; // 4

}