/*
** display.c for cmp-server in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/server
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Wed Apr 20 15:31:40 2016 Frédéric GOMEL
** Last update Sun Apr 24 18:56:31 2016 Frédéric GOMEL
*/

#include <stdio.h>
#include "cmp-client.h"

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
      printf("%s PORT : %s %i\n", RED, REINIT, port);
      printf("%s ADDRESSE : %s %s\n", RED, REINIT, adress);
      printf("%s TOUCHES :%s -q = Quitter\n\t   -n = Suivante\n\t   -p = Précédent\n\t   -s = Pause\n", RED, REINIT);
    }
  else
    {
      printf("%s PORT :%s %i\n", RED, REINIT, port);
      printf("%s ADDRESS : %s %s\n", RED, REINIT, adress);
      printf("%s KEYS :%s -q = Quit\n\t-n = Next\n\t-p = Previous\n\t-s = Pause\n", RED, REINIT);
    }
}
