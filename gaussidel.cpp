#include <iostream>
#include <cmath>
using namespace std;

#define N 3

void gaussSeidelIteration(double A[N][N], double b[N], double x[N], int max_iterations, double tolerance)
{
    for (int iteration = 0; iteration < max_iterations; iteration++)
    {
        for (int i = 0; i < N; i++)
        {
            double sum = b[i];
            for (int j = 0; j < N; j++)
            {
                if (i != j)
                {
                    sum -= A[i][j] * x[j];
                }
            }
            x[i] = sum / A[i][i];
        }

        double max_error = 0.0;
        for (int i = 0; i < N; i++)
        {
            double error = fabs(x[i] - x[i]);
            if (error > max_error)
            {
                max_error = error;
            }
        }

        if (max_error < tolerance)
        {
            cout << "Converged after " << iteration + 1 << " iterations\n";
            break;
        }
    }

    if (max_iterations == 3)
    {
        cout << "Performed 3 iterations\n";
    }
    else if (max_iterations < 3)
    {
        cout << "Iterations not completed\n";
    }
    else
    {
        cout << "Maximum iterations reached\n";
    }
}

int main()
{
    double A[N][N] = {{4, -1, 0}, {-1, 4, -1}, {0, -1, 4}};
    double b[N] = {15, 10, 10};
    double x[N] = {0, 0, 0};
    int max_iterations = 3;
    double tolerance = 1e-6;

    gaussSeidelIteration(A, b, x, max_iterations, tolerance);

    cout << "Solution vector x:\n";
    for (int i = 0; i < N; i++)
    {
        cout << x[i] << "\n";
    }

    return 0;
}
