/*
** main.c for cmp in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/client
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Wed Apr 20 01:18:58 2016 Frédéric GOMEL
** Last update Fri Apr 22 00:03:10 2016 Frédéric GOMEL
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "cmp-client.h"

void	read_conf(int fd)
{
  char	*para;
  char	*portp;
  int	i;
  int	j;

  i = (j = 0);
  para = gnl(fd);
  if (equal_char(para, "LANG=Fr_fr") == 1)
    lang = 1;
  else
    lang = 2;
  para = gnl(fd);
  if ((portp = malloc(sizeof(char) * lenght(para))) == NULL)
    exit(EXIT_FAILURE);
  while (para[i] != '=')
    i++;
  if (para[i] == '=')
    i++;
  while (para[i] != '\0')
    portp[j++] = para[i++];
  port = atoi(portp);
  para = gnl(fd);
  if ((adress = malloc(sizeof(char) * lenght(para))) == NULL)
    exit(EXIT_FAILURE);
  i = (j = 0);
  while (para[i] != '=')
    i++;
  if (para[i] == '=')
    i++;
  while (para[i] != '\0')
    adress[j++] = para[i++];
}

int	main()
{
  int	fd;
  char	cmd;

  copyright_display();
  if ((fd = open("config.ini", O_RDONLY)) == -1)
    create_config();
  else
    read_conf(fd);
  display_conf();
  cmd = getchar();
  reseau();
  return (0);
}
