/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "MeshRegistry.h"

/* Constructor */
MeshRegistry::MeshRegistry(void) {
}

/* Destructor */
MeshRegistry::~MeshRegistry(void) {
}

/* GenerateShapes */
void MeshRegistry::GenerateShapes(void) {
	/* Triangle */
	GenerateTriangle();

	/* Square */
	GenerateSquare();

	/* Cube */
	GenerateCube();
}

/* GetMesh */
Mesh* MeshRegistry::GetMesh(string id) {
	for(Mesh* m : registry) {
		if(m->GetID() == id)
			return m;
	}

	return nullptr;
}

/* AddMesh */
Mesh* MeshRegistry::AddMesh(Mesh* toAdd) {
	if(toAdd != nullptr)
		registry.push_back(toAdd);

	return toAdd;
}

#pragma region Shapes Meshes

/* GenerateTriangle */
void MeshRegistry::GenerateTriangle(void) {
	GLfloat triangleVertexData[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertexData), triangleVertexData, GL_STATIC_DRAW);

	AddMesh(new Mesh("Triangle", vbo, 3));
}

/* GenerateSquare */
void MeshRegistry::GenerateSquare(void) {
	GLfloat squareVertexData[] = {
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(squareVertexData), squareVertexData, GL_STATIC_DRAW);

	AddMesh(new Mesh("Square", vbo, 6));
}

/* GenerateCube */
void MeshRegistry::GenerateCube(void) {
	GLfloat cubeVertexData[] = {
		-0.5f,-0.5f,-0.5f, 
		-0.5f,-0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f, 
		 0.5f, 0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f, 0.5f,-0.5f,
		 0.5f,-0.5f, 0.5f,
		-0.5f,-0.5f,-0.5f,
		 0.5f,-0.5f,-0.5f,
		 0.5f, 0.5f,-0.5f,
		 0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f,-0.5f,
		 0.5f,-0.5f, 0.5f,
		-0.5f,-0.5f, 0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f, 0.5f, 0.5f,
		-0.5f,-0.5f, 0.5f,
		 0.5f,-0.5f, 0.5f,
		 0.5f, 0.5f, 0.5f,
		 0.5f,-0.5f,-0.5f,
		 0.5f, 0.5f,-0.5f,
		 0.5f,-0.5f,-0.5f,
		 0.5f, 0.5f, 0.5f,
		 0.5f,-0.5f, 0.5f,
		 0.5f, 0.5f, 0.5f,
		 0.5f, 0.5f,-0.5f,
		-0.5f, 0.5f,-0.5f,
		 0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f,-0.5f,
		-0.5f, 0.5f, 0.5f,
		 0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,
		 0.5f,-0.5f, 0.5f
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertexData), cubeVertexData, GL_STATIC_DRAW);


	AddMesh(new Mesh("Cube", vbo, 36));
}

#pragma endregion