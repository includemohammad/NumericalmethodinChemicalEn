#include <iostream>
#include <iomanip>
#include <cmath>
#include <Eigen/Dense>



#define N 3
using namespace std;

int main() {
    float a[N][N+1], x[N], aerr, maxerr, t, s, err;
    int i, j, itr, maxitr;

    // Initializing the array x
    for (i = 0; i < N; i++)
        x[i] = 0;

    cout << "Enter the elements of the augmented matrix rowwise:" << endl;
    for (i = 0; i < N; i++)
        for (j = 0; j < N + 1; j++)
            cin >> a[i][j];

    cout << "Enter the allowed error and maximum iterations:" << endl;
    cin >> aerr >> maxitr;

    cout << fixed;
    cout << "Iteration" << setw(8) << "x[1]" << setw(11) << "x[2]" << setw(11) << "x[3]" << endl;

    for (itr = 1; itr <= maxitr; itr++) {
        maxerr = 0;

        // Gauss-Seidel Iteration
        for (i = 0; i < N; i++) {
            s = 0;
            for (j = 0; j < N; j++) {
                if (j != i)
                    s += a[i][j] * x[j];
            }
            t = (a[i][N] - s) / a[i][i];
            err = fabs(x[i] - t);
            if (err > maxerr)
                maxerr = err;
            x[i] = t;
        }

        // Printing current iteration results
        cout << setw(5) << itr;
        for (i = 0; i < N; i++)
            cout << setw(11) << setprecision(4) << x[i];
        cout << endl;

        // Checking convergence
        if (maxerr < aerr) {
            cout << "Converges in " << itr << " iterations." << endl;
            for (i = 0; i < N; i++)
                cout << "x[" << i + 1 << "] = " << setprecision(4) << x[i] << endl;
            return 0;
        }
    }

    // If solution does not converge
    cout << "Solution does not converge, iterations not sufficient." << endl;
    return 1;
}
