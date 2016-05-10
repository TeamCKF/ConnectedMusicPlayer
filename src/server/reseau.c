/*
** reseau.c for cmp-server in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/server
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Thu Apr 21 15:33:31 2016 Frédéric GOMEL
** Last update Mon May  9 14:12:17 2016 Frédéric GOMEL
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
#include <pthread.h>
#include "cmp-server.h"

void*	reseau(void* data)
{
  int	erreur;
  int	yes;
  int	connected;
  int	sock_err;
  int	i;

#if defined (WIN32)
  WSADATA WSAData;
  erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
#else
  erreur = 0;
#endif

  yes = 1;
  i = 0;
  connected = 0;

  while(i != 10)
    {
      thread_used[i] = 0;
      i++;
    }
  /* Server */
  SOCKET	sock;
  SOCKADDR_IN	sin;
  socklen_t sinsize = sizeof(sin);

  pthread_t	tclient1;
  pthread_t	tclient2;
  pthread_t	tclient3;
  pthread_t	tclient4;
  pthread_t	tclient5;
  pthread_t	tclient6;
  pthread_t	tclient7;
  pthread_t	tclient8;
  pthread_t	tclient9;
  pthread_t	tclient10;

  clientsizeaddr1 = sizeof(clientaddr1);
  clientsizeaddr2 = sizeof(clientaddr2);
  clientsizeaddr3 = sizeof(clientaddr3);
  clientsizeaddr4 = sizeof(clientaddr4);
  clientsizeaddr5 = sizeof(clientaddr5);
  clientsizeaddr6 = sizeof(clientaddr6);
  clientsizeaddr7 = sizeof(clientaddr7);
  clientsizeaddr8 = sizeof(clientaddr8);
  clientsizeaddr9 = sizeof(clientaddr9);
  clientsizeaddr10 = sizeof(clientaddr10);
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
		  while (sock_err = listen(sock, 5) != SOCKET_ERROR)
		    {
		      if (thread_used[0] == 0)
			{
			  thread_used[0] = 1;
			  client1 = accept(sock, (SOCKADDR*)&clientaddr1, &clientsizeaddr1);
			  pthread_create(&tclient1, NULL, &gest_client1, NULL);
			}
		      else if (thread_used[1] == 0)
			{
			  thread_used[1] = 1;
			  client2 = accept(sock, (SOCKADDR*)&clientaddr2, &clientsizeaddr2);
			  pthread_create(&tclient2, NULL, &gest_client2, NULL);
			}
		      else if (thread_used[2] == 0)
			{
			  thread_used[2] = 1;
 			  client3 = accept(sock, (SOCKADDR*)&clientaddr3, &clientsizeaddr3);
			  pthread_create(&tclient3, NULL, &gest_client3, NULL);
			}
		      else if (thread_used[3] == 0)
			{
			  thread_used[3] = 1;
			  client4 = accept(sock, (SOCKADDR*)&clientaddr4, &clientsizeaddr4);
			  pthread_create(&tclient4, NULL, &gest_client4, NULL);
			}
		      else if (thread_used[4] == 0)
			{
			  thread_used[4] = 1;
			  client5 = accept(sock, (SOCKADDR*)&clientaddr5, &clientsizeaddr5);
			  pthread_create(&tclient5, NULL, &gest_client5, NULL);
			}
		      else if (thread_used[5] == 0)
			{
			  thread_used[5] = 1;
			  client6 = accept(sock, (SOCKADDR*)&clientaddr6, &clientsizeaddr6);
			  pthread_create(&tclient6, NULL, &gest_client6, NULL);
			}
		      else if (thread_used[6] == 0)
			{
			  thread_used[6] = 1;
			  client7 = accept(sock, (SOCKADDR*)&clientaddr7, &clientsizeaddr7);
			  pthread_create(&tclient7, NULL, &gest_client7, NULL);
			}
		      else if (thread_used[7] == 0)
			{
			  thread_used[7] = 1;
			  client8 = accept(sock, (SOCKADDR*)&clientaddr8, &clientsizeaddr8);
			  pthread_create(&tclient8, NULL, &gest_client8, NULL);
			}
		      else if (thread_used[8] == 0)
			{
			  thread_used[8] = 1;
			  client9 = accept(sock, (SOCKADDR*)&clientaddr9, &clientsizeaddr9);
			  pthread_create(&tclient9, NULL, &gest_client9, NULL);
			}
		      else if (thread_used[9] == 0)
			{
			  thread_used[9] = 1;
			  client10 = accept(sock, (SOCKADDR*)&clientaddr10, &clientsizeaddr10);
			  pthread_create(&tclient10, NULL, &gest_client10, NULL);
			}
		    }
		}
	      else
		perror("bind");
	    }
	  printf("Fermeture du socket server\n");
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
