#version 460 core

// all glsl source code
//-------------------------

 in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main() {
	FragColor = mix(texture(texture2, texCoord), texture(texture1, texCoord), 0.5);
	  
}
