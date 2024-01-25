#include <iostream>
#include <cmath>

using namespace std;

double g(double x)
{
    return x * x + 2;
}

double fixedPointIteration(double x0, double tol)
{
    double x1;
    do
    {
        x1 = g(x0);
        x0 = x1;
    } while (fabs(x1 - x0) > tol);
    return x1;
}

int main()
{
    double x0 = 0.5, tol = 0.0001;
    double root = fixedPointIteration(x0, tol);
    cout << "Root: " << root << endl;

    return 0;
}
