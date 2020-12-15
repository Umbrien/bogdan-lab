#include <iostream>

using namespace std;

int main() {
    float A[2][4] = {
        {1.5, 4.5, 6.2, 8.1},
        {2.1, -3.5, 2.7, 9.4}
    };
    float B[2][4];
    float E = 4.5;

    int b_index_counter = 0;

    for (int i = 0; i < 2; ++i) {
        for( int j = 0; j < 4; ++j ) {
            if (A[i][j] < E) {
                B[i][b_index_counter] = A[i][j];
                ++b_index_counter;
            }
        }
    }

    cout << "B:" << endl;
    cout << B[0][0] << endl;
    for (int i=1; i < b_index_counter; ++i) {
        cout << B[1][i] << ", ";
    }
    cout << endl;

    return 0;
}
