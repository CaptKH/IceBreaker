/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef GLRENDERER
#define GLRENDERER

#ifndef OPEN_GL
#define OPEN_GL
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#endif


#include <vector>
#include <iostream>
#include "Matrix4.h"
#include "Camera.h"
#include "FileIO.h"
#include "Particle.h"
#include "MeshRegistry.h"

enum RenderMode { WIREFRAME = 0, FILLED = 1 };

class GLRenderer
{
	GLuint vertexArrayObj;
	GLuint fragmentBufferObj;
	GLuint textureBufferObj;

	// Shader variables
	GLuint shaderProgramID;
	GLuint mvpUniformID;
	GLuint colorID;

	// Model-View-Projection matrix
	Matrix4 mvp;
	Matrix4 projection;

	MeshRegistry* meshRegistry;

public:
	GLFWwindow* window;
	Camera* camera;

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

	/* Draw */
	/*  Draw a triangle to OpenGL screen */
	/*  Particle p: particle to draw */
	/*	RenderMode r: whether to render in wireframe, filled, etc. */
	void Draw(Particle* p, RenderMode r);
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
	void GenerateFragmentBuffer(void);

	/* LoadShader */
	/*	Loads shader from specified file */
	/*	char* filePath: file to load shader from */
	GLuint LoadShader(char* filePath, GLenum type);

	/* LoadShaderProgram */
	/*	Creates shader program and adds created shaders */
	GLuint LoadShaderProgram(void);
};
#endif

