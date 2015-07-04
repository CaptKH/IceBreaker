/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef MESH_REGISTRY
#define MESH_REGISTRY

#include <vector>
#include "Mesh.h"

using namespace std;

/* MeshRegistry */
/*  ** Library for various meshes used in the IceBreaker engine */
class MeshRegistry
{
	vector<Mesh*> registry; // Library of meshes

public:
	/* Constructor */
	MeshRegistry(void);

	/* Destructor */
	~MeshRegistry(void);

	/* GenerateShapes */
	/*  ** Populates registry list with meshes of common shapes and objects */
	void GenerateShapes(void);

	/* GetMesh */
	/*  ** Returns specified Mesh from registry */
	/*  **** string id: ID of mesh to find */
	Mesh* GetMesh(string id);

	/* AddMesh */
	/*  ** Adds mesh to registry */
	/*  **** Mesh* toAdd: Well duh */
	Mesh* AddMesh(Mesh* toAdd);

private:
	/* GenerateTriangle */
	/*  ** Generates triangle VBO */
	void GenerateTriangle(void);

	/* GenerateSquare */
	/*  ** Generates triangle VBO */
	void GenerateSquare(void);

	/* GenerateCube */
	/*  ** Generates cube VBO */
	void GenerateCube(void);
};
#endif

