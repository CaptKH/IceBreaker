/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Vector4.h"

/* Constructor */
Vector4::Vector4(float _x, float _y, float _z, float _w) {
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

/* Destructor */
Vector4::~Vector4(void) {
}

/* Magnitude */
float Vector4::Magnitude(void) {
	return sqrt((x * x) + (y * y) + (z * z));
}

/* Normalize */
void Vector4::Normalize(void) {
	float mag = Magnitude();

	x /= mag;
	y /= mag;
	z /= mag;
}

/* DotProduct */
float Vector4::DotProduct(Vector4& vec) {
	return (x * vec.x) + (y * vec.y) + (z * vec.z);
}

/* AngleBetween */
float Vector4::AngleBetween(Vector4& vec) {
	return acos(DotProduct(vec)/(Magnitude() * vec.Magnitude()));
}

/* CrossProduct */
Vector4 Vector4::CrossProduct(Vector4& vec) {
	return Vector4((y * vec.z) - (z * vec.y),
					(z * vec.x) - (x * vec.z),
					(x * vec.y) - (y * vec.x));
}

/* Print */
string Vector4::Print(void) {
	string xStr = to_string(x);
	string yStr = to_string(y);
	string zStr = to_string(z);
	string wStr = to_string(w);

	return "(" + xStr + ", " + yStr + ", " + zStr + ", " + wStr + ")";
}

/* Operator Overloads */
Vector4 Vector4::operator + (Vector4& vec) {
	return Vector4(x + vec.x, y + vec.y, z + vec.z);
}
Vector4 Vector4::operator - (Vector4& vec) {
	return Vector4(x - vec.x, y - vec.y, z - vec.z);
}
Vector4 Vector4::operator * (float num) {
	return Vector4(x * num, y * num, z * num);
}
Vector4 Vector4::operator / (float num) {
	return Vector4(x / num, y / num, z / num);
}
void Vector4::operator += (Vector4& vec) {
	x += vec.x;
	y += vec.y;
	z += vec.z;
}
void Vector4::operator -= (Vector4& vec) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
}
void Vector4::operator *= (float num) {
	x *= num;
	y *= num;
	z *= num;
}
void Vector4::operator /= (float num) {
	x /= num;
	y /= num;
	z /= num;
}

namespace Vec4 {
	/* Random */
	Vector4 Random(void) {
		int x = rand();
		int y = rand();
		int z = rand();

 		Vector4 toReturn = Vector4(x, y, z);
		toReturn.Normalize();
		return toReturn;
	}
}