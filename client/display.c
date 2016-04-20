/*
** display.c for cmp in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/client
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Wed Apr 20 16:50:24 2016 Frédéric GOMEL
** Last update Wed Apr 20 16:50:41 2016 Frédéric GOMEL
*/

#include <stdio.h>
#include "cmp-client.h"

void	copyright_display()
{
  printf("\033[33m==========================================\n");
  printf("\033[31m CMP-Client - Copyright(c) - TeamCKF 2016\n");
  printf("\033[33m==========================================\n\033[00m");
}

void	display_conf()
{
  if (lang == 1)
    {
      printf("%s LANGUE :%s %s\n", RED, REINIT, "FR_fr");
      printf("%s ADRESSE :%s %s\n", RED, REINIT, adress);
      printf("%s PORT : %s %i\n", RED, REINIT, port);
    }
  else
    {
      printf("%s LANGUAGE :%s %s\n", RED, REINIT, "EN_us");
      printf("%s ADRESS :%s %s\n", RED, REINIT, adress);
      printf("%s PORT :%s %i\n", RED, REINIT, port);
    }
}
