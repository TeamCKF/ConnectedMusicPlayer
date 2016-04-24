/*
** cmp-client.h for cmp in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/client
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Wed Apr 20 16:32:25 2016 Frédéric GOMEL
** Last update Sun Apr 24 18:52:07 2016 Frédéric GOMEL
*/

#ifndef CMP_CLIENT_H_
#define CMP_CLIENT_H_

#define RED "\033[31m"
#define REINIT "\033[00m"

char	*adress;
int	port;
int	lang;

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
