
#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram() {
    m_id = glCreateProgram();
}

void ShaderProgram::attach(const Shader &shader) {
    glAttachShader(m_id, shader.getId());
}

void ShaderProgram::link() {
    int status;
    char log[512];

    glLinkProgram(m_id);

    glGetProgramiv(m_id, GL_LINK_STATUS, &status);

    if (!status) {
        glGetProgramInfoLog(m_id, 512, nullptr, log);
        std::cerr << "[ShaderProgram] Link failed: " << log << '\n';

        return;
    }
}

void ShaderProgram::use() {
    glUseProgram(m_id);
}
