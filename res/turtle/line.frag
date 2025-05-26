#version 460 core

out vec4 f_color;

in vec3 vColor;

void main()
{
	f_color = vec4(vColor.x / 255.0f, vColor.y / 255.0f, vColor.z / 255.0f, 1);
}