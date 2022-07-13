// include my library
#include "library/RenderWindow.hpp"

// include my object
#include "object/player.hpp"

// define constants
#define WINDOW_TITLE "Game"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

/*
 *lien pour compiler (attention a bien mettre le chemin de votre sdl2 et sdl2_image et de le lancer dans le dossier du projet) :
 * Debug:
 * g++ -c src/*.cpp -std=c++14 -g -Wall -m64 -I include -I C:/SDL2-w64/include  && g++ *.o -o bin/debug/main -L C:/SDL2-w64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image && start bin/debug/main
 *
 *Release
 * g++ -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I include -I C:/SDL2-w64/include  && g++ *.o -o bin/release/main -s -L C:/SDL2-w64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image && start bin/release/main
 */

// initialize the variables and objects needed for the game
void init()
{
}

// update the game
void update()
{
}

// render the game
void render()
{
}

// main function
int main(int argc, char **argv)
{
    // initialize SDL
    RenderWindow window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);

    // initialize variables
    SDL_Event event;
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    bool quit = false;

    // init function
    init();

    // main loop
    while (!quit)
    {
        // avoid the program to go too fast
        float startTicks = SDL_GetTicks();
        float timeStepMs = 1000.0f / window.getRefreshRate();

        // get input
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || state[SDL_SCANCODE_ESCAPE])
                quit = true;
        }

        // clear screen
        window.clear();

        // update game
        update();

        // render game
        render();

        // update screen
        window.display();

        // wait for the next frame
        float frameTicks = SDL_GetTicks() - startTicks;
        if (frameTicks < timeStepMs)
            SDL_Delay(timeStepMs - frameTicks);
    }

    // clean up
    window.cleanUp();
    return 0;
}