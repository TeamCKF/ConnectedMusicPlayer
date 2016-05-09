
/*
** reseau.c for cmp in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/client
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Thu Apr 21 17:23:29 2016 Frédéric GOMEL
** Last update Mon May  9 03:11:41 2016 Frédéric GOMEL
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

char	get_cmd(SOCKET sock)
{
  char	cmd;
  int	sock_err;

  cmd = getch();
  if (cmd == 'q')
    {
      sock_err = send(sock, &cmd, 1, 0);
      if (sock_err != SOCKET_ERROR)
	{
	  printf("Caractère envoyé : %c\n", cmd);
	  shutdown(sock, SHUT_WR);
	}
      else
	printf("Erreur de transmission...\n");
      return (cmd);
    }
  if (cmd == 'n' || cmd == 'p' || cmd == 's')
    {
      sock_err = send(sock, &cmd, 1, 0);
      if (sock_err != SOCKET_ERROR)
	printf("Caractère envoyé : %c\n", cmd);
      else
	printf("Erreur de transmission...\n");
    }

  return cmd;
}

void	reseau()
{
  int	erreur;
  int	sock_err;
  int	connected;

#if defined (WIN32)
  WSADATA WSAData;
  erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
#else
  erreur = 0;
#endif


  connected = 0;
  char	cmd;

  if (!erreur)
    {
      sock = socket(AF_INET, SOCK_STREAM, 0);

      sin.sin_addr.s_addr = inet_addr(adress);
      //inet_addr("90.127.21.186");
      sin.sin_family = AF_INET;
      sin.sin_port = htons(port);

      if (connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
	{
	  if (connected == 0)
	    {
	      printf("Connecté à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
	      connected = 1;
	    }
	  while (cmd != 'q')
	    {
	      cmd = get_cmd(sock);
	    }
	  shutdown(sock, 2);
	}
      else
	printf("Echec de connexion\n");
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
#if defined (WIN32)
  WSACleanup();
#endif
}
