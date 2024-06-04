#include <iostream>
#include "Eigen/Dense"

using namespace Eigen;

int main() {
    MatrixXd A(3, 3);
    VectorXd b(3);

    // مقداردهی اولیه به ماتریس A و بردار b
    A << 2, 1, -1,
         -3, -1, 2,
         -2, 1, 2;

    b << 8, -11, -3;

    // حل دستگاه معادلات خطی با استفاده از روش حذفی گاوس
    VectorXd x = A.colPivHouseholderQr().solve(b);

    // چاپ جواب
    std::cout << "Solution:\n" << x << std::endl;

    return 0;
}