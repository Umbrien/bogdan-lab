#include <iostream>
#include <cmath>

using namespace std;

bool z(float x, float y) {
    return pow(x,2) + pow(y,2) <= 1 and x >= 0 or y <= 0;
}

int main() {
    float x = 1.5;
    cin >> x;
    float y = 2.5;
    cin >> y;

    bool res = z(x,y);
    cout << res << endl;

    return 0;
}
