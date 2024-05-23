#version 460
precision highp float;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

layout (location = 0) in vec3 vp;

void main(){
	gl_Position = vec4(vp.x, vp.y, vp.z, 1.0f) * M * V * P;
}