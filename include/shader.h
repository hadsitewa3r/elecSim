#pragma once

#include "glad.h"

struct Shader{
	unsigned int id;
};

inline const void compile_and_attach_file(Shader* shader, const char* fragmentPath, const char* vertexPath){
	
}

inline const void use(const Shader* shader){
	glUseProgram(shader->id);
}

inline const void setBool (const Shader* shader, const char* u_Name, bool u_Value){
	GLint location = glGetUniformLocation(shader->id, u_Name);
	glUniform1i(location, (int) u_Value);
}

inline const void setInt (const Shader* shader, const char* u_Name, GLint u_Value){
	GLint location = glGetUniformLocation(shader->id, u_Name);
	glUniform1i(location, u_Value);
}

inline const void setFloat(const Shader* shader, const char* u_Name, GLfloat u_Value){
	GLint location = glGetUniformLocation(shader->id, u_Name);
	glUniform1f(location, u_Value);
}

inline const void setVec2 (const Shader* shader, const char* u_Name, GLfloat x, GLfloat y){
	GLint location = glGetUniformLocation(shader->id, u_Name);
	glUniform2f(location, x, y);
}




inline const void setVec3 (const Shader* shader, const char* u_Name, GLfloat x, GLfloat y, GLfloat z){
	GLint location = glGetUniformLocation(shader->id, u_Name);
	glUniform3f(location, x, y, z);
}




inline const void setVec4 (const Shader* shader, const char* u_Name, GLfloat x, GLfloat y, GLfloat z, GLfloat w){
	GLint location = glGetUniformLocation(shader->id, u_Name);
	glUniform4f(location, x, y, z, w);
}



