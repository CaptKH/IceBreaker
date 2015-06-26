/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef FILEIO
#define FILEIO

#include <string>
#include <fstream>

using namespace std;

/* ReadShaderFile */
/*  Reads in and returns string containing contents of specified shader file */
/*	char* filePath: name of file containing shader data */
string ReadShaderFile(const char* filePath);

#endif

