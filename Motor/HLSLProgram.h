#pragma once
#include <GL/glew.h>
#include <string>
using namespace std;

class HLSLProgram
{
private:
	GLuint programID;
	GLuint fragmentShaderID;
	GLuint vertexShaderID;

	void compileShader(const string& shaderPath, GLuint id);
public:
	HLSLProgram();
	~HLSLProgram();
	int numAtribute;
	void addAtribute(const string sttributeName);
	void use();
	void unuse();
	void compileShaders(const string& vertexShaderFilePath, const string& fragmentShaderFilePath);
	void  linkShader();
	GLuint getUniformLocation(const string& name);
};

