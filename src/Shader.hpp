
#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>

class Shader {
    GLenum m_type;
    GLuint m_id;

public:
    Shader(GLenum type, const char* path);
};

#endif
