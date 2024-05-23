#version 460
precision highp float;

layout (location = 0) in vec3 vp;
layout (location = 1) in vec2 texCoord;

out struct{
	vec3 position;
	vec2 texCoord;
} VSO;

uniform mat4 MVP;

void main(){
	vec4 p = vec4(vp, 1.0f) * MVP;
	VSO.position = p.xyz;
	VSO.texCoord = texCoord;
	gl_Position = vec4(vp.x, vp.y, 1.0f, 1.0f);
}