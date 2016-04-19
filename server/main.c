/*
** main.c for main.c in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/server
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Tue Apr 19 15:37:59 2016 Frédéric GOMEL
** Last update Tue Apr 19 16:26:13 2016 Frédéric GOMEL
*/

#include <fmod.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>

char *path_music;

void	create_config()
{
  int	nombre;

  printf("Welcome to the assistance of configuration of ConnectedMusiquePlayer - Server.\n");
  printf("Choose your language : 1 - Fr, 2 - En\n - :");
  scanf("%i", &nombre);
  while (nombre <= 0 && nombre >= 3)
    {
      printf("Wrong. You didn't choose a correct language : 1 - Fr, 2 - En\n");
      scanf("- %i", &nombre);
    }
  if (nombre == 1)
    {
      printf("Cool, un français. Bienvenue.\n");
      printf("Veuillez indiquer le chemin vers le répertoire contenant la musique.\n");
      scanf("%s", &path_music);
      printf("%s\n");
    }
  else
    {
      printf("You choose the international language ! Great i didn't do this work for nothing ;)\n");
      printf("Write the path to the directory where the music is.\n");
      scanf("%s", &path_music);
      printf("%s\n");
    }
  //open("config.cfg", O_CREAT | O_WRONLY, 0660);
}

int	main()
{
  if (open("config.cfg", O_RDONLY) == -1)
    create_config();
}
