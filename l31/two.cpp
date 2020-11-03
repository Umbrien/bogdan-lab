#include <iostream>
#include <cmath>

using namespace std;

float z(int x) {
    switch (x) {
        case 0:
            return sqrt(pow(cos(x),2) + 1);
        case 1:
            return (x-2) / (pow(x,2) + 2);
        case 2:
            return pow( pow(x-1, 2) + 3, 1.0/3.0);
        default:
            return 0;
    }
}

int main() {
    int x;

    cout << "Вариант 11" << endl;
    cout << "x: ";
    cin >> x;

    float res = z(x);
    cout << "z: " << res << endl;

    return 0;
}
