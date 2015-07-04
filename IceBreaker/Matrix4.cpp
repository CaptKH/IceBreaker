/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "Matrix4.h"

/* Constructor */
Matrix4::Matrix4(float num) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(i == j)
				matrix[i][j] = num;
			else 
				matrix[i][j] = 0.0f;
		}
	}
}

/* Destructor */
Matrix4::~Matrix4(void) {
}

/* Transpose */
void Matrix4::Transpose(void) {
	float newMatrix[4][4];

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			newMatrix[j][i] = matrix[i][j];
		}
	}

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			matrix[i][j] = newMatrix[i][j];
		}
	}
}

/* Print */
string Matrix4::Print(void) {
	string toReturn = "-------------------------------------------------------------------------\n";

	for(int i = 0; i < 4; i++) {
		toReturn += "|\t";

		for(int j = 0; j < 4; j++) {
			toReturn += to_string(matrix[i][j]) + "\t";
		}

		toReturn += "|\n";
	}

	toReturn += "-------------------------------------------------------------------------\n";

	return toReturn;
}

/* Operator Overloads */
float* Matrix4::operator [] (int index) {
	return matrix[index];
}
Vector4& Matrix4::operator * (Vector4& vec) {
	float x = (matrix[0][0] * vec.x) + (matrix[0][1] * vec.y) + (matrix[0][2] * vec.z) + (matrix[0][3] * vec.w);
	float y = (matrix[1][0] * vec.x) + (matrix[1][1] * vec.y) + (matrix[1][2] * vec.z) + (matrix[1][3] * vec.w);
	float z = (matrix[2][0] * vec.x) + (matrix[2][1] * vec.y) + (matrix[2][2] * vec.z) + (matrix[2][3] * vec.w);
	float w = (matrix[3][0] * vec.x) + (matrix[3][1] * vec.y) + (matrix[3][2] * vec.z) + (matrix[3][3] * vec.w);

	return Vector4(x, y, z, w);
}
Matrix4 Matrix4::operator * (Matrix4& mat) {
	Matrix4 toReturn = Matrix4();

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			for(int k = 0; k < 4; k++) {
				toReturn[i][j] += matrix[i][k] * mat[k][j];
			}
		}
	}

	toReturn[3][3] = 1.0f;

	return toReturn;
}

namespace Mat4 {
	/* Translate */
	Matrix4 Translate(float x, float y, float z) {
		Matrix4 mat = Matrix4(1.0f);

		mat[0][3] += x;
		mat[1][3] += y;
		mat[2][3] += z;

		return mat;
	}

	/* Rotate */
	Matrix4 Rotate(Vector3& axis, float angle) {
		Matrix4 rotationMat = Matrix4(1.0f);

		// If we need rotate around the x-axis...
		if(axis.x != 0.0f) {
			Matrix4 xRotationMat = Matrix4(1.0f);
			float xAngleScale = angle * axis.x;

			xRotationMat[1][1] = cosf(xAngleScale);
			xRotationMat[1][2] = -sinf(xAngleScale);
			xRotationMat[2][1] = sinf(xAngleScale);
			xRotationMat[2][2] = cosf(xAngleScale);

			rotationMat = rotationMat * xRotationMat;
		}

		// If we need rotate around the y-axis...
		if(axis.y != 0.0f) {
			Matrix4 yRotationMat = Matrix4(1.0f);
			float yAngleScale = angle * axis.y;

			yRotationMat[0][0] = cosf(yAngleScale);
			yRotationMat[0][2] = sinf(yAngleScale);
			yRotationMat[2][0] = -sinf(yAngleScale);
			yRotationMat[2][2] = cosf(yAngleScale);

			rotationMat = rotationMat * yRotationMat;
		}

		// If we need rotate arozund the -axis...
		if(axis.z != 0.0f) {
			Matrix4 zRotationMat = Matrix4(1.0f);
			float zAngleScale = angle * axis.z;

			zRotationMat[0][0] = cosf(zAngleScale);
			zRotationMat[0][1] = -sinf(zAngleScale);
			zRotationMat[1][0] = sinf(zAngleScale);
			zRotationMat[1][1] = cosf(zAngleScale);

			rotationMat = rotationMat * zRotationMat;
		}

		return rotationMat;
	}

	/* Scale */
	Matrix4 Scale(float s) {
		Matrix4 mat = Matrix4(0.0f);

		mat[0][0] = s;
		mat[1][1] = s;
		mat[2][2] = s;
				
		return mat;
	}

	/* Scale */
	Matrix4 Scale(float x, float y, float z) {
		Matrix4 mat = Matrix4(0.0f);

		mat[0][0] = x;
		mat[1][1] = y;
		mat[2][2] = z;
				
		return mat;
	}

	/* LookAt */
	Matrix4 LookAt(Vector4& eye, Vector4& point, Vector4& up) {
		Vector4 forward = point - eye;
		forward.Normalize();

		up.Normalize();

		Vector4 side = forward.CrossProduct(up);
		side.Normalize();

		up = forward.CrossProduct(side);
		up.Normalize();

		Matrix4 toReturn = Matrix4(1.0f);
		toReturn[0][0] = side.x;
		toReturn[0][1] = side.y;
		toReturn[0][2] = side.z;
		toReturn[0][3] = -side.DotProduct(eye);

		toReturn[1][0] = up.x;
		toReturn[1][1] = up.y;
		toReturn[1][2] = up.z;
		toReturn[1][3] = -up.DotProduct(eye);

		toReturn[2][0] = -forward.x;
		toReturn[2][1] = -forward.y;
		toReturn[2][2] = -forward.z;
		toReturn[2][3] = -forward.DotProduct(eye);

		toReturn[3][0] = 0;
		toReturn[3][1] = 0;
		toReturn[3][2] = 0;
		toReturn[3][3] = 1.0f;

		return toReturn;
	}

	/* Perspective */
	Matrix4 Perspective(float fovy, float aspect, float zNear, float zFar) {
		fovy /= 2.0f;
		
		Matrix4 toReturn = Matrix4(0.0f);
		float deltaZ = (zFar - zNear);
		float sine = sinf(fovy);
		float cotangent = (cosf(fovy) / sine);

		toReturn[0][0] = cotangent / aspect;
		toReturn[1][1] = cotangent;
		toReturn[2][2] = -(zFar + zNear) / deltaZ;
		toReturn[2][3] = (-2.0f * zFar * zNear) / deltaZ;
		toReturn[3][2] = -1;
		toReturn[3][3] = 0.0f;
		return toReturn;
	}
}
