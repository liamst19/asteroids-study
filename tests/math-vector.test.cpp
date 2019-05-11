/** math-vector.test.cpp
 * 
 * 
 */

#include <cmath>
#include "gtest/gtest.h"
#include "../src/math.h"

namespace {

    // Default Constructor
    TEST(Vector2dTest, DefaultConstructor){
        const Vector2d v;

        EXPECT_FLOAT_EQ(v.x, 0.0);
        EXPECT_FLOAT_EQ(v.y, 0.0);
    }

    // Constructor with explicit assignment
    TEST(Vector2dTest, AssignedConstructor){
        const Vector2d v2{5.0, 9.3};

        EXPECT_FLOAT_EQ(v2.x, 5.0);
        EXPECT_FLOAT_EQ(v2.y, 9.3);
    }

    // Vector Addition
    TEST(Vector2dTest, Addition){
        Vector2d a{2.5, 7.5}, b{5.5, 2.5};
        Vector2d sum = a + b;

        EXPECT_FLOAT_EQ(sum.x, 8.0);
        EXPECT_FLOAT_EQ(sum.y, 10.0);
    }

    // Vector Subtraction
    TEST(Vector2dTest, Subtraction){
        Vector2d a{10.5, 7.5}, b{5.5, 2.25};
        Vector2d difference = a - b;

        EXPECT_FLOAT_EQ(difference.x, 5.0);
        EXPECT_FLOAT_EQ(difference.y, 5.25);
    }

    // Vector Scalar
    TEST(Vector2dTest, Scalar){
        Vector2d vec{2.5, 5};
        float scalar = 2;
        Vector2d product = vec * scalar;

        EXPECT_FLOAT_EQ(product.x, 5.0);
        EXPECT_FLOAT_EQ(product.y, 10.0);
    }

    // Vector Scalar, commutative
    TEST(Vector2dTest, ScalarCommutative){
        Vector2d vec{2.5, 5};
        float scalar = 2;
        Vector2d product = scalar * vec;

        EXPECT_FLOAT_EQ(product.x, 5.0);
        EXPECT_FLOAT_EQ(product.y, 10.0);
    }

    // Vector shorthand assignment +=
    TEST(Vector2dTest, ShorthandAddition){
        Vector2d a{2.5, 7.5}, b{5.5, 2.5};
        a += b;

        EXPECT_FLOAT_EQ(a.x, 8.0);
        EXPECT_FLOAT_EQ(a.y, 10.0);
    }

    // Vector Shorthand Subtraction -=
    TEST(Vector2dTest, ShorthandSubtraction){
        Vector2d a{10.5, 7.5}, b{5.5, 2.25};
        a -= b;

        EXPECT_FLOAT_EQ(a.x, 5.0);
        EXPECT_FLOAT_EQ(a.y, 5.25);
    }

    // Vector Shorthand Scalar *=
    TEST(Vector2dTest, ShorthandScalar){
        Vector2d vec{2.5, 5};
        float scalar = 2;
        vec *= scalar;

        EXPECT_FLOAT_EQ(vec.x, 5.0);
        EXPECT_FLOAT_EQ(vec.y, 10.0);
    }

    // Length of Vector, Squared
    TEST(Vector2dTest, LengthSquared){
        Vector2d vec{5.0, 9.0};

        EXPECT_FLOAT_EQ(vec.lengthSq(), (25.0 + 81.0));
    }

    // Length of Vector
    TEST(Vector2dTest, Length){
        Vector2d vec{5.0, 9.0};

        EXPECT_FLOAT_EQ(vec.length(), sqrtf(25.0 + 81.0));
    }

    // Normalize
    TEST(Vector2dTest, Normalize){
        Vector2d vec{5.0, 9.0};
        vec.normalize();

        EXPECT_FLOAT_EQ(vec.length(), 1);
    }

    // Normalize Static Function
    TEST(Vector2dTest, NormalizeStatic){
        Vector2d vec{5.0, 9.0};
        Vector2d norm = Vector2d::Normalize(vec);

        EXPECT_FLOAT_EQ(norm.length(), 1);
    }

    // Dot Product
    TEST(Vector2dTest, Dot){
       Vector2d a{10.0, 7.0}, b{5.0, 2.0};
       float dot = Vector2d::Dot(a, b);

       EXPECT_FLOAT_EQ(dot, 64);
    }

    // Lerp 
    TEST(Vector2dTest, Lerp){
       Vector2d a{10.0, 7.0}, b{15.0, 12.0};
       float f = 10;
       Vector2d lp = Vector2d::Lerp(a, b, f); 

       EXPECT_FLOAT_EQ(lp.x, 60);
       EXPECT_FLOAT_EQ(lp.y, 57);
    }
}