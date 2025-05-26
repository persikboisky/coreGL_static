#version 460 core

in vec2 vTextCoord;
out vec4 f_color;

uniform vec4 uColor = vec4(255.0f, 255.0f, 255.0f, 255.0f);
uniform sampler2D uTexture;

void main()
{
	vec4 finish_uClor = vec4(uColor.r / 255.0f, uColor.g / 255.0f, uColor.b / 255.0f, uColor.a / 255.0f);
	f_color = finish_uClor * texture(uTexture, vTextCoord);
}