// Header
#include "trigonometry.hpp"

// Includes
#include "algebra.hpp"

double cosine(double theta)
{
    double cumulative = 0;

    theta = Modulus(theta, TRIGONOMETRY_CONSTANTS::TAU);

    for(int index = 0; index < TRIGONOMETRY_CONSTANTS::SINUSOIDAL_SERIES_RECURSION; index++)
    {
        if(index % 2 == 0)
        {
            // cumulative += exponent(theta, 2*index) / Factorial(2*index);
        }
        else
        {
            // cumulative -= exponent(theta, 2*index) / Factorial(2*index);
        }
    }
    
    return cumulative;
}