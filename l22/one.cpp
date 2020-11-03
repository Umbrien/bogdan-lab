#include <iostream>
#include <cmath>

using namespace std;

float y(float a, float x, float beta) {
    return pow(M_E,-x) + log(fabs(acos(x)))+atan(x)-1.2*pow(cos(x),2) / sqrt(a*x)*(a*pow(M_E, a*x) + 3.5*pow(10, -5)*a*x) - pow(x+pow(a,2) - 0.3*pow(10,-1.5),1/3) + log10(beta);
}

int main() {
    float a = 0.5;
    cin >> a;
    float x = 3.4*pow(10,-4);
    cin >> x;
    float beta = 1.65;
    cin >> beta;

    float res = y(a,x,beta);
    cout << res << endl;

    return 0;
}
