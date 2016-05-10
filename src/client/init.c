/*
** initialisation lib SDL & FMOD
*/

#include "game.h"

void        init_screen()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Could not initialize SDL : %s\n", SDL_GetError());
        exit(1);
    }
    if ((screen.screen = SDL_SetVideoMode(400, 100, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    {
        fprintf(stderr, "Couldn't set screen mode : %s", SDL_GetError());
        exit(1);
    }
    if (TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
}

void        cleanup()
{
    TTF_Quit();

    SDL_FreeSurface(screen.barre);
    SDL_FreeSurface(screen.charge);
    SDL_FreeSurface(screen.gear);
    SDL_FreeSurface(screen.gear_c);
    SDL_FreeSurface(screen.home);
    SDL_FreeSurface(screen.home_c);
    SDL_FreeSurface(screen.next);
    SDL_FreeSurface(screen.next_c);
    SDL_FreeSurface(screen.prev);
    SDL_FreeSurface(screen.prev_c);
    SDL_FreeSurface(screen.reload);
    SDL_FreeSurface(screen.reload_c);
    SDL_FreeSurface(screen.texte);

    SDL_Quit();
}
