
#include <glad/glad.h>
#include <SDL3/SDL.h>

#include <stdexcept>

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "SDL Init Failure - %s", SDL_GetError());
        
        return EXIT_FAILURE;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_Window* window = SDL_CreateWindow("Sandbox", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);

    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "Window Init Failure - %s", SDL_GetError());

        return EXIT_FAILURE;
    }

    SDL_GLContext gl_context = SDL_GL_CreateContext(window);

    if (gl_context == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "OpenGL Context Failure - %s", SDL_GetError());

        return EXIT_FAILURE;
    }

    if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "GLAD Init Failure - %s", SDL_GetError());
        
        return EXIT_FAILURE;
    }

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    bool window_open = true;

    while (window_open) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                window_open = false;
                
                break;

                case SDL_EVENT_KEY_DOWN:
                switch (event.key.key) {
                    case SDLK_ESCAPE:
                    window_open = false;
                    
                    break;
                }

                break;
            }
        }

        glClearColor(135.0f / 255.0f, 206.0f / 255.0f, 235.0f / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DestroyContext(gl_context);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return EXIT_SUCCESS;
}
