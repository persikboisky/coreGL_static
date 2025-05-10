#version 460 core

out vec4 f_color;

in vec2 vTextCoord;

//uniform sampler2D sampleTexture;

void main()
{
	f_color = vec4(1, 1, 1, 1);// * texture(sampleTexture, vTextCoord);
}