/*
** gest_client.c for cmp-server in /home/gomel_f/Documents/LecteurBotMusique/Multiclient/ConnectedMusicPlayer
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Sun May  8 14:48:47 2016 Frédéric GOMEL
** Last update Mon May  9 13:36:15 2016 Frédéric GOMEL
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

#include "cmp-server.h"

void*	gest_client1(void* data)
{
  sendtitle();
  while (recv(client1, &cmd, 1, 0) != SOCKET_ERROR && cmd != 'q');
  close(client1);
  thread_used[0] = 0;
}

void*	gest_client2(void* data)
{
  sendtitle();
  while (recv(client2, &cmd, 1, 0) != SOCKET_ERROR && cmd != 'q');
  close(client2);
  thread_used[1] = 0;
}

void*	gest_client3(void* data)
{
  sendtitle();
  while (recv(client3, &cmd, 1, 0) != SOCKET_ERROR && cmd != 'q');
  close(client3);
  thread_used[2] = 0;
}

void*	gest_client4(void* data)
{
  sendtitle();
  while (recv(client4, &cmd, 1, 0) != SOCKET_ERROR && cmd != 'q');
  close(client4);
  thread_used[3] = 0;
}

void*	gest_client5(void* data)
{
  sendtitle();
  while (recv(client5, &cmd, 1, 0) != SOCKET_ERROR && cmd != 'q');
  close(client5);
  thread_used[4] = 0;
}

void*	gest_client6(void* data)
{
  sendtitle();
  while (recv(client6, &cmd, 1, 0) != SOCKET_ERROR && cmd != 'q');
  close(client6);
  thread_used[5] = 0;
}

void*	gest_client7(void* data)
{
  sendtitle();
  while (recv(client7, &cmd, 1, 0) != SOCKET_ERROR && cmd != 'q');
  close(client7);
  thread_used[6] = 0;
}

void*	gest_client8(void* data)
{
  sendtitle();
  while (recv(client8, &cmd, 1, 0) != SOCKET_ERROR && cmd != 'q');
  close(client8);
  thread_used[7] = 0;
}

void*	gest_client9(void* data)
{
  sendtitle();
  while (recv(client9, &cmd, 1, 0) != SOCKET_ERROR && cmd != 'q');
  close(client9);
  thread_used[8] = 0;
}

void*	gest_client10(void* data)
{
  sendtitle();
  while (recv(client10, &cmd, 1, 0) != SOCKET_ERROR && cmd != 'q');
  close(client10);
  thread_used[9] = 0;
}
