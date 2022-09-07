#ifndef GAME_HPP
#define GAME_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_timer.h"

#include "player.hpp"

class Game {
    public:
        Game(const char* title, int width, int height, unit32 flags, PlayerV* player_values);
        ~Game();
        void draw();
        void update();
    private:
        Player* player;
        SDL_Renderer* renderer;
        SDL_Window* window;
};

#endif