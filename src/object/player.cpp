#include "object/Player.hpp"
#include "library/Math.hpp"

Player::Player()
{
    position = Vector2f(0, 0);
    texture = NULL;
}

Player::Player(Vector2f p_position, SDL_Texture *p_texture)
{
    position = p_position;
    texture = p_texture;
}

Player::~Player()
{
    SDL_DestroyTexture(texture);
}

void Player::update(const Uint8 *state)
{
    if (state[SDL_SCANCODE_W])
    {
        position += Vector2f(0, -1);
    }
    if (state[SDL_SCANCODE_S])
    {
        position += Vector2f(0, 1);
    }
    if (state[SDL_SCANCODE_A])
    {
        position += Vector2f(-1, 0);
    }
    if (state[SDL_SCANCODE_D])
    {
        position += Vector2f(1, 0);
    }
}

void Player::render(RenderWindow window)
{
    // render player
    window.drawTexture(texture, position.x, position.y, 1);
}