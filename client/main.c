/*
** main.c for cmp in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/client
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Wed Apr 20 01:18:58 2016 Frédéric GOMEL
** Last update Sun Apr 24 18:53:07 2016 Frédéric GOMEL
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "cmp-client.h"

int	main()
{
  int	fd;

  copyright_display();
  set_config();
  display_conf();
  reseau();
  return (0);
}
