#include "Vector2.h"

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

Vector2& Vector2::add(const Vector2& other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vector2& Vector2::substract(const Vector2& other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}

Vector2& Vector2::multiply(const float& num)
{
	x *= num;
	y *= num;

	return *this;
}

Vector2& Vector2::divide(const float& num)
{
	x /= num;
	y /= num;

	return *this;
}

Vector2& operator+(Vector2& a, const Vector2& b)
{
	return a.add(b);
}

Vector2& operator-(Vector2& a, const Vector2& b)
{
	return a.substract(b);
}

Vector2& operator*(Vector2& a, const float& num)
{
	return a.multiply(num);
}

Vector2& operator/(Vector2& a, const float& num)
{
	return a.divide(num);
}

Vector2& Vector2::operator+=(const Vector2& a)
{
	return this->add(a);
}

Vector2& Vector2::operator-=(const Vector2& a)
{
	return this->substract(a);
}

Vector2& Vector2::operator*=(const float& num)
{
	return this->multiply(num);
}

Vector2& Vector2::operator/=(const float& num)
{
	return this->divide(num);
}

Vector2& Vector2::zero()
{
	this->x = 0.0f;
	this->y = 0.0f;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vector2& a)
{
	stream << "(" << a.x << ", " << a.y << ")";
	return stream;
}