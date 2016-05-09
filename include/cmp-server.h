/*
** cmp-server.h for cmp-server.h in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Tue Apr 19 18:33:03 2016 Frédéric GOMEL
** Last update Mon May  9 13:28:30 2016 Frédéric GOMEL
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
typedef struct sockaddr_in SOCKADRR_IN;
typedef struct sockaddr	SOCKADRR;

int	thread_used[10];

#endif

#ifndef CMP_SERVER_H_
#define CMP_SERVER_H_

#include <fmod.h>
#include <dirent.h>

#define RED "\033[31m"
#define REINIT "\033[00m"

typedef struct	s_music
{
  FMOD_SYSTEM	*system;
  FMOD_SOUND	*music;
  FMOD_CHANNEL	*channel;
  FMOD_BOOL	isplaying;
  FMOD_BOOL	pause;
  DIR		*rep;
  char		**playlist;
  int		nbsong;
  struct dirent	*file;
}		t_music;


int	lang;
char	*path_music;
int	port;
char	cmd;
t_music	music;
char	titre[30];
char	time_music[36000000];

/* Fonctions main */

int	main();

/* Fonctions "outils" */

void	sendtitle();
int	equal_char(char*, char*);
int	lenght(char*);
void	quit();

/* Fonctions d'affichage */

void	copyright_display();
void	display_conf();
void	aff(int);

/* Fonctions pour la configuration */

void	get_parameters(int);
void	create_config();
void	set_port();
void	set_language();
void	set_path();
void	set_file();

/* Fonctions pour la lecture de la musique */

void	init_system();
void	load_playlist();
char	**alloc(char **str, int nb);
void	checkerror(FMOD_RESULT result);
int	play();
void	pausemusic(int lecture);
int	next_music(int lecture);
int	prev_music(int lecture);

/* Fonction pour le reseau */

void*	reseau(void*);
void*	gest_client1(void*);
void*	gest_client2(void*);
void*	gest_client3(void*);
void*	gest_client4(void*);
void*	gest_client5(void*);
void*	gest_client6(void*);
void*	gest_client7(void*);
void*	gest_client8(void*);
void*	gest_client9(void*);
void*	gest_client10(void*);

#endif /* !CMP_SERVER_H_ */

#ifndef SOCKET_CLIENT
#define SOCKET_CLIENT

SOCKET	client1;
SOCKET	client2;
SOCKET	client3;
SOCKET	client4;
SOCKET	client5;
SOCKET	client6;
SOCKET	client7;
SOCKET	client8;
SOCKET	client9;
SOCKET	client10;
SOCKADRR_IN	clientaddr1;
SOCKADRR_IN	clientaddr2;
SOCKADRR_IN	clientaddr3;
SOCKADRR_IN	clientaddr4;
SOCKADRR_IN	clientaddr5;
SOCKADRR_IN	clientaddr6;
SOCKADRR_IN	clientaddr7;
SOCKADRR_IN	clientaddr8;
SOCKADRR_IN	clientaddr9;
SOCKADRR_IN	clientaddr10;
socklen_t	clientsizeaddr1;
socklen_t	clientsizeaddr2;
socklen_t	clientsizeaddr3;
socklen_t	clientsizeaddr4;
socklen_t	clientsizeaddr5;
socklen_t	clientsizeaddr6;
socklen_t	clientsizeaddr7;
socklen_t	clientsizeaddr8;
socklen_t	clientsizeaddr9;
socklen_t	clientsizeaddr10;

#endif
