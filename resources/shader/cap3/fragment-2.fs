#version 450 core

out vec4 color;

in vec4 vs_col;

void main(void){
	color = vs_col;
}