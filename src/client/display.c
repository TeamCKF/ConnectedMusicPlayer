/*
** display.c for cmp-server in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/server
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Wed Apr 20 15:31:40 2016 Frédéric GOMEL
** Last update Tue May 10 15:55:55 2016 guillaume
*/

#include <stdio.h>
#include "cmp-client.h"
#include "game.h"

void	copyright_display()
{
  printf("==========================================\n");
  printf(" CMP-Server - Copyright(c) - TeamCKF 2016\n");
  printf("==========================================\n");
}

void	display_conf()
{
  if (lang == 1)
    {
      printf("PORT : %i\n",  port);
      printf("ADRESSE : %s\n",  adress);
      printf("TOUCHES :  -q = Quitter\n\t   -n = Suivante\n\t   -p = Precedent\n\t   -r = Reload\n");
    }
  else
    {
      printf("PORT : %i\n", port);
      printf("ADDRESS : %s\n", adress);
      printf("KEYS : -q = Quit\n\t-n = Next\n\t-p = Previous\n\t-s = Pause\n");
    }
}

void    menu()
{
    SDL_WM_SetCaption("Cmp Client - Home", NULL);
    SDL_FillRect(screen.screen, NULL, SDL_MapRGB(screen.screen->format, 255, 255, 255));
    SDL_BlitSurface(screen.prev, NULL, screen.screen, &screen.posprev);
    SDL_BlitSurface(screen.reload, NULL, screen.screen, &screen.posreload);
    SDL_BlitSurface(screen.next, NULL, screen.screen, &screen.posnext);
    SDL_BlitSurface(screen.barre, NULL, screen.screen, &screen.posbarre);
    SDL_BlitSurface(screen.gear, NULL, screen.screen, &screen.posgear);
    SDL_BlitSurface(screen.charge, &screen.poscharge, screen.screen, &screen.posbarre);
    SDL_BlitSurface(screen.texte, NULL, screen.screen, &screen.postext);
    if (screen.poscharge.w > 380)
        screen.poscharge.w = 20;
    if (screen.key_next)
        SDL_BlitSurface(screen.next_c, NULL, screen.screen, &screen.posnext);
    if (screen.key_prev)
        SDL_BlitSurface(screen.prev_c, NULL, screen.screen, &screen.posprev);
    if (screen.key_gear)
        SDL_BlitSurface(screen.gear_c, NULL, screen.screen, &screen.posgear);
    if (screen.key_reload)
        SDL_BlitSurface(screen.reload_c, NULL, screen.screen, &screen.posreload);
    SDL_Flip(screen.screen);
}

void    option()
{
    SDL_WM_SetCaption("Cmp Client - Option", NULL);
    SDL_FillRect(screen.screen, NULL, SDL_MapRGB(screen.screen->format, 255, 255, 255));
    SDL_BlitSurface(screen.home, NULL, screen.screen, &screen.poshome);
    if (screen.key_home)
        SDL_BlitSurface(screen.home_c, NULL, screen.screen, &screen.poshome);
    SDL_Flip(screen.screen);
}
