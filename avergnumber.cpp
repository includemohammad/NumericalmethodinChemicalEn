#include <iostream>
using namespace std;

float averg(float x, float y, float z, float w, float r) {
    return (x + y + z + w + r) / 5;
}

int main() {
    float x, y, z, w, r;
    cout << "Enter number of course: ";
    cin >> x >> y >> z >> w >> r;
    cout << "Average is: " << averg(x, y, z, w, r) << endl;

    
    float highest = x;
    if (y > highest) highest = y;
    if (z > highest) highest = z;
    if (w > highest) highest = w;
    if (r > highest) highest = r;

 
    switch (static_cast<int>(highest)) {
        case 20:
            cout << "The Highest is 20" << endl;
            break;
        case 19:
            cout << "The Highest is 19" << endl;
            break;

        default:
            cout << "dont have High" << endl;
    }

    return 0;
}
