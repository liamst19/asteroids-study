/** math.h
 * 
 * Collection of math functions and classes,
 * specifically a Vector class.
 */

#ifndef MATH_H
#define MATH_H

#include <cmath>

namespace Math{

	const float Pi = 3.1415926535f;
	const float TwoPi = Pi * 2.0f;
	const float PiOver2 = Pi / 2.0f;
//	const float Infinity = std::numeric_limits<float>::infinity();
//	const float NegInfinity = -std::numeric_limits<float>::infinity();

    // Convert degrees to radians
	inline float ToRadians(float degrees)
	{
		return degrees * Pi / 180.0f;
	}

    // Convert radians to degrees
	inline float ToDegrees(float radians)
	{
		return radians * 180.0f / Pi;
	}

    // Checks whether float value is near zero
	inline bool NearZero(float val, float epsilon = 0.001f)
	{
		if (fabs(val) <= epsilon)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

    // Square root of float
    inline float Sqrt(float value){
        return sqrtf(value);
    }

// --------------------------------------------------
// Trigonometric Functions

	inline float Cos(float angle)
	{
		return cosf(angle);
	}

	inline float Sin(float angle)
	{
		return sinf(angle);
	}

	inline float Tan(float angle)
	{
		return tanf(angle);
	}

	inline float Acos(float value)
	{
		return acosf(value);
	}
	
	inline float Atan2(float y, float x)
	{
		return atan2f(y, x);
	}

	inline float Cot(float angle)
	{
		return 1.0f / Tan(angle);
	}

// --------------------------------------------------

}


class Vector2d{

public:
    float x,y;

    Vector2d():
        x(0.0),
        y(0.0)
    {};

    explicit Vector2d(float xIn, float yIn):
        x(xIn),
        y(yIn)
    {};

// ----------------------------------------
// Vector Operators

    // Vector Addition (a + b)
    friend Vector2d operator+(const Vector2d& a, const Vector2d& b)
    {
        return Vector2d(a.x + b.x, a.y + b.y);
    }

    // Vector Subtraction (a - b)
    friend Vector2d operator-(const Vector2d& minuend, const Vector2d& subtrahend)
    {
        return Vector2d(minuend.x - subtrahend.x, minuend.y - subtrahend.y);
    }

    // Vector Scaling (vector * scalar)
    friend Vector2d operator*(const Vector2d vector, const float scalar)
    {
        return Vector2d(vector.x * scalar, vector.y * scalar);
    }

    // Vector Scaling, commutative (scalar * vector) 
    friend Vector2d operator*(const float scalar, const Vector2d vector)
    {
        return Vector2d(vector.x * scalar, vector.y * scalar);
    }

// ----------------------------------------
//  Shorthand Assignment Operators

    // Vector Addition +=
    Vector2d operator+=(const Vector2d& addend)
    {
        x += addend.x;
        y += addend.y;
        return *this;
    }

    // Vector Subtraction -=
    Vector2d operator-=(const Vector2d& subtrahend)
    {
        x -= subtrahend.x;
        y -= subtrahend.y;
        return *this;
    }

    // Vector Scaling *=
    Vector2d operator*=(const float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

// ----------------------------------------
// Vector functions

    // Length squared
    float lengthSq()
    {
        return (x*x + y*y);
    }

    // Length
    float length()
    {
        return Math::Sqrt(lengthSq());
    }

    // Normalizes, convert to unit vector
    void normalize(){
        float len = length();
        x /= len;
        y /= len;
    }

// ----------------------------------------
// Static functions

    // Normalizes a vector
    static Vector2d Normalize(const Vector2d& vector){
        Vector2d tempVec = vector;
        tempVec.normalize();
        return tempVec;
    }

    // Dot product of vectors: determines the angle between
    static float Dot(const Vector2d& a, const Vector2d& b)
    {
        return (a.x * b.x + a.y * b.y);
    }

    // Lerp from A to B by f
	static Vector2d Lerp(const Vector2d& a, const Vector2d& b, float f)
	{
        return Vector2d(a + (f * (b - a)));
	}

	// Reflect V about (normalized) N
	static Vector2d Reflect(const Vector2d& v, const Vector2d& n)
	{
		return v - 2.0f * Vector2d::Dot(v, n) * n;
	}

	// Get forward vector from rotation angle
	static Vector2d GetForward(float angle)
	{
        // negative y-value because of screen
		return Vector2d(Math::Cos(angle), -Math::Sin(angle));
	}

	// Get angle of a vector using arctangent
	static float GetAngle(const Vector2d& vec)
	{
		return Math::Atan2(vec.y, vec.x);
	}

	// Transform vector by matrix
	// static Vector2d Transform(const Vector2d& vec, const class Matrix3& mat, float w = 1.0f);

	static const Vector2d Zero;
	static const Vector2d UnitX;
	static const Vector2d UnitY;
	static const Vector2d NegUnitX;
	static const Vector2d NegUnitY;	

};

#endif