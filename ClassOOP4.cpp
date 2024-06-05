#include <iostream>
#include <cmath>
using namespace std;

class MyMath {
private:
    int fact(int x) {
        int ans = 1;
        for (int i = 1; i <= x; i++) {
            ans *= i;
        }
        return ans;
    }

public:
    double coshx(double z) {
        double sum = 1.0; // Initialize sum with the first term
        for (int i = 1; i <= 5; i++) {
            sum += (pow(z, 2 * i) / fact(2 * i));
        }
        return sum;
    }
};

int main() {
    MyMath math;
    double x = 2.0; // Example value for x
    MyMath math2;
    double y = 3.0; // Example value for y

    cout << "cosh(" << x << ") = " << math.coshx(x) << endl;
    cout << "cosh(" << y << ") = " << math.coshx(y) << endl;

    return 0;
}
