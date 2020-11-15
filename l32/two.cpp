#include <iostream>
#include <cmath>

using namespace std;

long double fact(int N)
{
    if(N < 0)
        return 0; 
    if (N == 0)
        return 1;
    else 
        return N * fact(N - 1); 
}

float s(float x, float n) {
   return pow(-1, n) * ((2 * pow(n, 2) + 1) / fact(2*n)) * pow(x, 2*n);
}

float S() {
    float x = 0.7;
    float n = 10;

    float r = 0;
    for (float i = n; i >= n; i--) {
        r += s(x,n);
    }

    return r;
}

int main() {
    float Ss = S();
    float delta = pow(10, -4);
    float x[64] = {0.1, 0.3, 0.5, 0.7, 0.9};

    float res = 0;
    float s = Ss;
    for (int i = 0; i < 5; i++) {
        if (abs(s) < delta)
            break;
        
        res += x[i];
        s--;
    }

    cout << "Result: " << res << endl;

    return 0;
}