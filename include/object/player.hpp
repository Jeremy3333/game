#include <SDL2/SDL.h>
#include "library/Math.hpp"
#include "library/RenderWindow.hpp"

class Player
{
private:
    Vector2f position;
    SDL_Texture *texture;

public:
    Player();
    Player(Vector2f p_position, SDL_Texture *p_texture);
    ~Player();
    void update(const Uint8 *state);
    void render(RenderWindow window);
    Vector2f getPosition();
};