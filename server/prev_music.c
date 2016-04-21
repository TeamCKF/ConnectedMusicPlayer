/*
** prev_music.c for cmp in /home/guillaume/ConnectedMusiquePlayer/server
**
** Made by guillaume
** Login   <guillaume@epitech.net>
**
** Started on  Thu Apr 21 15:54:36 2016 guillaume
** Last update Thu Apr 21 16:53:23 2016 guillaume
*/

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <fmod.h>
#include "wincompat.h"
#include "cmp-server.h"

/*long int	*tab_file(long int *tab)
{
  int	cursor = 0;

  rewinddir(music.rep);
  if ((tab = malloc(sizeof(long int) * 1)) == NULL)
    {
      printf("Memory Error!\n");
      exit(1);
    }
  while ((music.file = readdir(music.rep)) != NULL)
    {
      printf("%d\n", tab[cursor] = telldir(music.rep));
      cursor++;
      tab = realloc(tab, cursor + 1 * sizeof(long int));
    }
  while (cursor != -1)
    {
      printf("%ld\n", tab[cursor--]);
      }
}
*/
void	prev_music()
{
  //long int	*tab;

  //tab_file(tab);
}
