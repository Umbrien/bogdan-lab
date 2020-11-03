#include <iostream>

using namespace std;

class Ellipse {
    public:
        double xAxis, yAxis;
        Ellipse(double axAxis, double ayAxis) {
            xAxis = axAxis;
            yAxis = ayAxis;
        }

        bool isInside(double x, double y) {
            //double a = this->xAxis/2;
            //double b = this->yAxis/2;
            double a = this->xAxis;
            double b = this->yAxis;

            return ((x*x)/(a*a) + (y*y)/(b*b) <= 1.);
        }
};


int main() {
    double x;
    double y;
    Ellipse e1(1,2);
    Ellipse e2(2,1);

    cout << "Вариант 11" << endl;
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;

    //bool res = z(x);
    //cout << "z: " << res << endl;

    cout << e1.isInside(x,y);
    cout << e2.isInside(x,y);

    return 0;
}
