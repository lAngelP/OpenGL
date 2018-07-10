#version 450 core

layout (location = 0) in vec4 offset;

void main(void){
	//Declares a hard-coded array of positions
	const vec4 vertices[4] = vec4[4](
		vec4(0.25, -0.25, 0.5, 1.0),
		vec4(-0.25, -0.25, 0.5, 1.0),
		vec4(0.25, 0.25, 0.5, 1.0),
		vec4(0.25, -0.25, 0.5, 1.0));

	//Index into our array using gl_VertexID
	gl_Position = vertices[gl_VertexID] + offset;
}