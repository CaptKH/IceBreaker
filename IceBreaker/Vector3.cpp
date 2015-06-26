/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Vector3.h"

/* Constructor */
Vector3::Vector3(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}

/* Destructor */
Vector3::~Vector3(void) {
}

/* Magnitude */
float Vector3::Magnitude(void) {
	return sqrt((x * x) + (y * y) + (z * z));
}

/* Normalize */
void Vector3::Normalize(void) {
	float mag = Magnitude();

	x /= mag;
	y /= mag;
	z /= mag;
}

/* DotProduct */
float Vector3::DotProduct(Vector3& vec) {
	return (x * vec.x) + (y * vec.y) + (z * vec.z);
}

/* AngleBetween */
float Vector3::AngleBetween(Vector3& vec) {
	return acos(DotProduct(vec)/(Magnitude() * vec.Magnitude()));
}

/* CrossProduct */
Vector3 Vector3::CrossProduct(Vector3& vec) {
	return Vector3((y * vec.z) - (z * vec.y),
					(z * vec.x) - (x * vec.z),
					(x * vec.y) - (y * vec.x));
}

/* Print */
string Vector3::Print(void) {
	string xStr = to_string(x);
	string yStr = to_string(y);
	string zStr = to_string(z);

	return "(" + xStr + ", " + yStr + ", " + zStr + ")";
}

/* Operator Overloads */
Vector3 Vector3::operator + (Vector3& vec) {
	return Vector3(x + vec.x, y + vec.y, z + vec.z);
}
Vector3 Vector3::operator - (Vector3& vec) {
	return Vector3(x - vec.x, y - vec.y, z - vec.z);
}
Vector3 Vector3::operator * (float num) {
	return Vector3(x * num, y * num, z * num);
}
Vector3 Vector3::operator / (float num) {
	return Vector3(x / num, y / num, z / num);
}
void Vector3::operator += (Vector3& vec) {
	x += vec.x;
	y += vec.y;
	z += vec.z;
}
void Vector3::operator -= (Vector3& vec) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
}
void Vector3::operator *= (float num) {
	x *= num;
	y *= num;
	z *= num;
}
void Vector3::operator /= (float num) {
	x /= num;
	y /= num;
	z /= num;
}