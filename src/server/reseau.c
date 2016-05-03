/*
** reseau.c for cmp-server in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/server
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Thu Apr 21 15:33:31 2016 Frédéric GOMEL
** Last update Tue May  3 16:41:29 2016 Frédéric GOMEL
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
#include "cmp-server.h"

void*	reseau(void* data)
{
  int	erreur;
  int	yes;
  int	connected;
  int	sock_err;
  //int	thread_used[max_client];
  int	i;

#if defined (WIN32)
  WSADATA WSAData;
  erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
#else
  erreur = 0;
#endif

  yes = 1;
  i = 0;
  //  max_client = 2;
  /* while (i != max_client) */
  /*   { */
  /*     max_client[i++] = 0; */
  /*   } */
  connected = 0;
  /* Server */
  SOCKET	sock;
  SOCKADDR_IN	sin;
  socklen_t sinsize = sizeof(sin);

  /* Client */
  SOCKET	csock;
  SOCKADDR_IN	csin;
  socklen_t csinsize = sizeof(csin);

  pthread_t	thread_client[max_client];
  while (42)
    {
      if (!erreur)
	{
	  sock = socket(AF_INET, SOCK_STREAM, 0);
	  if (sock != INVALID_SOCKET)
	    {
	      printf("Socket N°%d ouvert en TCP/IP\n", sock);
	      sin.sin_addr.s_addr = htonl(INADDR_ANY);
	      sin.sin_family = AF_INET;
	      sin.sin_port = htons(port);
	      if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes,sizeof(int)) == -1)
		{
		  perror("setsockopt");
		  close(sock);
#if defined (WIN32)
		  WSACleanup();
#endif
		  exit(EXIT_FAILURE);
		}
	      sock_err = bind(sock, (SOCKADDR*)&sin, sinsize);

	      if (sock_err != SOCKET_ERROR)
		{
		  sock_err = listen(sock, 5);
		  if (connected == 0)
		    printf("Ecoute du port %d...\n", port);

		  if (sock_err != SOCKET_ERROR)
		    {
		      printf("Ecoute de client sur le port %d...\n", port);
		      csock = accept(sock, (SOCKADDR*)&csin, &csinsize);
		      printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
		  while (recv(csock, &cmd, 1, 0) != SOCKET_ERROR && cmd != 'q')
		    printf("Commande : %c\n", cmd);
		    }
		  else
		    perror("listen");
		}
	      else
		perror("bind");
	    }
	  printf("Fermeture du socket client\n");
	  close(csock);
	  printf("Fermeture de la socket serveur\n");
	  close(sock);
	  printf("Fermeture de port terminée\n");
	  connected = 1;
	}
      else
	perror("socket");
#if defined (WIN32)
      WSACleanup();
#endif
    }
}
