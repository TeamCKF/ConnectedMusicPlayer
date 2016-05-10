
/*
** reseau.c for cmp in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/client
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Thu Apr 21 17:23:29 2016 Frédéric GOMEL
** Last update Tue May 10 14:40:26 2016 guillaume
*/


//#include "wincompat.h"
#include "game.h"
#include "cmp-client.h"

char	get_cmd(SOCKET sock)
{
    int	sock_err;

    getImput();
    if (cmd == 'q')
    {
        sock_err = send(sock, &cmd, 1, 0);
        if (sock_err != SOCKET_ERROR)
        {
            printf("Caractere envoye : %c\n", cmd);
            shutdown(sock, SHUT_WR);
        }
        else
            printf("Erreur de transmission...\n");
        return (cmd);
    }
    if (cmd == 'n' || cmd == 'p' || cmd == 'r')
    {
        sock_err = send(sock, &cmd, 1, 0);
        if (sock_err != SOCKET_ERROR)
            printf("Caractere envoye : %c\n", cmd);
        else
            printf("Erreur de transmission...\n");
    }
    aff();
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

      sinn.sin_addr.s_addr = inet_addr(adress);
      //inet_addr("90.127.21.186");
      sinn.sin_family = AF_INET;
      sinn.sin_port = htons(port);

      if (connect(sock, (SOCKADDR*)&sinn, sizeof(sinn)) != SOCKET_ERROR)
	{
	  if (connected == 0)
	    {
	      printf("Connecte a %s sur le port %d\n", inet_ntoa(sinn.sin_addr), htons(sinn.sin_port));
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
