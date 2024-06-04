#include <iostream>
#include <cmath>
using namespace std;

double third_derivative_taylor(double (*f)(double), double x, double h) {
    // Approximates the third derivative of a function f using central difference method
    // and Taylor series expansion up to third degree.
    
    double third_derivative = (f(x - 2 * h) - 2 * f(x - h) + 2 * f(x + h) - f(x + 2 * h)) / (2 * pow(h, 3));
    return third_derivative;
}

// Example function
double my_function(double x) {
    return (0.1 * std::exp(0.02 * x) * std::sin(M_PI / 6 - M_PI / 3)) / (x - 1);
}

int main() {
    double x = 0.5; // Example point
    double h = 0.1; // Example step size

    // Calculate the third derivative of the example function at point x
    double third_derivative = third_derivative_taylor(my_function, x, h);
    
    std::cout << "Third derivative at x = " << x << " is: " << third_derivative << std::endl;
    
    return 0;
}
