#pragma once

#include <string>
#include <vector>
#include <unordered_map>

enum class ShaderType {
	CANVAS_VS, CANVAS_FS,
	BRUSH_VS, BRUSH_FS,
};

class Shader
{
private:
	ShaderType VertexShader;
	ShaderType FragmentShader;
	unsigned int Program;
	std::unordered_map<std::string, int> UniformLocations;
	static std::vector<std::string> Source;
private:
	void CreateShader(std::string VertexShader, std::string FragmentShader);
	std::string ReadShaderFile(std::string FileName);
public:
	Shader(const ShaderType VertexShader, const ShaderType FragmentShader);
	Shader(std::string VertexShader, std::string FragmentShader);
	Shader() {}
	~Shader();
	unsigned int GetUniformLocation(const std::string& UniformName);
	template<typename T>
	void Uniform(const std::string& UniformName, const T& Value);
	void UseProgram() const;
};
