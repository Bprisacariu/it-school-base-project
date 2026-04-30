#include "math_utils.h"
#include <stdexcept>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int factorial(int n)
{
    if (n < 0)
    {
        throw std::invalid_argument("factorial is not defined for negative numbers");
    }
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

bool is_even(int n)
{
    return n % 2 == 0;
}
