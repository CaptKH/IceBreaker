#version 330 core

in vec3 fragmentColor;

uniform float alpha;


void main() {
	 gl_FragColor = vec4(fragmentColor, alpha);
}