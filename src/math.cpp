/** math.cpp
 * 
 * Collection of math functions and classes,
 * specifically a Vector class.
 */

// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

// #include "Math.h"

// const Vector2d Vector2d::Zero(0.0f, 0.0f);
// const Vector2d Vector2d::UnitX(1.0f, 0.0f);
// const Vector2d Vector2d::UnitY(0.0f, 1.0f);
// const Vector2d Vector2d::NegUnitX(-1.0f, 0.0f);
// const Vector2d Vector2d::NegUnitY(0.0f, -1.0f);

// Vector2d Vector2d::Transform(const Vector2& vec, const Matrix3& mat, float w /*= 1.0f*/)
// {
	// Vector2d retVal;
	// retVal.x = vec.x * mat.mat[0][0] + vec.y * mat.mat[1][0] + w * mat.mat[2][0];
	// retVal.y = vec.x * mat.mat[0][1] + vec.y * mat.mat[1][1] + w * mat.mat[2][1];
	// //ignore w since we aren't returning a new value for it...
	// return retVal;
// }