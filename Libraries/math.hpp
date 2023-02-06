// Math
// - Collection of Standard Math Functions

#ifndef MATH_H
#define MATH_H

#include <random>
#include <time.h>

// Random Number Seeding
// - Must be called to initialize random number generation
// - Seeds the <random> library
void SeedRandom();
// Get Random Int
// - Called when a random integer is required
// - Returns a pseudorandom number between 0 and max
int RandomInt(int max);
// Get Random Bool
// - Called when a random boolean is required
// - Returns a pseudorandom boolean
bool RandomBool();
// Get Random Char
// - Called when a random character is required
// - Returns a pseudorandom character
char RandomChar(std::string options);

// Is Prime
// - Returns True for a Prime Input, False Otherwise.
bool IsPrime(int number);

// Bubble Sort
// - Call to sort the elements of an arry
// - Sorts the elements from least to greatest
void BubbleSort(int *data, int size);
void BubbleSort(double *data, int size);

// Push to Front of Array
// - Creates a new Array with a 0 pushed to the first element
// - Returns a pointer to the dynamic array
// - Note: the dynamic array must be deallocated after use
int *PushToFrontArray(int array[], int size);

#endif // MATH_H