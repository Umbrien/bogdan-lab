#include <iostream>
#include <cmath>

using namespace std;

float y(float a, float x) {
    if (x <= -1) {
        return a * cos(x + 1) + a;
    } else if (x > -1) {
        return a * pow(x+2, 3/2);
    }
}

int main() {
    float x;
    float a;

    cout << "x: ";
    cin >> x;
    cout << "a: ";
    cin >> a;

    float res = y(a,x);
    cout << "y: " << res << endl;

    return 0;
}
