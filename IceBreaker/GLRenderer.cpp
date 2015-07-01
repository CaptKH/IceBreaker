/* Ice Breaker Physics Engine */
/* Creator: Kirk Hewitt       */
/* Created: 6/15/2015         */

#include "GLRenderer.h"

/* Constructor */
GLRenderer::GLRenderer(void) {
}

/* Destructor */
GLRenderer::~GLRenderer(void) {
}

/* Initialize */
int GLRenderer::Initialize(void) {
	// Init GLFW
	if(!glfwInit()) {
		std::cout << "Failed to initialize GLFW\n\n";
	}
	else std::cout << "GLFW initialized.\n";

	// Create a window
	CreateWindow();

	// Init GLEW
	glewExperimental = true;
	// Make sure GLEW initialized properly
	if(glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW.\n\n";
		return -1;
	}
	else std::cout << "GLEW initialized.\n\n";

	// Create/bind VAO
	GenerateVAO(vertexArrayObj);

	// Create/bind Fragmnt Buffer
	GenerateFragmentBuffer();

	shaderProgramID = LoadShaderProgram();

	// Create Camera
	camera = new Camera(Mat4::Translate(0, 0, 0));

	mvp = Matrix4(1.0f);
	projection = Mat4::Perspective(3.14159/4, 4.0f/3.0f, 0.1f, 1000.0f);

	meshRegistry = new MeshRegistry();
	meshRegistry->GenerateShapes();

	mvpUniformID = glGetUniformLocation(shaderProgramID, "MVP");
	textureBufferObj = LoadBMP("uvtemplate.bmp");

	return 1;
}

/* Draw */
void GLRenderer::DrawRefresh(void) {
	glClearColor(0.235294, 0.701961, 0.443137, 1.0);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mvp = projection * camera->LookAt(Vector4(0, 0, 0, 1)) * Mat4::Scale(0.1f, 0.1f, 0.1f);
}

/* DrawCube */
void GLRenderer::Draw(Particle* p, RenderMode r) {
	Mesh* pMesh = meshRegistry->GetMesh(p->GetMeshID());

	// Vertex shader pointer
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, pMesh->GetVBO());
	glVertexAttribPointer(
		0,
		3,			// size
		GL_FLOAT,	// type
		GL_FALSE,	// normalized?
		0,			// stride
		(void*)0
	);

	// Fragment shader pointer
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, fragmentBufferObj);
	glVertexAttribPointer(
		1,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	Matrix4 pMVP = mvp * p->translation;

	// GL_TRUE GODDAM IT!! 6/30/2015
	glUniformMatrix4fv(mvpUniformID, 1, GL_TRUE, &pMVP[0][0]);
	glUseProgram(shaderProgramID);

	// Render in wireframe
	if(r == RenderMode::WIREFRAME)
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
	// Draw the triangle!
	glDrawArrays(GL_TRIANGLES, 0, pMesh->GetNumIndicies());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

#pragma region Private Methods

/* CreateWindow */
int GLRenderer::CreateWindow(int w, int h) {
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Create window
	window = glfwCreateWindow(w, h, "IceBreaker Physics Engine", NULL, NULL);

	// Make sure window initialized properly
	if(window == NULL) {
		std::cout << "Failed to open GLFW window.  If using Intel processor, switch to OpenGL 2.1.\n\n";
		return -1;
	}

	// Initialize GLEW
	glfwMakeContextCurrent(window);
	// GLFW input mode
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}

/* GenerateVAO */
void GLRenderer::GenerateVAO(GLuint vao) {
	// Create spot for VAO on GPU
	glGenVertexArrays(1, &vao);
	// Bind it
	glBindVertexArray(vao);
}

/* GenerateVertexBuffer */
void GLRenderer::GenerateVertexBuffer(GLuint vbo, GLfloat data[]) {
	// Create spot for VBO on GPU
	glGenBuffers(1, &vbo);
	// Bind it
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// Give it data
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}

/* GenerateFragmentBuffer */
void GLRenderer::GenerateFragmentBuffer(void) {
	GLfloat fragmentData[] = {
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.597f,  0.770f,  0.761f,
		0.559f,  0.436f,  0.730f,
		0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,
		0.559f,  0.861f,  0.639f,
		0.195f,  0.548f,  0.859f,
		0.014f,  0.184f,  0.576f,
		0.771f,  0.328f,  0.970f,
		0.406f,  0.615f,  0.116f,
		0.676f,  0.977f,  0.133f,
		0.971f,  0.572f,  0.833f,
		0.140f,  0.616f,  0.489f,
		0.997f,  0.513f,  0.064f,
		0.945f,  0.719f,  0.592f,
		0.543f,  0.021f,  0.978f,
		0.279f,  0.317f,  0.505f,
		0.167f,  0.620f,  0.077f,
		0.347f,  0.857f,  0.137f,
		0.055f,  0.953f,  0.042f,
		0.714f,  0.505f,  0.345f,
		0.783f,  0.290f,  0.734f,
		0.722f,  0.645f,  0.174f,
		0.302f,  0.455f,  0.848f,
		0.225f,  0.587f,  0.040f,
		0.517f,  0.713f,  0.338f,
		0.053f,  0.959f,  0.120f,
		0.393f,  0.621f,  0.362f,
		0.673f,  0.211f,  0.457f,
		0.820f,  0.883f,  0.371f,
		0.982f,  0.099f,  0.879f
	};
	
	// Create spot for VBO on GPU
	glGenBuffers(1, &fragmentBufferObj);
	// Bind it
	glBindBuffer(GL_ARRAY_BUFFER, fragmentBufferObj);
	// Give it data
	glBufferData(GL_ARRAY_BUFFER, sizeof(fragmentData), fragmentData, GL_STATIC_DRAW);
}

/* LoadShaders */
GLuint GLRenderer::LoadShader(char* filePath, GLenum type) {
	// Variable to store location of shader on GPU
	GLuint shaderID = glCreateShader(type);

	// File contents
	string shaderData = ReadShaderFile(filePath);

	// Load/compile vertex shader
	char const * vsPointer = shaderData.c_str();
	glShaderSource(shaderID, 1, &vsPointer, NULL);
	glCompileShader(shaderID);

	// Variables needed to check shader
	GLint result = GL_FALSE;
	int infoLogLength;

	// Check shader
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
    std::vector<char> FragmentShaderErrorMessage(infoLogLength);
    glGetShaderInfoLog(shaderID, infoLogLength, NULL, &FragmentShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);

	return shaderID;
}

/* LoadShaderProgram */
GLuint GLRenderer::LoadShaderProgram(void) {
	// Create Shader Program
	GLuint programID = glCreateProgram();

	// Get the shaders
	GLuint vertexShader = LoadShader("Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
	GLuint fragmentShader = LoadShader("Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);

	// Link shaders to program
	glAttachShader(programID, vertexShader);
	glAttachShader(programID, fragmentShader);
	// Link the program
	glLinkProgram(programID);
	
	// Variables needed to check program
	GLint result = GL_FALSE;
	int infoLogLength;

	// Check program
	glGetProgramiv(programID, GL_LINK_STATUS, &result);
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
    std::vector<char> ProgramErrorMessage( max(infoLogLength, int(1)) );
    glGetProgramInfoLog(programID, infoLogLength, NULL, &ProgramErrorMessage[0]);
    fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);

	// Delete now unneeded shaders since they're in the program
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return programID;
}

#pragma endregion