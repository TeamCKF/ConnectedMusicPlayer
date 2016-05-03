/*
** display.c for cmp-server in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/server
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Wed Apr 20 15:31:40 2016 Frédéric GOMEL
** Last update Mon May  2 17:00:21 2016 Mineshot03
*/

#include <stdio.h>
#include "cmp-server.h"

void	copyright_display()
{
  printf("\033[33m==========================================\n");
  printf("\033[31m CMP-Server - Copyright(c) - TeamCKF 2016\n");
  printf("\033[33m==========================================\n\033[00m");
}

void	display_conf()
{
  if (lang == 1)
    {
      printf("%s CHEMIN MUSIQUE :%s %s\n", RED, REINIT, path_music);
      printf("%s PORT : %s %i\n", RED, REINIT, port);
      printf("%s TOUCHES :%s -q = Quitter\n\t   -n = Suivante\n\t   -p = Précédent\n\t   -r = Recharger la playlist\n\t   -s = Pause\n", RED, REINIT);
    }
  else
    {
      printf("%s PATH MUSIC :%s %s\n",RED, REINIT, path_music);
      printf("%s PORT :%s %i\n", RED, REINIT, port);
      printf("%s KEYS :%s -q = Quit\n\t-n = Next\n\t-p = Previous\n\t   -r = Reload playlist\n\t   -s = Pause\n", RED, REINIT);
    }
}
