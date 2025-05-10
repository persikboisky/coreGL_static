#version 460 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTextCoord;

out vec2 vTextCoord;

//uniform mat4 view = mat4(1.0f);
//uniform mat4 proj = mat4(1.0f);
//uniform mat4 model = mat4(1.0f);

void main()
{
	vTextCoord = aTextCoord;
	gl_Position = vec4(aPos, 1.0f);
}