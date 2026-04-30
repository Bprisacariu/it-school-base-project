#include <gtest/gtest.h>
#include "math_utils.h"

// ---- Addition tests ----

TEST(MathUtilsTest, AddPositiveNumbers)
{
    EXPECT_EQ(add(2, 3), 5);
}

TEST(MathUtilsTest, AddNegativeNumbers)
{
    EXPECT_EQ(add(-2, -3), -5);
}

TEST(MathUtilsTest, AddZero)
{
    EXPECT_EQ(add(0, 5), 5);
    EXPECT_EQ(add(5, 0), 5);
}

// ---- Subtraction tests ----

TEST(MathUtilsTest, SubtractPositiveNumbers)
{
    EXPECT_EQ(subtract(5, 3), 2);
}

TEST(MathUtilsTest, SubtractResultNegative)
{
    EXPECT_EQ(subtract(3, 5), -2);
}

// ---- Multiplication tests ----

TEST(MathUtilsTest, MultiplyPositiveNumbers)
{
    EXPECT_EQ(multiply(4, 3), 12);
}

TEST(MathUtilsTest, MultiplyByZero)
{
    EXPECT_EQ(multiply(5, 0), 0);
}

TEST(MathUtilsTest, MultiplyNegativeNumbers)
{
    EXPECT_EQ(multiply(-2, -3), 6);
}

// ---- Factorial tests ----

TEST(MathUtilsTest, FactorialOfZero)
{
    EXPECT_EQ(factorial(0), 1);
}

TEST(MathUtilsTest, FactorialOfOne)
{
    EXPECT_EQ(factorial(1), 1);
}

TEST(MathUtilsTest, FactorialOfFive)
{
    EXPECT_EQ(factorial(5), 120);
}

TEST(MathUtilsTest, FactorialNegativeThrows)
{
    EXPECT_THROW(factorial(-1), std::invalid_argument);
}

// ---- IsEven tests ----

TEST(MathUtilsTest, IsEvenTrue)
{
    EXPECT_TRUE(is_even(4));
    EXPECT_TRUE(is_even(0));
    EXPECT_TRUE(is_even(-2));
}

TEST(MathUtilsTest, IsEvenFalse)
{
    EXPECT_FALSE(is_even(3));
    EXPECT_FALSE(is_even(1));
    EXPECT_FALSE(is_even(-1));
}
