#version 460 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTextCoord;

out vec2 vTextCoord;

uniform mat4 model = mat4(1.0f);

void main()
{
	vTextCoord = aTextCoord;
	gl_Position = model * vec4(aPos, 0.0, 1.0);
}