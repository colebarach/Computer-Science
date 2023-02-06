#include "math.hpp"

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

void BubbleSort(int *data, int size)
{
    for(int j = 0; j < size-1; j++)
    {
        for(int k = 0; k < size-j-1; k++)
        {
            if(data[k] > data[k+1])
            {
                int temp = data[k];
                data[k] = data[k+1];
                data[k+1] = temp;
            }
        }
    }
}

void BubbleSort(double *data, int size)
{
    for(int j = 0; j < size-1; j++)
    {
        for(int k = 0; k < size-j-1; k++)
        {
            if(data[k] > data[k+1])
            {
                double temp = data[k];
                data[k] = data[k+1];
                data[k+1] = temp;
            }
        }
    }
}

int *PushToFrontArray(int array[], int size)
{
    // Create New Array
    int *newArray = new int[size+1];

    // Initialize First Element
    newArray[0] = 0;

    // Fill Remaining Elements
    for(int x = 0; x < size; x++)
    {
        newArray[x+1] = array[x];
    }

    // Return Pointer
    return newArray;
}