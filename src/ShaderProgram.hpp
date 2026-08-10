
#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include "Shader.hpp"

class ShaderProgram {
    GLuint m_id;

public:
    ShaderProgram();

    void attach(const Shader &shader);
    
    void link();

    void use();
};

#endif
