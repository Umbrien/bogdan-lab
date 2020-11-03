#include <iostream>

using namespace std;

bool z(bool a, bool b, float x, float y) {
    return a and b or x <= 1.3 and y >= 1.5 or not (a or b);
}

int main() {
    bool a = true;
    cin >> a;
    bool b = true;
    cin >> b;
    float x = 1.5;
    cin >> x;
    float y = 2.5;
    cin >> y;

    bool res = z(a,b,x,y);
    cout << res << endl;

    return 0;
}
