/*
** main.c for cmp in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/client
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Wed Apr 20 01:18:58 2016 Frédéric GOMEL
** Last update Wed Apr 20 01:30:59 2016 Frédéric GOMEL
*/

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
  int	fd;

  if ((fd = open("config.init", O_RDONLY)) == -1)
    create_config();

  return (0);
}
