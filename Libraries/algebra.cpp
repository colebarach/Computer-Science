// Header
#include "algebra.hpp"

// Functions ------------------------------------------------------------------------------------------------------------------
double Exponential(double power)
{
    double sum = 0;

    if(power < ALGEBRA_CONSTANTS::EXPONENTIAL_MIN_CUTOFF) return 0;

    for(int k = 0; k < ALGEBRA_CONSTANTS::EXPONENTIAL_SERIES_RECURSION; k++)
    {
        double z = 1;
        for(int p = 0; p < k; p++)
        {
            z *= power;
        }

        sum += z / Factorial(k);
    }

    return sum;
}

double Exponentiate(double base, double power)
{
    power *= NaturalLogarithm(base);
    return Exponential(power);
}

double NaturalLogarithm(double exponential)
{
    double y = (exponential - 1) / (exponential + 1);
    double sum = 0;
    
    for(int n = 0; n < ALGEBRA_CONSTANTS::NATURAL_LOG_SERIES_RECURSION; n++)
    {
        double yPower = 1;
        for(int power = 0; power < 2*n; power++)
        {
            yPower *= y;
        }
        sum += yPower / (2*n + 1);
    }

    return sum * 2 * y;
}

double Logarithm(double base, double exponential)
{
    return NaturalLogarithm(exponential) / NaturalLogarithm(base);
}

double Factorial(double number)
{
    double product = 1;

    for(int count = 1; count <= number; count++)
    {
        product *= count;
    }

    return product;
}

double Modulus(double number, double base)
{
    while(number >= base)
    {
        number -= base;
    }
    while(number < 0)
    {
        number += base;
    }

    return number;
}

bool IsPrime(int number)
{
    // 1 is Not Prime
    if(number == 1) return false;
    // Check all possible divisors
    for(int divisor = 2; divisor < number; divisor++)
    {
        int remainder = number % divisor;
        if(remainder == 0) return false;
    }
    return true;
}

// Discrete Arithmetic --------------------------------------------------------------------------------------------------------
void Add(double* x, double* y, double value, int size)
{
    for(int index = 0; index < size; index++)
    {
        y[index] += value;
    }
}

void Subtract(double* x, double* y, double value, int size)
{
    for(int index = 0; index < size; index++)
    {
        y[index] -= value;
    }
}

void Multiply(double* x, double* y, double value, int size)
{
    for(int index = 0; index < size; index++)
    {
        y[index] *= value;
    }
}

void Divide(double* x, double* y, double value, int size)
{
    for(int index = 0; index < size; index++)
    {
        y[index] /= value;
    }
}

void Add(double* x1, double* y1, double* x2, double* y2, int size1, int size2)
{
    for(int t = 0; t < size1; t++)
    {
        int lowerBound = 0;
        int upperBound = size2-1;

        for(int s = 0; s < size2; s++)
        {
            if(x2[s] >= x2[lowerBound] && x2[s] <= x1[t])
            {
                lowerBound = s;
            }
            if(x2[s] < x2[upperBound] && x2[s] >= x1[t])
            {
                upperBound = s;
            }
        }

        if(x1[t] < x2[lowerBound] || x1[t] > x2[upperBound])
        {
            continue;
        }

        if(x2[lowerBound] == x2[upperBound])
        {
            y1[t] += y2[upperBound];
            continue;
        }

        double lerp = (x1[t] - x2[lowerBound]) / (x2[upperBound] - x2[lowerBound]);
        y1[t] += lerp * (y2[upperBound] - y2[lowerBound]) + y2[lowerBound];
    }
}

void Subtract(double* x1, double* y1, double* x2, double* y2, int size1, int size2)
{
    for(int t = 0; t < size1; t++)
    {
        int lowerBound = 0;
        int upperBound = size2-1;

        for(int s = 0; s < size2; s++)
        {
            if(x2[s] >= x2[lowerBound] && x2[s] <= x1[t])
            {
                lowerBound = s;
            }
            if(x2[s] < x2[upperBound] && x2[s] >= x1[t])
            {
                upperBound = s;
            }
        }

        if(x1[t] < x2[lowerBound] || x1[t] > x2[upperBound])
        {
            continue;
        }

        if(x2[lowerBound] == x2[upperBound])
        {
            y1[t] -= y2[upperBound];
            continue;
        }

        double lerp = (x1[t] - x2[lowerBound]) / (x2[upperBound] - x2[lowerBound]);
        y1[t] -= lerp * (y2[upperBound] - y2[lowerBound]) + y2[lowerBound];
    }
}

void Multiply(double* x1, double* y1, double* x2, double* y2, int size1, int size2)
{
    for(int t = 0; t < size1; t++)
    {
        int lowerBound = 0;
        int upperBound = size2-1;

        for(int s = 0; s < size2; s++)
        {
            if(x2[s] >= x2[lowerBound] && x2[s] <= x1[t])
            {
                lowerBound = s;
            }
            if(x2[s] < x2[upperBound] && x2[s] >= x1[t])
            {
                upperBound = s;
            }
        }

        if(x1[t] < x2[lowerBound] || x1[t] > x2[upperBound])
        {
            continue;
        }

        if(x2[lowerBound] == x2[upperBound])
        {
            y1[t] *= y2[upperBound];
            continue;
        }

        double lerp = (x1[t] - x2[lowerBound]) / (x2[upperBound] - x2[lowerBound]);
        y1[t] *= lerp * (y2[upperBound] - y2[lowerBound]) + y2[lowerBound];
    }
}

void Divide(double* x1, double* y1, double* x2, double* y2, int size1, int size2)
{
    for(int t = 0; t < size1; t++)
    {
        int lowerBound = 0;
        int upperBound = size2-1;

        for(int s = 0; s < size2; s++)
        {
            if(x2[s] >= x2[lowerBound] && x2[s] <= x1[t])
            {
                lowerBound = s;
            }
            if(x2[s] < x2[upperBound] && x2[s] >= x1[t])
            {
                upperBound = s;
            }
        }

        if(x1[t] < x2[lowerBound] || x1[t] > x2[upperBound])
        {
            continue;
        }

        if(x2[lowerBound] == x2[upperBound])
        {
            y1[t] /= y2[upperBound];
            continue;
        }

        double lerp = (x1[t] - x2[lowerBound]) / (x2[upperBound] - x2[lowerBound]);
        y1[t] /= lerp * (y2[upperBound] - y2[lowerBound]) + y2[lowerBound];
    }
}