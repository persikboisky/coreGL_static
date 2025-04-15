#version 460 core

out vec4 f_color;

in vec2 vCoordTexture;

uniform sampler2D Texture;
uniform vec4 vColor = vec4(1, 1, 1, 1);

void main()
{
	f_color = vColor * texture(Texture, vCoordTexture);
}