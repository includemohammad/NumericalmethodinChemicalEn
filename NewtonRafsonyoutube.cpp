#include <iostream>
#include <cmath>
#include <iomanip>
#include "Eigen/Jacobi"
#define eps 0.000375

using namespace std;

double Re(double Rho, double V, double D, double mu) {
    return ((Rho * V * D) / mu);
}

double f(double x, double Re) {
    return ((1 / sqrt(x)) + 2 * log10((eps / 3.7) + (2.51 / (Re * sqrt(x)))));
}

double fprime(double x, double Re) {
    return ((-0.5 * pow(x, -1.5)) + ((2 * 1.83e-4 * (-0.5 * pow(x, -1.5))) / (1.01e-4 + 1.83e-4 * pow(x, -1.5))));
}

int main() {
    double Rho, V, D, mu;
    cout << "Please Enter your Rho, V, D & mu: ";
    cin >> Rho >> V >> D >> mu;
    double Re_val = Re(Rho, V, D, mu);
    double x, x1, e, fx, fx1;
    cout << "Please Enter your initial guess x: ";
    cin >> x;
    cout << "Please Enter your Accuracy epsilon e: ";
    cin >> e;
    cout << setw(10) << "x{i}" << setw(15) << "x{i+1}" << setw(20) << "|x{i+1} - x{i}" << endl;

    do {
        x1 = x;
        fx = f(x, Re_val);
        fx1 = fprime(x, Re_val);
        x = (x1 - (fx / fx1));
        cout << setw(10) << x1 << setw(15) << x << setw(20) << fabs(f(x1, Re_val) - f(x, Re_val)) << endl;
    } while (fabs(f(x1, Re_val) - f(x, Re_val)) >= e);

    cout << "Root of the equation is: " << x << endl;
    return 0;
}
