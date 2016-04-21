
/*
** config.c for cmp-server in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/server
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Wed Apr 20 00:54:59 2016 Frédéric GOMEL
** Last update Thu Apr 21 15:34:18 2016 Frédéric GOMEL
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "cmp-server.h"

char	portp[5];

void	set_port()
{
  if (lang == 1)
    printf("Désignez le port à utiliser pour communiquer avec les clients. Entrez 0 pour le port par défault (1729)\n");
  else
    printf("Put the port you want to use to communicate with the clients. Put 0 to use the default port (1729)\n");
  scanf("%s", portp);
  port = atoi(portp);
  if (port == 0)
    {
      port = 1729;
      strcpy(portp, "1729");
    }
}

void	set_language()
{
  printf("Choose language : 1 - Fr, 2 - En\n # ");
  scanf("%i", &lang);
  if (lang != 1 && lang != 2)
    lang = 0;
  while (lang == 0)
    {
      printf("Wrong. You didn't choose a correct language : 1 - Fr, 2 - En\n # ");
      scanf("%i", &lang);
      if (lang != 1 && lang != 2)
	lang = 0;
    }
  if (lang == 1)
    printf("Cool, un français :P. Bienvenue.\n");
  else
    printf("You choose the international language ! Great i didn't do the translation for nothing ;)\n");
}

void	set_path()
{
  if (lang == 1)
    printf("Veuillez indiquer le chemin vers le répertoire contenant la musique.\n");
  else
    printf("Write the path to the directory where the music is.\n");
  path_music = gnl(0);
}

void	set_file()
{
  int	fd;

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
  close(fd);
}

void	create_config()
{
  printf("\033[32mWelcome to the ConnectedMusicPlayer-Server configuration system\n\033[00m");
  set_language();
  set_path();
  set_port();
  set_file(portp);
}
