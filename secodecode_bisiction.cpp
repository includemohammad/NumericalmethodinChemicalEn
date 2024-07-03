#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return 1 / (x + 1);
}

int main() {
    double a[2] = { -0.5, -4 };
    double tol = 1e-6;  // Tolerance for stopping the iteration
    double b, fa, fb, fc;

    // Print the initial values
    for (size_t i = 0; i <= 1; i++) {
        cout << "a[" << i << "] = " << a[i] << "\tf(x) = " << f(a[i]) << endl;
    }

    // Check if there's a root in the interval [a[0], a[1]]
    fa = f(a[0]);
    fb = f(a[1]);
    if (fa * fb < 0) {
        cout << "We have one root in the equation within this interval." << endl;
        
        // Bisection method
        while (fabs(a[1] - a[0]) > tol) {
            b = (a[0] + a[1]) / 2;  // Midpoint
            fc = f(b);

            cout << "Midpoint b = " << b << "\tf(b) = " << fc << endl;

            if (fa * fc < 0) {
                a[1] = b;
                fb = fc;
            } else {
                a[0] = b;
                fa = fc;
            }
        }

        cout << "The root is approximately at x = " << b << " with f(x) = " << fc << endl;
    } else {
        cout << "We don't have a root in this interval." << endl;
    }

    return 0;
}
