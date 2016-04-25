/*
** load_playlist.c for  in /home/guillaume/ConnectedMusiquePlayer/server
**
** Made by guillaume
** Login   <guillaume@epitech.net>
**
** Started on  Thu Apr 21 16:35:31 2016 guillaume
** Last update Mon Apr 25 11:54:50 2016 guillaume
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include "cmp-server.h"

void	load_playlist()
{
  int	c = 1;
  int	i = 0;
  int	ok = 0;
  char	*s;

  music.nbsong = 0;
  while ((music.file = readdir(music.rep)) != NULL)
    {
      s = music.file->d_name;
      while (s[i])
	{
	  if ((s[i] == 'm' && s[i+1] == 'p' && s[i+2] == '3' && s[i+3] == '\0') ||
	      (s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'g' && s[i+3] == '\0') ||
	      (s[i] == 'w' && s[i+1] == 'a' && s[i+2] == 'v' && s[i+3] == '\0'))
	    ok = 1;
	  i++;
	}
      if (ok == 1)
	{
	  music.playlist = alloc(music.playlist, c);
	  music.playlist[c-1] = music.file->d_name;
	  c++;
	  music.nbsong++;
	}
      i = 0;
      ok = 0;
    }
}

char	**alloc(char **str, int nb)
{
  if (nb == 1)
    {
      if ((str = malloc(sizeof(char*) * nb)) == NULL)
	{
	  printf("Memory error!\n");
	  quit();
	}
    }
  else
    {
      if ((str = realloc(str, sizeof(char*) * nb)) == NULL)
	{
	  printf("Memory error!\n");
	  quit();
	}
    }
  return (str);
}
