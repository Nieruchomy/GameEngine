#pragma once

#include <iostream>

class Vector2
{
public:
	float x; 
	float y;

	Vector2();
	Vector2(float x, float y);

	Vector2& add(const Vector2& other);
	Vector2& substract(const Vector2& other);
	Vector2& multiply(const float& num);
	Vector2& divide(const float& num);

	friend Vector2& operator+(Vector2& a, const Vector2& b);
	friend Vector2& operator-(Vector2& a, const Vector2& b);
	friend Vector2& operator*(Vector2& a, const float& num);
	friend Vector2& operator/(Vector2& a, const float& num);

	Vector2& operator+=(const Vector2& a);
	Vector2& operator-=(const Vector2& a);
	Vector2& operator*=(const float& num);
	Vector2& operator/=(const float& num);

	Vector2& zero();

	friend std::ostream& operator<<(std::ostream& stream, const Vector2& a);
};