#version 460 core

// all glsl source code
//-------------------------

layout (location = 0) in vec3 aPos;
// layout (location = 1) in vec2 aTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

 out vec2 texCoord;

void main() {
	gl_Position = projection * view * model * vec4(aPos, 1.0f);
	texCoord = vec2(texCoord.x, 1.0 - texCoord.y);
}
