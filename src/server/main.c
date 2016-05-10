/*
** main.c for main.c in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/server
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Tue Apr 19 15:37:59 2016 Frédéric GOMEL
** Last update Tue May 10 15:29:47 2016 Frédéric GOMEL
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
#include <signal.h>
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

void	sendtitle()
{
  int	i;
  char	c;

  if (thread_used[0] == 1)
    send(client1, &titre, 40, 0);
  if (thread_used[1] == 1)
    send(client2, &titre, 40, 0);
  if (thread_used[2] == 1)
    send(client3, &titre, 40, 0);
  if (thread_used[3] == 1)
    send(client4, &titre, 40, 0);
  if (thread_used[4] == 1)
    send(client5, &titre, 40, 0);
  if (thread_used[5] == 1)
    send(client6, &titre, 40, 0);
  if (thread_used[6] == 1)
    send(client7, &titre, 40, 0);
  if (thread_used[7] == 1)
    send(client8, &titre, 40, 0);
  if (thread_used[8] == 1)
    send(client9, &titre, 40, 0);
  if (thread_used[9] == 1)
    send(client10, &titre, 40, 0);
  alarm(1);
}

int	main()
{
  int	fd;
  pthread_t thread_reseau;

  signal(SIGALRM, sendtitle);
  copyright_display();
  if ((fd = open("config.cfg", O_RDONLY)) == -1)
    create_config();
  else
    get_parameters(fd);
  display_conf();
  init_system();
  pthread_create(&thread_reseau, NULL, reseau, NULL);
  alarm(2);
  while (42)
    play();

#if defined (WIN32)
  WSACleanup();
#endif
  return (0);
}
