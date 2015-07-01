/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#ifndef MESH_REGISTRY
#define MESH_REGISTRY

#include <string>
#include <vector>
#include "Mesh.h"

using namespace std;

/* MeshRegistry */
/*  ** Library for various meshes used in the IceBreaker engine */
class MeshRegistry
{
	vector<Mesh*> registry; // Holds meshes

public:
	/* Constructor */
	MeshRegistry(void);

	/* Destructor */
	~MeshRegistry(void);

	/* GenerateShapes */
	/*  ** Populates registry list with meshes of common shapes and objects */
	void GenerateShapes(void);

	/* AddMesh */
	/*  ** Adds mesh to registry */
	/*  **** Mesh* mesh: mesh to add */
	void AddMesh(Mesh* mesh);

	/* GetMesh */
	/*  ** Returns specified mesh from list, otherwise returns nullptr (/
	/*  **** string ID: mesh ID to search for */
	Mesh* GetMesh(string ID);

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

