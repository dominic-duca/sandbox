
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

    SDL_Quit();

    return EXIT_SUCCESS;
}
