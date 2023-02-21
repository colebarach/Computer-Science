#ifndef ALGEBRA_H
#define ALGEBRA_H

namespace ALGEBRA_CONSTANTS
{
    const int EXPONENTIAL_SERIES_RECURSION = 32;
    const double EXPONENTIAL_MIN_CUTOFF = -9.653;

    const int NATURAL_LOG_SERIES_RECURSION = 128;
}

// Functions ------------------------------------------------------------------------------------------------------------------

// Exponential
// - Calculates e^power
double Exponential(double power);

// Exponentiate
// - Calculates base^power
double Exponentiate(double base, double power);

// Natural Logarithm
// Calculates ln(exponential)
double NaturalLogarithm(double exponential);

// Logarithm
// - Calclulates log[base](exponential)
double Logarithm(double base, double exponential);

// Factorial
// - Calculates number!
double Factorial(double number);

// Modulus
// - Calculates number mod base
double Modulus(double number, double base);

// Is Prime
// - Returns True for a Prime Input, False Otherwise.
bool IsPrime(int number);

// Discrete Arithmetic --------------------------------------------------------------------------------------------------------

// Discrete Add
// - Adds a value to a discrete function
void Add(double* x, double* y, double value, int size);

// Discrete Subtract
// - Subtracts a value from a discrete function
void Subtract(double* x, double* y, double value, int size);

// Discrete Multiply
// - Multiplies a discrete function by a value
void Multiply(double* x, double* y, double value, int size);

// Discrete Divide
// - Divides a discrete function by a value
void Divide(double* x, double* y, double value, int size);

// Discrete Add
// - Adds two discrete functions.
// - Retains the size and domain of function 1
void Add(double* x1, double* y1, double* x2, double* y2, int size1, int size2);

// Discrete Subtract
// - Subtracts two discrete functions.
// - Retains the size and domain of function 1
void Subtract(double* x1, double* y1, double* x2, double* y2, int size1, int size2);

// Discrete Multiply
// - Multiplies two discrete functions.
// - Retains the size and domain of function 1
void Multiply(double* x1, double* y1, double* x2, double* y2, int size1, int size2);

// Discrete Divide
// - Divides two discrete functions
// - Retains the size and domain of function 1
void Divide(double* x1, double* y1, double* x2, double* y2, int size1, int size2);

#endif // ALGEBRA_H