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
		TexCoord = vec2((aPos.x + 0.5), (aPos.y + 0.5));
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
		vec4 texColor = texture(CanvasTex, TexCoord);
		FragColor = texColor;
	}

	)END",







	// BRUSH_VS
	R"END(

	#version 330 core
	layout(location = 0) in vec3 aPos;

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	out vec4 vPos;

	void main()
	{
		vPos = vec4(aPos, 1.0);
		gl_Position = projection * view * model * vec4(aPos, 1.0);
	}

	)END",

	// BRUSH_FS
	R"END(

	#version 330 core

	out vec4 FragColor;

	uniform vec4 Color;

	in vec4 vPos;

	void main()
	{
		if (dot(vPos, vPos) > 1.25) {
			discard;
		}
		FragColor = Color;
	}

	)END",


};