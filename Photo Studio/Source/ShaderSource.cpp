#include "Shader.h"


std::vector<std::string> Shader::Source = {


	// CANVAS_VS
	R"END(

	#version 330 core
	layout(location = 0) in vec3 aPos;

	out vec2 TexCoord;

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	void main()
	{
		TexCoord = vec2(aPos.x, aPos.y);
		gl_Position = projection * view * model * vec4(aPos, 1.0);
	}

	)END",

	// CANVAS_FS
	R"END(

	#version 330 core

	out vec4 FragColor;

	in vec2 TexCoord;

	uniform sampler2D CanvasTex;

	void main()
	{
		FragColor = texture(CanvasTex, TexCoord);// + vec4(1.0, 1.0, 1.0, 1.0);
	}

	)END",







	// BRUSH_VS
	R"END(

	#version 330 core
	layout(location = 0) in vec3 aPos;

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	void main()
	{
		gl_Position = projection * view * model * vec4(aPos, 1.0);
	}

	)END",

	// BRUSH_FS
	R"END(

	#version 330 core

	out vec4 FragColor;

	void main()
	{
		FragColor = vec4(1.0, 0.0, 0.0, 1.0);
	}

	)END",


};