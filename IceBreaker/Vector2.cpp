/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Vector2.h"

/* Constructor */
Vector2::Vector2(float _x, float _y) {
	x = _x;
	y = _y;
}

/* Destructor */
Vector2::~Vector2(void) {
}

/* Magnitude */
float Vector2::Magnitude(void) {
	return sqrt((x * x) + (y * y));
}

/* Normalize */
void Vector2::Normalize(void) {
	float mag = Magnitude();

	x /= mag;
	y /= mag;
}

/* DotProduct */
float Vector2::DotProduct(Vector2& vec) {
	return (x * vec.x) + (y * vec.y);
}

/* AngleBetween */
float Vector2::AngleBetween(Vector2& vec) {
	return acos(DotProduct(vec)/(Magnitude() * vec.Magnitude()));
}

/* Print */
string Vector2::Print(void) {
	string xStr = to_string(x);
	string yStr = to_string(y);

	return "(" + xStr + ", " + yStr + ")";
}

/* Operator Overloads */
Vector2 Vector2::operator + (Vector2& vec) {
	return Vector2(x + vec.x, y + vec.y);
}
Vector2 Vector2::operator - (Vector2& vec) {
	return Vector2(x - vec.x, y - vec.y);
}
Vector2 Vector2::operator * (float num) {
	return Vector2(x * num, y * num);
}
Vector2 Vector2::operator / (float num) {
	return Vector2(x / num, y / num);
}
void Vector2::operator += (Vector2& vec) {
	x += vec.x;
	y += vec.y;
}
void Vector2::operator -= (Vector2& vec) {
	x -= vec.x;
	y -= vec.y;
}
void Vector2::operator *= (float num) {
	x *= num;
	y *= num;
}
void Vector2::operator /= (float num) {
	x /= num;
	y /= num;
}