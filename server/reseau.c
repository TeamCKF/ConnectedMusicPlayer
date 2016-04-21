/*
** reseau.c for cmp-server in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/server
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Thu Apr 21 15:33:31 2016 Frédéric GOMEL
** Last update Thu Apr 21 15:53:08 2016 Frédéric GOMEL
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

#include <stdio.h>
#include <stdlib.h>

int	reseau()
{
#if defined (WIN32)
  WSADATA WSAData;
  WSAStartup(MAKEWORD(2,2), &WSAData);
#endif

}
