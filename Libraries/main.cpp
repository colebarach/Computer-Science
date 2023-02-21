#include <iostream>

#include "trigonometry.hpp"
#include "calculus.hpp"
#include "algebra.hpp"

int main()
{
    double fx[32];
    double fy[32];
    double gx[24];
    double gy[24];

    for(int t = 0; t < 32; t++)
    {
        fx[t] = t / 4.0;
        fy[t] = fx[t] * fx[t] / 2;
    }

    for(int t = 0; t < 24; t++)
    {
        gx[t] = t / 5.0;
        gy[t] = gx[t] * gx[t]*gx[t] - gx[t];
    } 

    for(int x = 0; x < 32; x++)
    {
        std::cout << "(" << fx[x] << ", " << fy[x] << "), ";
    }
    
    std::cout << "\nFunction2\n";

    for(int x = 0; x < 24; x++)
    {
        std::cout << "(" << gx[x] << ", " << gy[x] << "), ";
    }

    std::cout << "\nOPERATION\n";

    Add(fx, fy, gx, gy, 32, 24);

    for(int x = 0; x < 32; x++)
    {
        std::cout << "(" << fx[x] << ", " << fy[x] << "), ";
    }

    return 0;
}