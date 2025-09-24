#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("MineSweeper",640, 480, 0);
    if (window == nullptr) 
	{
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event e;
    bool quit = false;

    while (!quit) 
	{
        while (SDL_PollEvent(&e)) 
		{
            if (e.type == SDL_EVENT_QUIT) 
			{
                quit = true;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
