/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "FileIO.h"

/* ReadShaderFile */
string ReadShaderFile(const char* filePath) {
	// String to store shader code
	string shaderCode;
	// Create stream to file
	ifstream shaderStream(filePath, ios::in);

	// Open sream
	if(shaderStream.is_open()) {
		// To store shader file lines
		string line;

		// Fill shaderCode with shader data
		while(getline(shaderStream, line)) {
			shaderCode += "\n" + line;
		}

		// Close the stream
		shaderStream.close();
	}

	return shaderCode;
}

/* LoadBMP */
GLuint LoadBMP(const char* filePath) {
	unsigned char header[54]; // BMP files start with 54 byte header
	unsigned int dataPos;	  // Where data begins in file
	unsigned int width;
	unsigned int height;
	unsigned int imageSize;	  // = width * height * 3
	unsigned char* data;	  // RGB data

	#pragma region File IO Section

	// Find the file
	FILE * file = fopen(filePath, "rb");

	// If it didn't load get out
	if(!file) {
		printf("BMP file could not be loaded. >> Incorrect filepath");
		return 0;
	}

	// Check to verify header is 54-bytes large
	if(fread(header, 1, 54, file) != 54 &&
		// All BMP files begin with "BM"
		(header[0] != 'B' || header[1] != 'M')) {
		printf("BMP file could not be loaded. >> Improper header");
		return false;
	}

	// Read in various data
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);

	// In case of poor formatting, guess some of the information
	if(imageSize == 0) imageSize = width * height * 3;
	if(dataPos == 0) dataPos = 54;

	// Buffer to hold data
	data = new unsigned char[imageSize];
	// Read the data into the buffer
	fread(data, 1, imageSize, file);

	// All done with file
	fclose(file);

	#pragma endregion

	#pragma region OpenGL Section

	// Create texture in OpenGL
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	// We'll come back to this..
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	#pragma endregion

	return textureID;
}
