#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    return x * x * x - 2 * x * x - 5;
}

double func_derivative(double x)
{
    return 3 * x * x - 4 * x;
}

double newtonRaphson(double x0, double tol)
{
    double x1;
    do
    {
        x1 = x0 - func(x0) / func_derivative(x0);
        x0 = x1;
    } while (fabs(func(x1)) > tol);
    return x1;
}

int main()
{
    double x0 = 1.5, tol = 0.0001;

    double root = newtonRaphson(x0, tol);
    cout << "Root: " << root << endl;

    return 0;
}
