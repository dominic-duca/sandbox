
#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram() {
    m_id = glCreateProgram();
}

void ShaderProgram::attach(const Shader &shader) {
    glAttachShader(m_id, shader.getId());
}
