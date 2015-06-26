/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef GLRENDERER
#define GLRENDERER
#define GLEW

#include <vector>
#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "Matrix4.h"
#include "Camera.h"
#include "FileIO.h"

enum RenderMode { WIREFRAME = 0, FILLED = 1 };

class GLRenderer
{
	GLuint vertexArrayObj;
	GLuint vertexBufferObj;
	GLuint fragmentBufferObj;

	GLuint shaderProgramID;
	GLuint mvpUniformID;
	GLuint colorID;

	Camera* camera;

	Matrix4 projection;

public:
	GLFWwindow* window;

	/* Constructor */
	GLRenderer(void);

	/* Destructor */
	~GLRenderer(void);

	/* Initialize */
	/*	Initializes functionality necessary to operate in an OpenGL environment */
	int Initialize(void);

	/* DrawRefresh */
	/*	Clears screen and calls necessary GL draw-cycle functions */
	void DrawRefresh(void);

	/* DrawCube */
	/*	Draws a cube to OpenGL screen */
	/*  Matrix4& model: model matrix of cube */
	/*  Matrix4& mview: Mview matrix of camera */
	/*	RenderMode r: whether to render in wireframe, filled, etc. */
	void DrawCube(Matrix4& model, Matrix4& view, RenderMode r);
private:
	/* CreateWindow */
	/*	Creates OpenGL window to render to */
	/*	int w: window width */
	/*	int h: window height */
	int CreateWindow(int w = 720, int h = 480);

	/* GenerateVAO */
	/*	Creates and binds a new Vertex Array Object */
	/*	GLuint vao: VAO to bind to */
	void GenerateVAO(GLuint vao);

	/* GenerateVertexBuffer */
	/*	Creates and binds a new Vertex Buffer Object */
	/*	GLuint vbo: VBO to bind to */
	/*  GLflot data: buffer data to use */
	void GenerateVertexBuffer(GLuint vbo, GLfloat data[]);

	/* GeneraFragmentBuffer */
	/*	Creates and binds a new Fragment Buffer Object */
	/*	GLuint vbo: VBO to bind to */
	/*  GLfloat data[]: buffer data to use */
	void GenerateFragmentBuffer(GLuint fbo, GLfloat data[]);

	/* LoadShader */
	/*	Loads shader from specified file */
	/*	char* filePath: file to load shader from */
	GLuint LoadShader(char* filePath, GLenum type);

	/* LoadShaderProgram */
	/*	Creates shader program and adds created shaders */
	GLuint LoadShaderProgram(void);
};
#endif

