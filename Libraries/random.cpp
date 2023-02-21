#include "random.hpp"

void SeedRandom()
{
    srand(time(nullptr));
}

int RandomInt(int max)
{
    return static_cast<int>(static_cast<double>(max * rand()) / RAND_MAX);
}

bool RandomBool()
{
    return static_cast<bool>(RandomInt(2));
}

char RandomChar(std::string options)
{
    int length = options.length();
    int selection = RandomInt(length);
    return options[selection];
}