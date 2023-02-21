#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

// Matrix -------------------------------------------------------------------------------------
class Matrix
{
    private:
        double *elements;
        int width;
        int height;

        double nullElement;

    public:
        Matrix(const int width, const int height);
        ~Matrix();

        double& Element(int x, int y);
};

// Complex ------------------------------------------------------------------------------------
class Complex : Matrix
{
    public:
        Complex(double real, double imaginary);
};

#endif // LINEAR_ALGEBRA_H