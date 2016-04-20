/*
** my_realloc.c for my_realloc in /home/guillaume/Documents/Projets/S2/PSU_2015_minishell2
**
** Made by guillaume
** Login   <guillaume@epitech.net>
**
** Started on  Mon Mar 21 15:11:30 2016 guillaume
** Last update Mon Mar 21 16:14:35 2016 guillaume
*/

#include <stdlib.h>
#include "get_next_line.h"

char	*my_realloc(char *str, int size)
{
  char	*buffer;
  int	i;

  i = 0;
  if ((buffer = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      buffer[i] = str[i];
      i++;
    }
  free (str);
  return (buffer);
}
