/*
** main.c for main.c in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/server
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Tue Apr 19 15:37:59 2016 Frédéric GOMEL
** Last update Tue Apr 19 18:22:13 2016 Frédéric GOMEL
*/

#include <fmod.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include "get_next_line.h"

char *path_music;
int  lang;
int  port;

void	copyright_display()
{
  printf("\033[33m==========================================\n");
  printf("\033[31m CMP-Server.  Copyright (c) TeamCKF 2016.\n");
  printf("\033[33m==========================================\n");
}

void	create_config()
{
  int	nombre;
  int	fd;
  char	portp[5];

  printf("\033[32mWelcome to the assistance of configuration of ConnectedMusiquePlayer - Server.\n\033[00m");
  printf("Choose your language : 1 - Fr, 2 - En\n # ");
  scanf("%i", &lang);
  while (lang <= 0 && lang >= 3)
    {
      printf("Wrong. You didn't choose a correct language : 1 - Fr, 2 - En\n");
      scanf("%i", &lang);
    }
  if (lang == 1)
    {
      printf("Cool, un français :P. Bienvenue.\n");
      printf("Veuillez indiquer le chemin vers le répertoire contenant la musique.\n");
      path_music = gnl(0);
      printf("Désignez le port à utiliser pour connecter les clients au server. Entrez 0 pour le port par défault (1729)\n");
      scanf("%s", portp);
      port = atoi(portp);
      if (port == 0)
	{
	  port = 1729;
	  strcpy(portp, "1729");
	}
    }
  else
    {
      printf("You choose the international language ! Great i didn't do the translation for nothing ;)\n");
      printf("Write the path to the directory where the music is.\n");
      path_music = gnl(0);
      printf("Put the port you want to use to communicate with the clients. Put 0 to use the default port (1729)\n");
      scanf("%s", portp);
      port = atoi(portp);
      if (port == 0)
	{
	  port = 1729;
	  strcpy(portp, "1729");
	}
    }
  fd = open("config.cfg", O_CREAT | O_WRONLY, 0660);
  write(fd, "LANG=", 5);
  if (lang == 1)
    write(fd, "Fr_fr\n", 6);
  else
    write(fd, "En_us\n", 6);
  write(fd, "PATH=", 5);
  write(fd, path_music, strlen(path_music));
  write(fd, "\nPORT=", 6);
  write(fd, portp, strlen(portp));
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
  if (lang == 1)
    {
      printf("CHEMIN MUSIQUE : %s\n", path_music);
      printf("PORT : %i\n", port);
    }
  else
    {
      printf("PATH MUSIC : %s\n", path_music);
      printf("PORT : %i\n", port);
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
}
