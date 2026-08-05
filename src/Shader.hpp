
#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>

#include <iostream>
#include <fstream>
#include <sstream>

class Shader {
    GLenum m_type;
    GLuint m_id;

    void compile(std::string source);

public:
    Shader(GLenum type, const char* path);
};

#endif
