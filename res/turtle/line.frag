#version 460 core

out vec4 f_color;

in vec3 vColor;

void main()
{
	f_color = vec4(vColor, 1);
}