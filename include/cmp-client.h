/*
** cmp-client.h for cmp in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/client
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Wed Apr 20 16:32:25 2016 Frédéric GOMEL
** Last update Mon May  9 14:05:19 2016 Frédéric GOMEL
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

#ifndef CMP_CLIENT_H_
#define CMP_CLIENT_H_

#define RED "\033[31m"
#define REINIT "\033[00m"

char	*adress;
int	port;
int	lang;
SOCKET	sock;
// SOCKADDR_IN sin;

int	main();

/* Fonction configuration */

void	set_config();
void	set_language();
void	set_port();
void	set_adress();
void	create_file();
void	read_conf(int);

/* Fonction "outils" */

int	equal_char(char*, char*);
int	lenght(char*);

/* Fonction affichage */

void	copyright_display();
void	display_conf();

/* Fonctions de réseau */

void	reseau();
char	get_cmd();

#endif /* !CMP_CLIENT_H_ */
