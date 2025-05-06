#version 460 core

layout (location = 0) in vec3 aPos;

uniform mat4 view = mat4(1.0f);
uniform mat4 proj = mat4(1.0f);
uniform mat4 model = mat4(1.0f);

void main()
{
	gl_Position = proj * view * model * vec4(aPos, 1.0f);
}