#include "Shader.h"

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glad/glad.h>

#include <fstream>

void Shader::CreateShader(std::string VertexShader, std::string FragmentShader) {
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* VS = VertexShader.c_str();
    glShaderSource(vertexShader, 1, &VS, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* FS = FragmentShader.c_str();
    glShaderSource(fragmentShader, 1, &FS, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    this->Program = glCreateProgram();
    glAttachShader(this->Program, vertexShader);
    glAttachShader(this->Program, fragmentShader);
    glLinkProgram(this->Program);
    // check for linking errors
    glGetProgramiv(this->Program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->Program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}
std::string Shader::ReadShaderFile(std::string FileName) {
    std::ifstream File("shaders/" + FileName);
    std::string Line, Contents;
    while (std::getline(File, Line)) {
        Contents += Line + '\n';
    }
    return Contents;
}

Shader::Shader(std::string VertexShader, std::string FragmentShader) {
    this->CreateShader(this->ReadShaderFile(VertexShader), this->ReadShaderFile(FragmentShader));
}
Shader::Shader(const ShaderType VertexShader, const ShaderType FragmentShader) : VertexShader(VertexShader), FragmentShader(FragmentShader) {
    this->CreateShader(this->Source[(int)VertexShader], this->Source[(int)FragmentShader]);
}
Shader::~Shader() {
    glDeleteProgram(this->Program);
}

unsigned int Shader::GetUniformLocation(const std::string& UniformName) {
    auto Uniform = this->UniformLocations.find(UniformName);
    if (Uniform == this->UniformLocations.end()) {
        unsigned int Location = glGetUniformLocation(this->Program, UniformName.c_str());
        this->UniformLocations.insert({ UniformName, Location });
        return Location;
    }
    return Uniform->second;
}

template<typename T>
void Shader::Uniform(const std::string& UniformName, const T& Value) {
    std::cout << "Type not supported (yet)\n";
}

template<>
void Shader::Uniform<float>(const std::string& UniformName, const float& Value) {
    unsigned int Location = this->GetUniformLocation(UniformName);
    glUniform1f(Location, Value);
}

template<>
void Shader::Uniform<glm::mat4>(const std::string& UniformName, const glm::mat4& Value) {
    unsigned int Location = this->GetUniformLocation(UniformName);
    glUniformMatrix4fv(Location, 1, GL_FALSE, &Value[0][0]);
}

template<>
void Shader::Uniform<int>(const std::string& UniformName, const int& Value) {
    unsigned int Location = this->GetUniformLocation(UniformName);
    glUniform1i(Location, Value);
}

template<>
void Shader::Uniform<glm::vec3>(const std::string& UniformName, const glm::vec3& Value) {
    unsigned int Location = this->GetUniformLocation(UniformName);
    glUniform3f(Location, Value[0], Value[1], Value[2]);
}

template<>
void Shader::Uniform<glm::vec4>(const std::string& UniformName, const glm::vec4& Value) {
    unsigned int Location = this->GetUniformLocation(UniformName);
    glUniform4f(Location, Value[0], Value[1], Value[2], Value[3]);
}

//template void Shader::Uniform<int>(const std::string&, float);

void Shader::UseProgram() const {
    glUseProgram(this->Program);
}