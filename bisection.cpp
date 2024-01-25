#include <iostream>
#include <cmath>

using namespace std;

double myFunction(double x)
{
    return x * x * x - 2 * x - 5;
}

double bisection(double a, double b, double tol)
{
    double c;
    while ((b - a) >= tol)
    {
        c = (a + b) / 2;
        if (myFunction(c) == 0.0)
        {
            break;
        }
        else if (myFunction(c) * myFunction(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    return c;
}

int main()
{
    double a = 1.0, b = 3.0, tol = 0.01;
    cout << "Initial interval: [" << a << ", " << b << "]\n";

    double root = bisection(a, b, tol);
    cout << " The root is: " << root << endl;
    return 0;
}
