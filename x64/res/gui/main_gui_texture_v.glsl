#version 460 core

layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 aCoordTexture;

out vec2 vCoordTexture;

void main()
{
	vCoordTexture = aCoordTexture;
	gl_Position = vec4(pos, 0.0, 1.0);
}