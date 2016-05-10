#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

typedef struct  s_screen
{
    SDL_Surface *screen;
    int         win;

    SDL_Surface *prev;
    SDL_Rect    posprev;
    SDL_Surface *prev_c;
    int         key_prev;

    SDL_Surface *reload;
    SDL_Rect    posreload;
    SDL_Surface *reload_c;
    int         key_reload;

    SDL_Surface *next;
    SDL_Rect    posnext;
    SDL_Surface *next_c;
    int         key_next;

    SDL_Surface *barre;
    SDL_Rect    posbarre;

    SDL_Surface *charge;
    SDL_Rect    poscharge;

    SDL_Surface *gear;
    SDL_Rect    posgear;
    SDL_Surface *gear_c;
    int         key_gear;

    SDL_Surface *home;
    SDL_Rect    poshome;
    SDL_Surface *home_c;
    int         key_home;

    char        titre[30];
    SDL_Surface *texte;
    SDL_Rect    postext;
}               t_screen;

typedef struct  s_police
{
    SDL_Color   black;
    TTF_Font    *verdana;
}               t_police;

char        cmd;
t_screen   screen;
t_police    police;

void        init_screen();
void        init_music();
void        init_key();
void        getImput();
void        scroll();

#endif // GAME_H_INCLUDED
