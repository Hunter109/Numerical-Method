#include <iostream>

using namespace std;

double func(double x)
{
    return x * x * x + 2 * x * x - 3;
}

double simpsonsThreeEighth(double a, double b, int n)
{
    double h = (b - a) / n;
    double integral = func(a) + func(b);

    for (int i = 1; i < n; i += 3)
    {
        integral += 3 * (func(a + i * h) + func(a + (i + 1) * h));
    }

    for (int i = 3; i < n - 2; i += 3)
    {
        integral += 2 * func(a + i * h);
    }

    return (3 * h / 8) * integral;
}

int main()
{
    double a = 0.0, b = 2.0;

    int n = 6;

    double integral = simpsonsThreeEighth(a, b, n);
    cout << "Integral: " << integral << endl;

    return 0;
}
