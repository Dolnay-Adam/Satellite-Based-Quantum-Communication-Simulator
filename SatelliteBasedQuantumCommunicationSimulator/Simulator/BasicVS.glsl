#version 460
precision highp float;

uniform mat4 MVP;

layout (location = 0) in vec2 vp;

void main(){
	gl_Position = vec4(vp.x, vp.y, 0.0f, 1.0f) * MVP;
}