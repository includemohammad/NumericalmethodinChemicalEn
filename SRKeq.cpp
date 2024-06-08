#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class SRKeq {
public:
    double SRKeq_a(double R, double Tc, double Pc);
    double SRKeq_b(double R, double Tc, double Pc);
    double SRKeq_Al(double Tr, double w);
    double SRK_v (double Z, double R, double P, double T);
};

double SRKeq::SRKeq_a(double R, double Tc, double Pc) {
    return 0.42747 * (pow(R, 2) * pow(Tc, 2.5)) / Pc;
}

double SRKeq::SRKeq_b(double R, double Tc, double Pc) {
    return 0.08664 * (R * Tc) / Pc;
}

double SRKeq::SRKeq_Al(double Tr, double w) {
    return (0.48 + 1.574 * w - 0.176 * pow(w, 2)) * (1 - pow(Tr, 0.5));
}

double SRKeq::SRK_v(double Z, double R, double P, double T) {
    return (Z * R * T) / P;
}

double f(double x, double a, double b) {
    return pow(x, 3) - (1 - b) * pow(x, 2) + (a - 3 * pow(b, 2) - 2 * b) * x - (a * b - pow(b, 2) - pow(b, 3));
}

double f_prime(double x, double a, double b) {
    return 3 * pow(x, 2) - 2 * (1 - b) * x + (a - 3 * pow(b, 2) - 2 * b);
}

double f2(double T1, double T0, double R, double A1, double A2, double B1, double B2, double P, double del1, double del2, double fy, double noh1, double noh2) {
    return del1 / (R * T0) + 1304.655 * (1 / T1 - 1 / T0) + 9.217 * (log(T1) - log(T0)) - 0.00847 * (T1 - T0) + del2 * P / ((R * T1) - (noh1 * log(1 + (A1 / T1) * exp(B1 / T1))) * (1 / 101325) * fy) + (noh2 * log(1 + (A2 / T1) * exp((B2 / T1) * (1 / 101325) * fy)));
}

double f2_prime(double T1, double R, double P, double del1) {
    return (-1304.655) / (pow(T1, 2)) + 9.217 / T1 - 0.00847 + del1 * P / (R * pow(T1, 2));
}

int main() {
    SRKeq srk;
    double w = 0.0115; // Acentric factor
    double Ti = 300; // Initial temperature in Kelvin
    double R = 8.314; // Universal gas constant
    double Tc = 190.564; // Critical Temperature
    double Pc = 4599000; // Critical Pressure
    double T0 = 273.15; 

    double a = srk.SRKeq_a(R, Tc, Pc);
    double b = srk.SRKeq_b(R, Tc, Pc);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    double Pi;
    cout << "Please enter the pressure (KPa): ";
    cin >> Pi;

    double T1 = Ti;
    double Tr = T1 / Tc; // Reduced Temperature
    double A = (srk.SRKeq_Al(Tr, w) * a * Pi) / (pow(R, 2) * pow(T1, 2));
    double B = (b * Pi) / (R * T1);

    cout << "A parameter is: " << A << endl;
    cout << "B parameter is: " << B << endl;

    double x, x1, e;
    cout << "Please Enter your initial guess x: ";
    cin >> x;
    cout << "Please Enter your Accuracy epsilon e: ";
    cin >> e;
    cout << setw(10) << "x{i}" << setw(15) << "x{i+1}" << setw(20) << "|x{i+1} - x{i}" << endl;

    int iteration = 0;
    const int maxIterations = 100;

    do {
        x1 = x;
        double fx = f(x, A, B);
        double fx1 = f_prime(x1, A, B);
        if (fabs(fx1) < 1e-6) {
            cout << "Warning: Derivative is close to zero. Method may not converge." << endl;
            break;
        }
        x = x1 - (fx / fx1);
        cout << setw(10) << x1 << setw(15) << x << setw(20) << fabs(x1 - x) << endl;
        iteration++;
    } while (fabs(x1 - x) >= e && iteration < maxIterations);

    if (iteration >= maxIterations) {
        cout << "Warning: Maximum iterations reached. Method may not have converged." << endl;
    }

    cout << "Root of the equation is: " << x << endl;

    double v = srk.SRK_v(x, R, Pi, T1);
    double phi = exp(log(v / (v - b))) + (a / (b * R * T1)) * log(v / (v + b)) - log(x) + x - 1;
    double fi = Pi * phi;

    double noh1 = 2.0 / 46.0;
    double noh2 = 6.0 / 46.0;
    double deltah0 = -4858.9;
    double deltamh0 = 1263.6;
    double deltanoh0h = 4.6e-6;
    double A1 = 3.7237e-3;
    double B1 = 2.7088e3;
    double A2 = 1.8372e-2;
    double B2 = 2.7379e3;
    double t, t1, es;

    cout << "Please Enter your initial guess for T : ";
    cin >> t;
    cout << "Please Enter your Accuracy epsilon e: ";
    cin >> es;
    cout << setw(10) << "T{i}" << setw(15) << "T{i+1}" << setw(20) << "|T{i+1} - T{i}" << endl;

    int iteration2 = 0;
    const int maxIterations2 = 100;

    do {
        t1 = t;
        double fg = f2(t, T0, R, A1, A2, B1, B2, Pi, deltamh0, deltanoh0h, fi, noh1, noh2);
        double fg1 = f2_prime(t, R, Pi, deltah0);
        if (fabs(fg1) < 1e-6) {
            cout << "Warning: Derivative is close to zero. Method may not converge." << endl;
            break;
        }
        t = t1 - (fg / fg1);
        cout << setw(10) << t1 << setw(15) << t << setw(20) << fabs(t1 - t) << endl;
        iteration2++;
    } while (fabs(t1 - t) >= es && iteration2 < maxIterations2);

    if (iteration2 >= maxIterations2) {
        cout << "Warning: Maximum iterations reached. Method may not have converged." << endl;
    }

    cout << "Root of the equation is: " << t << endl;

    return 0;
}
