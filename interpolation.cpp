#include <iostream>

using namespace std;

double lagrangeInterpolation(double x[], double y[], int n, double xi)
{
    double result = 0.0;
    for (int i = 0; i < n; i++)
    {
        double term = y[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                term = term * (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main()
{
    double x[] = {1, 2, 4, 5};
    double y[] = {3, 5, 9, 11};

    int n = sizeof(x) / sizeof(x[0]);

    double xi = 3.0;

    double interpolatedValue = lagrangeInterpolation(x, y, n, xi);
    cout << "Interpolated value at x = " << xi << ": " << interpolatedValue << endl;

    return 0;
}
