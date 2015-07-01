/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "MeshRegistry.h"

/* Constructor */
MeshRegistry::MeshRegistry(void) {
	registry = vector<Mesh*>();
}

/* Destructor */
MeshRegistry::~MeshRegistry(void) {
	for(Mesh* m : registry) {
		if(m != nullptr) {
			delete m;
			m = nullptr;
		}
	}
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

/* AddMesh */
void MeshRegistry::AddMesh(Mesh* m) {
	registry.push_back(m);
}

/* GetMesh */
Mesh* MeshRegistry::GetMesh(const string ID) {
	for(Mesh* m : registry) {
		if(m->GetID() == ID)
			return m;
	}

	return nullptr;
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
	GLfloat squareVertexData[] = {
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
	glBufferData(GL_ARRAY_BUFFER, sizeof(squareVertexData), squareVertexData, GL_STATIC_DRAW);

	AddMesh(new Mesh("Cube", vbo, 36));
}

#pragma endregion