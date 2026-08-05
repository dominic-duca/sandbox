
#include "Shader.hpp"

Shader::Shader(GLenum type, const char* path) : m_type(type) {
    std::ifstream file (path);

    if (!file) {
        std::cerr << "[Shader] Unable to open file: " << path << '\n';

        return;
    }

    std::stringstream source_stream;
    source_stream << file.rdbuf();

    file.close();

    compile(source_stream.str());
}

void Shader::compile(std::string source) {
    const GLchar* source_c = source.c_str();

    int status;
    char log[512];

    m_id = glCreateShader(m_type);

    glShaderSource(m_id, 1, &source_c, nullptr);
    glCompileShader(m_id);

    glGetShaderiv(m_id, GL_COMPILE_STATUS, &status);

    if (!status) {
        glGetShaderInfoLog(m_id, 512, nullptr, log);
        std::cerr << "[Shader] Compilation failed: " << log << '\n';

        return;
    }
}
