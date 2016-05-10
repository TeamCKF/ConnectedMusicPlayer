#ifndef CMP-CLIENT_H_INCLUDED
#define CMP-CLIENT_H_INCLUDED

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
typedef struct sockaddr SOCKADDR;

#endif

#include <stdio.h>
#include <stdlib.h>



char            *adress;
int             port;
int             lang;
SOCKET	sock;
SOCKADDR_IN	sinn;

/* Fonction configuration */

void    set_config();
void    set_language();
void    set_port();
void    set_adress();
void    create_file();
void    read_conf(int);

/* Fonction "outils" */

int     equal_char(char*, char*);
int     lenght(char*);

/* Fonction affichage */

void    copyright_display();
void    display_conf();

/* Fonctions de réseau */

void    reseau();
char    get_cmd();

#endif // CMP-CLIENT_H_INCLUDED
