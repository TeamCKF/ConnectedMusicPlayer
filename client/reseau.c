
/*
** reseau.c for cmp in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/client
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Thu Apr 21 17:23:29 2016 Frédéric GOMEL
** Last update Fri Apr 22 02:31:58 2016 Frédéric GOMEL
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
#include "wincompat.h"
#include "cmp-client.h"

void	reseau()
{
  int	erreur;
  int	sock_err;
  int	connected;
  char	cmd;

#if defined (WIN32)
  WSADATA WSAData;
  erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
#else
  erreur = 0;
#endif

  SOCKET	sock;
  SOCKADDR_IN	sin;

  while (42)
    {
      sleep(1);
      if (!erreur)
	{
	  sock = socket(AF_INET, SOCK_STREAM, 0);

	  sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	  sin.sin_family = AF_INET;
	  sin.sin_port = htons(port);

	  if (connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
	    {
	      if (connected == 0)
		{
		  printf("Connecté à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
		  connected = 1;
		}
	      cmd = getch();
	      if (cmd == 'q')
		{
		  close(sock);
#if defined (WIN32)
		  WSACleanup();
#endif
		  exit(EXIT_SUCCESS);
		}
	      if (cmd == 'n' || cmd == 'p' || cmd == 's')
		{
		  sock_err = send(sock, &cmd, 1, 0);
		  if (sock_err != SOCKET_ERROR)
		    printf("Caractère envoyé : %c\n", cmd);
		  else
		    printf("Erreur de transmission...\n");
		}
	      else
		printf("Commande non existante...\n");
	    }
	  else
	    {
	      if (connected != 0)
		{
		  connected = 0;
		  printf("Impossible de se connecter\n");
		}
	    }
	  close(sock);
	}
    }
#if defined (WIN32)
  WSACleanup();
#endif
}
