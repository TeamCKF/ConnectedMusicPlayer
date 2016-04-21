/*
** cmp-server.h for cmp-server.h in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Tue Apr 19 18:33:03 2016 Frédéric GOMEL
** Last update Thu Apr 21 15:57:21 2016 Frédéric GOMEL
*/

#ifndef CMP_SERVER_H_
#define CMP_SERVER_H_

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
typedef struct sockaddr_in SOCKADRR_IN;
typedef struct sockaddr	SOCKADRR;

#endif

#include <fmod.h>
#include <dirent.h>

#define RED "\033[31m"
#define REINIT "\033[00m"

int	lang;
char	*path_music;
int	port;

typedef struct	s_music
{
  FMOD_SYSTEM	*system;
  FMOD_SOUND	*music;
  FMOD_CHANNEL	*channel;
  FMOD_BOOL	isplaying;
  DIR		*rep;
  struct dirent	*file;
}		t_music;

t_music	music;

int	main();

/* Fonctions "outils" */

int	equal_char(char*, char*);
int	lenght(char*);

/* Fonctions d'affichage */

void	copyright_display();
void	display_conf();

/* Fonctions pour la configuration */

void	get_parameters(int);
void	create_config();
void	set_port();
void	set_language();
void	set_path();
void	set_file();

/* Fonctions pour la lecture de la musique */

void	init_system();
void	checkerror(FMOD_RESULT result);
int	play();

#endif /* !CMP_SERVER_H_ */
