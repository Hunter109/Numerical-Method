#include <iostream>

using namespace std;

double func(double x)
{
    return x * x * x + 2 * x * x - 3;
}

double simpsonsOneThird(double a, double b, int n)
{
    double h = (b - a) / n;
    double integral = func(a) + func(b);

    for (int i = 1; i < n; i += 2)
    {
        integral += 4 * func(a + i * h);
    }

    for (int i = 2; i < n - 1; i += 2)
    {
        integral += 2 * func(a + i * h);
    }

    return (h / 3) * integral;
}

int main()
{
    double a = 0.0, b = 2.0;

    int n = 4;

    double integral = simpsonsOneThird(a, b, n);
    cout << "Integral: " << integral << endl;

    return 0;
}
