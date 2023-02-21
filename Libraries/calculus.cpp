// Header
#include "calculus.hpp"

// Discrete Calculus ----------------------------------------------------------------------------------------------------------
void Derive(double *x, double *y, int size)
{
    double dx = 0;
    double dy = 0;

    for(int index = 0; index < size - 1; index++)
    {
        dx = x[index + 1] - x[index];
        dy = y[index + 1] - y[index];

        x[index] += 0.5;
        y[index] = dy / dx;
    }

    x[size - 1] += dx / 2;
    y[size - 1] = 2*y[size-2] - y[size-3];
}

void IntegrateBackwards(double *x, double *y, int size)
{
    double xPrime = x[0];
    
    double dx = x[1] - xPrime;

    double yPrime = -y[0] * dx / 2;
    
    double yTemp = 0;
    
    yTemp = y[0];
    x[0] -= dx / 2;
    y[0] = yPrime + 0;
    yPrime = yTemp;
    
    for(int index = 1; index < size; index ++)
    {
        dx = x[index] - xPrime;

        xPrime = x[index];

        yTemp = y[index];

        x[index] -= dx / 2;
        
        y[index] = yPrime + y[index - 1];
        yPrime = yTemp;
    }
}

void IntegrateForwards(double *x, double *y, int size)
{
    x[0] = 0.5;
    y[0] = y[0] * 0.5;
    
    for(int index = 1; index < size; index ++)
    {
        x[index] += 0.5;
        y[index] = y[index] + y[index - 1];
    }
}

void Integrate(double *x, double *y, int size)
{
    IntegrateBackwards(x, y, size);
}