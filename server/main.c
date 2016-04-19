/*
** main.c for main.c in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/server
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Tue Apr 19 15:37:59 2016 Frédéric GOMEL
** Last update Wed Apr 20 01:12:13 2016 Frédéric GOMEL
*/

#include <fmod.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include "get_next_line.h"
#include "cmp-server.h"

void	copyright_display()
{
  printf("\033[33m==========================================\n");
  printf("\033[31m CMP-Server - Copyright(c) - TeamCKF 2016\n");
  printf("\033[33m==========================================\n\033[00m");
}

int	equal_char(char *src, char *comp)
{
  int	i;

  i = 0;
  while (src[i] && comp[i])
    {
      if (src[i] == comp[i])
	i++;
      else
	return (0);
    }
  if (src[i] == '\0')
    return (1);
  return (0);
}

int	lenght(char *str)
{
  int	i;
  int	j;

  i = (j = 0);
  while (str[i] != '=')
    i++;
  if (str[i] == '=')
    i++;
  while (str[i] != '\0')
    {
      i++;
      j++;
    }
  return j;
}

void	get_path(int fd)
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
  if ((path_music = malloc(sizeof(char) * lenght(para))) == NULL)
    exit(EXIT_FAILURE);
  while (para[i] != '=')
    i++;
  if (para[i] == '=')
    i++;
  while (para[i] != '\0')
    path_music[j++] = para[i++];
  para = gnl(fd);
  if ((portp = malloc(sizeof(char) * lenght(para))) == NULL)
    exit(EXIT_FAILURE);
  i = (j = 0);
  while (para[i] != '=')
    i++;
  if (para[i] == '=')
    i++;
  while (para[i] != '\0')
    portp[j++] = para[i++];
  port = atoi(portp);
}

void	display_conf()
{
  if (lang == 1)
    {
      printf("%s CHEMIN MUSIQUE :%s %s\n", RED, REINIT, path_music);
      printf("%s PORT : %s %i\n", RED, REINIT, port);
    }
  else
    {
      printf("%s PATH MUSIC :%s %s\n",RED, REINIT, path_music);
      printf("%s PORT :%s %i\n", RED, REINIT, port);
    }
}

int	main(int ac, char **av)
{
  int fd;

  copyright_display();
  if ((fd = open("config.cfg", O_RDONLY)) == -1)
    create_config();
  else
    get_path(fd);
  display_conf();
}
