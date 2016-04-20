/*
** config.c for cmp in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/client
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Wed Apr 20 16:24:15 2016 Frédéric GOMEL
** Last update Wed Apr 20 16:52:27 2016 Frédéric GOMEL
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "cmp-client.h"
#include "get_next_line.h"

char	portp[5];

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

void	set_port()
{
  if (lang == 1)
    printf("Désignez le port de connection au serveur. Entrez 0 pour le port par défault (1729)\n");
  else
    printf("Put the port of the server. Put 0 to use the default port (1729)\n");
  scanf("%s", portp);
  port = atoi(portp);
  if (port == 0)
    {
      port = 1729;
      strcpy(portp, "1729");
    }
}

void	set_adress()
{
  if (lang == 1)
    printf("Saisissez l'adresse du serveur CMP (Example : 192.168.1.1 ou lavevaisselle.com)\n");
  else
    printf("Put the adress of the server CMP. (Exemple : 192.168.1.1 or shower.com)\n");
  adress = gnl(0);
}

void	create_file()
{
  int	fd;

  fd = open("config.ini", O_CREAT | O_WRONLY, 0660);
  write(fd, "LANG=", 5);
  if (lang == 1)
    write(fd, "Fr_fr\n", 6);
  else
    write(fd, "En_us\n", 6);
  write(fd, "PORT=", 6);
  write(fd, portp, strlen(portp));
  write(fd, "\nADRESS=", 8);
  write(fd, adress, strlen(adress));
}

void	create_config()
{
  printf("\033[32mWelcome to ConnectedMusicPlayer-Client configuration system.\n\033[00m");
  set_language();
  set_port();
  set_adress();
  create_file();
}
