#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return 2 * pow(x, 3) + pow(x, 2) - 20 * x + 12;
}

int main() {
    double a = 0, b = 1; // Initial interval [0, 1]
    double fa, fb, fc, c;
    double tol = 1e-6; // Tolerance for stopping the iteration

    fa = f(a);
    fb = f(b);

    // Check if there's a root in the interval [a, b]
    if (fa * fb < 0) {
        cout << "We have one root in the equation within this interval." << endl;
        
        // Regula Falsi method
        do {
            // Calculate the next approximation using linear interpolation
            c = a - (fa * (b - a)) / (fb - fa);
            fc = f(c);

            cout << "Approximation c = " << c << "\tf(c) = " << fc << endl;

            if (fa * fc < 0) {
                b = c;
                fb = fc;
            } else {
                a = c;
                fa = fc;
            }
        } while (fabs(b - a) > tol);

        cout << "The root is approximately at x = " << c << " with f(x) = " << fc << endl;
    } else {
        cout << "We don't have a root in this interval." << endl;
    }

    return 0;
}
