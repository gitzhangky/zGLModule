#version 450 core

layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec3 aColor;

out vec3 ourColor;

void main()
{
	gl_Position = vec4(vPosition,1.0);
	ourColor = vPosition;
}