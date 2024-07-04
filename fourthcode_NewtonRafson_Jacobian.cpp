#include <iostream>
#include <cmath>

using namespace std;

class Functions {
public:
    double f1(double x, double y) {
        return x + 3 * log(x) - pow(y, 2);
    }

    double f2(double x, double y) {
        return 2 * pow(x, 2) - x * y - 5 * x + 1;
    }

    double fpx1(double x, double y) {
        return 1 + 3 / x;
    }

    double fpy1(double x, double y) {
        return -2 * y;
    }

    double fpx2(double x, double y) {
        return 4 * x - y - 5;
    }

    double fpy2(double x, double y) {
        return -x;
    }
};

int main() {
    double x0 = 1, y0 = -2; // Initial guess
    double a1, a2, b1, b2, c1, c2;
    double tol = 1e-8;
    int max_iter = 100;
    bool converged = false;

    Functions Jacob_Newton;

    for (size_t iter=0; iter < max_iter; ++iter) {
        a1 = Jacob_Newton.fpx1(x0, y0);
        a2 = Jacob_Newton.fpy1(x0, y0);
        b1 = Jacob_Newton.fpx2(x0, y0);
        b2 = Jacob_Newton.fpy2(x0, y0);
        c1 = Jacob_Newton.f1(x0, y0);
        c2 = Jacob_Newton.f2(x0, y0);

        // Jacobian matrix
        double J[2][2] = {{a1, a2}, {b1, b2}};
        // Function values
        double F[2] = {c1,c2};

        // Compute the determinant of the Jacobian matrix
        double det = J[0][0] * J[1][1] - J[0][1] * J[1][0];
        if (det == 0) {
            cerr << "Matrix is singular, can't find its inverse" << endl;
            return -1;
        }

        // Compute the inverse of the Jacobian matrix
        double J_inv[2][2];
        J_inv[0][0] =  J[1][1] / det;
        J_inv[0][1] = -J[0][1] / det;
        J_inv[1][0] = -J[1][0] / det;
        J_inv[1][1] =  J[0][0] / det;

        // Newton-Raphson update
        double deltaX[2];
        deltaX[0] = J_inv[0][0] * F[0] + J_inv[0][1] * F[1];
        deltaX[1] = J_inv[1][0] * F[0] + J_inv[1][1] * F[1];

        // Update the guess
        x0 = x0 - deltaX[0];
        y0 = y0 - deltaX[1];

        // Check for convergence
        if (fabs(deltaX[0]) < tol && fabs(deltaX[1]) < tol) {
            converged = true;
            break;
        }
    }

    if (converged) {
        cout << "Converged to solution:\n";
        cout << "x: " << x0 << "\n";
        cout << "y: " << y0 << endl;
    } else {
        cout << "Did not converge within the maximum number of iterations" << endl;
    }

    return 0;
}
