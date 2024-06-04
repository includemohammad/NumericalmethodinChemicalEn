#include <iostream>
#include <cmath>

using namespace std;

class Equation {
private:
    double x1, x2;

public:
    Equation(double initial_x1, double initial_x2) : x1(initial_x1), x2(initial_x2) {}

    double f1() {
        return exp(x1) + x1 * x2 - 1;
    }

    double f2() {
        return sin(x1 * x2) + x1 + x2 - 1;
    }

    double df1_dx1() {
        return exp(x1) + x2;
    }

    double df1_dx2() {
        return x1;
    }

    double df2_dx1() {
        return x2 * cos(x1 * x2) + 1;
    }

    double df2_dx2() {
        return x1 * cos(x1 * x2) + 1;
    }

    double abs(double val) {
        return (val < 0) ? -val : val;
    }

    void solve() {
        double xnew1 = x1, xnew2 = x2;
        double deltax1, deltax2; // تعریف deltax1 و deltax2
        int n = 0;
        do {
            x1 = xnew1;
            x2 = xnew2;
            double fj1 = f1();
            double fj2 = f2();
            double df1dx1 = df1_dx1();
            double df1dx2 = df1_dx2();
            double df2dx1 = df2_dx1();
            double df2dx2 = df2_dx2();
            double d = ((df1dx1 * df2dx2) - (df1dx2 * df2dx1));
            deltax1 = (((fj2 * df1dx2) - (fj1 * df2dx2)) / d);
            deltax2 = (((fj1 * df2dx1) - (fj2 * df1dx1)) / d);
            xnew1 = x1 + deltax1;
            xnew2 = x2 + deltax2;
            n = n + 1;
        } while (abs(deltax1 - x1) > 1e-6 && abs(deltax2 - x2) > 1e-6);
        cout << "The Roots of Equations are: " << '\n';
        cout << "The first Root x1:  " << xnew1 << '\t' << "The second Root x2: " << xnew2 << endl;
        cout << "Number of iterations: " << n << endl;
    }
};

int main() {
    double x1, x2;
    cout << "Please Enter your new resume: (for x1,x2) " << endl;
    cin >> x1 >> x2;
    Equation eq(x1, x2);
    eq.solve();
    return 0;
}
