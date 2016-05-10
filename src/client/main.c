
/*
** main.c for cmp in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/client
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Wed Apr 20 01:18:58 2016 Frédéric GOMEL
** Last update Tue May 10 15:17:01 2016 Frédéric GOMEL
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include "cmp-client.h"

void	get_msg()
{
  char	titre[30];
  char	timebuf;

  if (recv(sock, &titre, 30, 0) == SOCKET_ERROR)
    exit(EXIT_FAILURE);
  system("clear");
  printf("Musique : %s.\n", titre);
}

void*	get_title(void* data)
{
  sleep(2);
  while (42)
    {
      get_msg();
    }
}

int	main()
{
  int	fd;
  pthread_t	receive;

  copyright_display();
  set_config();
  display_conf();
  pthread_create(&receive, NULL, get_title, NULL);
  reseau();
  return (0);
}
