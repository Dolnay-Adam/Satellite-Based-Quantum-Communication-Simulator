#version 460
precision highp float;

out vec4 outColor;
uniform sampler2D textureColor;

uniform vec2 satProj;

in struct {
	vec3 position;
	vec2 texCoord;
} VSO;

void main(){
	vec3 color = texture(textureColor, VSO.texCoord).xyz;
	outColor = vec4(color, 1.0f);
}