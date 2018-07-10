#version 450 core

out vec4 color;

in VS_COL{
	vec4 col;
} fs_col;

void main(void){
	color = fs_col.col;
}