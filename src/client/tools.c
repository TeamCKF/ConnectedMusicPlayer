/*
** tools.c for cmp in /home/gomel_f/Documents/LecteurBotMusique/ConnectedMusiquePlayer/server
**
** Made by Frédéric GOMEL
** Login   <gomel_f@epitech.net>
**
** Started on  Wed Apr 20 15:29:31 2016 Frédéric GOMEL
** Last update Sun Apr 24 18:40:56 2016 Frédéric GOMEL
*/

#include "cmp-client.h"

int	equal_char(char *src, char *comp)
{
  int	i;

  i = 0;
  while (src[i] && comp[i])
    {
      if (src[i] == comp[i])
	i++;
      else
	return (0);
    }
  if (src[i] == '\0' && comp[i] == '\0')
    return (1);
  return (0);
}

int	lenght(char *str)
{
  int	i;
  int	j;

  i = (j = 0);
  while (str[i] != '=' && str[i] != '\0')
    i++;
  if (str[i] == '=')
    i++;
  while (str[i])
    {
      i++;
      j++;
    }
  return j;
}
