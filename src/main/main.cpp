// include my library
#include "library/RenderWindow.hpp"

// include my object
#include "object/player.hpp"

// define constants
#define WINDOW_TITLE "Game"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

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
    Player player(Vector2f(0, 0), window.loadTexture("media/img/player/player.png"));

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
        player.update(state);

        // render game
        render();
        window.color(0, 0, 0, 255);
        window.drawBackground();
        player.render(window);

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