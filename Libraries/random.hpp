#include <random>
#include <time.h>
#include <string.h>

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
