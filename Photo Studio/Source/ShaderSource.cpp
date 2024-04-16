#include "Shader.h"


std::vector<std::string> Shader::Source = {

	// CANVAS_FS
	R"END(

	#version 330 core

	out vec4 FragColor;

	void main()
	{
		FragColor = vec4(1.0, 1.0, 1.0, 1.0);
	}

	)END",


	// CANVAS_VS
	R"END(

	#version 330 core
	layout(location = 0) in vec3 aPos;

	void main()
	{
		gl_Position = vec4(aPos, 1.0);
	}

	)END",


};