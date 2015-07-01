/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef FILEIO
#define FILEIO

#ifndef OPEN_GL
#define OPEN_GL
#include <GL\glew.h>
#endif

#include <string>
#include <fstream>

using namespace std;

/* ReadShaderFile */
/*  ** Reads in and returns string containing contents of specified shader file */
/*	**** char* filePath: path to file containing shader data */
string ReadShaderFile(const char* filePath);

/* LoadBMP */
/*  ** Loads specified BMP file and returns location on GPU */
/*  **** char* filePath: path to file containing BMP data */
GLuint LoadBMP(const char* filePath);

#endif

