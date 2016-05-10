/*
** Main
*/

#include "game.h"
#include "cmp-client.h"

void    aff()
{
    if (screen.win == 1)
        menu();
    else if (screen.win == 2)
        option();
}

void    load_texture()
{
    screen.prev = IMG_Load("resources/prev.png");
    screen.prev_c = IMG_Load("resources/prev_c.png");
    screen.posprev.x = 144;
    screen.posprev.y = 60;

    screen.reload = IMG_Load("resources/reload.png");
    screen.reload_c = IMG_Load("resources/reload_c.png");
    screen.posreload.x = 184;
    screen.posreload.y = 60;

    screen.next = IMG_Load("resources/next.png");
    screen.next_c = IMG_Load("resources/next_c.png");
    screen.posnext.x = 224;
    screen.posnext.y = 60;

    screen.barre = IMG_Load("resources/barre.png");
    screen.posbarre.x = 0;
    screen.posbarre.y = 20;

    screen.charge = IMG_Load("resources/charge.png");
    screen.poscharge.h = 50;
    screen.poscharge.w = 20;

    screen.gear = IMG_Load("resources/gear.png");
    screen.gear_c = IMG_Load("resources/gear_c.png");
    screen.posgear.x = 370;
    screen.posgear.y = 70;

    screen.home = IMG_Load("resources/home.png");
    screen.home_c = IMG_Load("resources/home_c.png");
    screen.poshome.x = 370;
    screen.poshome.y = 70;

    police.verdana = TTF_OpenFont("resources/verdanab.ttf", 12);
    police.black.b = 0;
    police.black.g = 0;
    police.black.r = 0;
    screen.postext.x = 30;
    screen.postext.y = 20;
}

void*   get_title(void *data)
{
  char	titre[40];

  while (42)
    {
      recv(sock, titre, 40, 0);
      screen.texte = TTF_RenderText_Blended(police.verdana, titre, police.black);
    }
}

int main(int argc, char **argv)
{
    int   fd;
    pthread_t   receive;

    screen.win = 1;
    init_screen();
    load_texture();
    copyright_display();
    adress = "90.127.21.186";
    port = 1729;
    lang = 1;
    //set_config();
    pthread_create(&receive, NULL, get_title, NULL);
    display_conf();
    reseau();
    return 0;
}
