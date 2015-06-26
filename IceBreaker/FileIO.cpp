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
