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

float S(float x, float n) {
   return pow(-1, n) * ((2 * pow(n, 2) + 1) / fact(2*n)) * pow(x, 2*n);
}

int main() {
    float x = 0.7;
    float n = 10;

    float res = 0;
    for (float i = n; i >= n; i--) {
        res += S(x,n);
    }

    cout << "Result: " << res << endl;

    return 0;
}
