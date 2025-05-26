#version 460 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTextCoord;

out vec2 vTextCoord;

void main()
{
	vTextCoord = aTextCoord;
	gl_Position = vec4(aPos, 0.0f, 1.0f);
}