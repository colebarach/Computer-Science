// Header
#include "linear_algebra.hpp"

// Libraries
#include <cmath>

// Matrix -------------------------------------------------------------------------------------
Matrix::Matrix(const int width, const int height)
{
    elements = new double[width * height];
        
    this->width  = width;
    this->height = height;

    this->nullElement = NAN;
}

Matrix::~Matrix()
{
    delete [] elements;
}

double& Matrix::Element(int x, int y)
{
    if(x < 0 || y < 0 || x >= width || y >= height) return nullElement; // TODO Throw Exception
    return elements[x + y*width];
}

// Complex ------------------------------------------------------------------------------------
Complex::Complex(double real, double imaginary) : Matrix(2,2)
{
    Element(0, 0) = real;
    Element(1, 0) = imaginary;
    Element(0, 1) = -imaginary;
    Element(1, 1) = real;
}