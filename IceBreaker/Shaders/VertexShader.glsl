#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;

out vec3 fragmentColor;

uniform mat4 MVP;

void main() {
	vec4 v = vec4(vertexPosition, 1);
	gl_Position = v * MVP;
	
	fragmentColor = vertexColor;
}