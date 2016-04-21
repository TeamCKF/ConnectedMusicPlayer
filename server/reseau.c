/*
** reseau.c for cmp-server in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/server
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Thu Apr 21 15:33:31 2016 Frédéric GOMEL
** Last update Thu Apr 21 16:30:49 2016 Frédéric GOMEL
*/

#if defined (WIN32)

#include <winsock2.h>

typedef int socketlen_t;

#elif defined (linux)

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr	SOCKADDR;


#endif

#include <stdio.h>
#include <stdlib.h>

int	main()
{
  int	port = 1729;
  int	erreur;
  int	sockerreur;

#if defined (WIN32)
  WSADATA WSAData;
  erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
#else
  erreur = 0;
#endif

  /* Server */
  SOCKET	sock;
  SOCKADDR_IN	sin;
  socklen_t sinsize = sizeof(sin);

  /* Client */
  SOCKET	csock;
  SOCKADDR_IN	csin;
  socklen_t csinsize = sizeof(csin);

  if (!erreur)
    {
      sock = socket(AF_INET, SOCK_STREAM, 0);
      if (sock != INVALID_SOCKET)
	{
	  printf("");
	}
    }
  else
    perror("socket");


#if defined (WIN32)
  WSACleanup();
#endif
}
