/*
** Gestion ecran
*/

#include <stdbool.h>
#include "game.h"
#include "cmp-client.h"

void        getImput()
{
    SDL_Event   event;
    SDL_WaitEvent(&event);

    switch(event.type)
    {
    case SDL_QUIT:
        cmd = 'q';
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            if (screen.win == 1)
                event_home(event, 1);
            else if (screen.win == 2)
                event_option(event, 1);
        }
        break;
    case SDL_MOUSEBUTTONUP:
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            if (screen.win == 1)
                event_home(event, 2);
            else if (screen.win == 2)
                event_option(event, 2);
            else
            screen.key_prev = false;
            screen.key_reload = false;
            screen.key_next = false;
            screen.key_gear = false;
            screen.key_home = false;
        }
        break;
    default:
        cmd = 0;
        screen.key_home = false;
        screen.key_prev = false;
        screen.key_reload = false;
        screen.key_next = false;
        screen.key_gear = false;
        break;
    }
}

void    event_home(SDL_Event event, int i)
{
    if (i == 1)
    {
        if (event.button.x > 144 && event.button.y > 60 &&
            event.button.x < 176 && event.button.y < 92)
                screen.key_prev = true;
        if (event.button.x > 184 && event.button.y > 60 &&
            event.button.x < 216 && event.button.y < 92)
                screen.key_reload = true;
        if (event.button.x > 224 && event.button.y > 60 &&
            event.button.x < 256 && event.button.y < 92)
                screen.key_next = true;
        if (event.button.x > 370 && event.button.y > 70 &&
            event.button.x < 400 && event.button.y < 100)
                screen.key_gear = true;
    }
    else if (i == 2)
    {
        if (event.button.x > 144 && event.button.y > 60 &&
            event.button.x < 176 && event.button.y < 92)
                cmd = 'p';
        if (event.button.x > 184 && event.button.y > 60 &&
            event.button.x < 216 && event.button.y < 92)
                cmd = 'r';
        if (event.button.x > 224 && event.button.y > 60 &&
            event.button.x < 256 && event.button.y < 92)
                cmd = 'n';
        if (event.button.x > 370 && event.button.y > 70 &&
            event.button.x < 400 && event.button.y < 100)
                screen.win = 2;
    }
}

void    event_option(SDL_Event event, int i)
{
    if (i == 1)
    {
        if (event.button.x > 370 && event.button.y > 70 &&
            event.button.x < 400 && event.button.y < 100)
                screen.key_home = true;
    }
    else if (i == 2)
    {
        if (event.button.x > 370 && event.button.y > 70 &&
            event.button.x < 400 && event.button.y < 100)
                screen.win = 1;
    }
}
