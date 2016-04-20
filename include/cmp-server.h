/*
** cmp-server.h for cmp-server.h in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Tue Apr 19 18:33:03 2016 Frédéric GOMEL
** Last update Wed Apr 20 17:00:06 2016 guillaume
*/

#ifndef CMP_SERVER_H_
#define CMP_SERVER_H_

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
void	play();

#endif /* !CMP_SERVER_H_ */
