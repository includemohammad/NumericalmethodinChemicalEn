#include <iostream>
#include <cmath>


using namespace std;

// تابع اولیه f1(x1, x2)
double f1(double x1, double x2) {
    return exp(x1) + x1 * x2 - 1;
}

// تابع اولیه f2(x1, x2)
double f2(double x1, double x2) {
    return sin(x1 * x2) + x1 + x2 - 1;
}

// مشتق جزئی تابع اولیه f1 نسبت به x1
double df1_dx1(double x1, double x2) {
    return exp(x1) + x2;
}

// مشتق جزئی تابع اولیه f1 نسبت به x2
double df1_dx2(double x1, double x2) {
    return x1;
}

// مشتق جزئی تابع اولیه f2 نسبت به x1
double df2_dx1(double x1, double x2) {
    return x2 * cos(x1 * x2) + 1;
}

// مشتق جزئی تابع اولیه f2 نسبت به x2
double df2_dx2(double x1, double x2) {
    return x1 * cos(x1 * x2) + 1;
}

int main() {
    double x1, x2, xnew1, xnew2, df1dx1, df2dx1, df1dx2, df2dx2, fj1, fj2;
    double d, deltax1, deltax2;
    cout << "Please Enter your new ressume : (for x1,x2) " << endl;
    cin >> xnew1 >> xnew2;
    int n = 0;
    do {
        x1 = xnew1;
        x2 = xnew2;
        fj1 = f1(x1, x2);
        fj2 = f2(x1, x2);
        df1dx1 = df1_dx1(x1, x2);
        df1dx2 = df1_dx2(x1, x2);
        df2dx1 = df2_dx1(x1, x2);
        df2dx2 = df2_dx2(x1, x2);
        d = ((df1dx1 * df2dx2) - (df1dx2 * df2dx1));
        deltax1 = (((fj2 * df1dx2) - (fj1 * df2dx2)) / d);
        deltax2 = (((fj1 * df2dx1) - (fj2 * df1dx1)) / d);
        xnew1 = x1 + deltax1;
        xnew2 = x2 + deltax2;
        n = n + 1;
    } while (fabs(deltax1 - x1) > 1e-6 && fabs(deltax2 - x2) > 1e-6);
    cout << "The Roots of Equsations is : " << '\n';
    cout << "The frist Roots x1 :  " << xnew1 <<"         " <<"The secod Roots x2 : " << xnew2;
    return 0;
}
