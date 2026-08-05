
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

    std::string source_string = source_stream.str();

    const char* source = source_string.c_str();

    int status;
    char log[512];

    m_id = glCreateShader(type);

    glShaderSource(m_id, 1, &source, nullptr);
    glCompileShader(m_id);

    glGetShaderiv(m_id, GL_COMPILE_STATUS, &status);
    
    if (!status) {
        glGetShaderInfoLog(m_id, 512, nullptr, log);
        std::cerr << "[Shader] Compilation failed: " << log << '\n';

        return;
    }
}
