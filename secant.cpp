#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    return cos(x) - x;
}

double secant(double x0, double x1, double tol)
{
    double x2;
    do
    {
        x2 = x1 - (func(x1) * (x1 - x0)) / (func(x1) - func(x0));
        x0 = x1;
        x1 = x2;
    } while (fabs(func(x2)) > tol);
    return x2;
}

int main()
{
    double x0 = 0.5, x1 = 1.0, tol = 0.0001;
    double root = secant(x0, x1, tol);
    cout << "Root: " << root << endl;

    return 0;
}
