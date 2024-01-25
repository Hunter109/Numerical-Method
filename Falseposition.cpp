#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    return x * x - 4;
}

double falsePosition(double a, double b, double tol)
{
    double c;
    do
    {
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));
        if (func(c) == 0.0)
        {
            break;
        }
        else if (func(c) * func(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    } while (fabs(b - a) >= tol);
    return c;
}

int main()
{
    double a = 1.0, b = 3.0, tol = 0.0001;
    cout << "Initial interval: [" << a << ", " << b << "]\n";
    double root = falsePosition(a, b, tol);
    cout << "Root: " << root << "\n";
    return 0;
}
