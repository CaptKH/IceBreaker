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

/* Clear */
void Vector4::Clear(void) {
	x = 0;
	y = 0;
	z = 0;
}

/* Magnitude */
float Vector4::Magnitude(void) {
	return sqrtf((x * x) + (y * y) + (z * z));
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
	/* Vec3to4 */
	Vector4 Vec3to4(Vector3 vec3, int w) {
		return Vector4(vec3.x, vec3.y, vec3.z, w);
	}

	/* Random */
	Vector4 Random(void) {
		int x = rand() - rand();
		int y = rand() - rand();
		int z = rand() - rand();

		// z = 0 for now until graphics issues sorted out
 		Vector4 toReturn = Vector4(x, y, 0);
		toReturn.Normalize();
		return toReturn;
	}

	/* Normalize */
	Vector4 Normalize(Vector4 toNorm) {
		toNorm.Normalize();
		return toNorm;
	}
}