/*
** main.c for main.c in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/server
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Tue Apr 19 15:37:59 2016 Frédéric GOMEL
** Last update Fri Apr 22 00:25:06 2016 Frédéric GOMEL
*/

#if defined (WIN32)

#include <winsock2.h>

#elif defined (linux)

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#endif

#include <fmod.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <pthread.h>
#include "get_next_line.h"
#include "cmp-server.h"

void	get_parameters(int fd)
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
  close(fd);
}

int	main()
{
  int fd;
  pthread thread_reseau;

  copyright_display();
  if ((fd = open("config.cfg", O_RDONLY)) == -1)
    create_config();
  else
    get_parameters(fd);
  display_conf();
  init_system();
  pthread_create(&thread_reseau, NULL, reseau, NULL)
  //while (42)
  //play();

#if defined (WIN32)
  WSACleanup();
#endif
  return (0);
}
