#ifndef CALCULUS_H
#define CALCULUS_H

// Discrete Calculus ----------------------------------------------------------------------------------------------------------

// Derive
// - Calculates the derivative of a discrete function
// - Increments x-values by dx/2
// - Will lose the terminating element.
void Derive(double *x, double *y, int size);

// Integrate
// - Calculates the integral of a discrete function
// - Decrements x-values by dx/2
// - Will add a starting value of 0
// - Use addition to add integration constant
void Integrate(double *x, double *y, int size);

#endif // CALCULUS_H