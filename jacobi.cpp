#include <iostream>
#include <cmath>

#define N 3

using namespace std;

void jacobiIteration(double A[N][N], double b[N], double x[N], int max_iterations, double tolerance)
{
    int iteration;
    double new_x[N];

    for (iteration = 0; iteration < max_iterations; iteration++)
    {
        for (int i = 0; i < N; i++)
        {
            new_x[i] = b[i];
            for (int j = 0; j < N; j++)
            {
                if (i != j)
                {
                    new_x[i] -= A[i][j] * x[j];
                }
            }
            new_x[i] /= A[i][i];
        }

        double max_error = 0.0;
        for (int i = 0; i < N; i++)
        {
            double error = fabs(new_x[i] - x[i]);
            if (error > max_error)
            {
                max_error = error;
            }
        }

        if (max_error < tolerance)
        {
            // Convergence reached
            cout << "Converged after " << iteration + 1 << " iterations\n";
            break;
        }

        // Update the solution vector
        for (int i = 0; i < N; i++)
        {
            x[i] = new_x[i];
        }
    }

    if (iteration == max_iterations)
    {
        cout << "Maximum iterations reached\n";
    }
}

int main()
{
    double A[N][N] = {{4, -1, 0}, {-1, 4, -1}, {0, -1, 4}};

    double b[N] = {15, 10, 10};

    double x[N] = {1, 1, 1};

    int max_iterations = 100;
    double tolerance = 1e-6;

    jacobiIteration(A, b, x, max_iterations, tolerance);

    cout << "Solution vector x:\n";
    for (int i = 0; i < N; i++)
    {
        cout << x[i] << "\n";
    }

    return 0;
}
