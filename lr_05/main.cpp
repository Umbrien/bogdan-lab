#include <iostream>

using namespace std;

int main() {
    float A[9] = {1.2, 5, 7, 9.3, 6.9, -8, -1.5, 2.5, 2.8};
    float F[9];
    float C = -3.5;
    float D = 6;

    int index_counter = 0;

    for (int i = 0; i < 9; i++) {
        if (C <= A[i] && A[i] < D) {
            F[index_counter] = A[i];
            ++index_counter;
        }
    }

    for (int i=0; i < index_counter; ++i) {
        cout << F[i] <<endl;
    }


    return 0;
}
