/*
** get_next_line.c for get_next_line in /home/mineshot03/Documents/projets/tetriminos
**
** Made by Mineshot03
** Login   <mineshot03@epitech.net>
**
** Started on  Wed Mar  9 11:13:53 2016 Mineshot03
** Last update Sun Apr  3 23:14:39 2016 Mineshot03
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		*gnl(const int fd)
{
  static t_gnl	*rest;
  t_str		str;
  int		test;

  str.i = 0;
  if ((str.buffer = malloc(sizeof(char) * READ_SIZE)) == NULL)
    return (NULL);
  if ((str.str = malloc(sizeof(char) * READ_SIZE)) == NULL)
    return (NULL);
  if (rest == NULL)
    if ((rest = malloc(sizeof(t_gnl))) == NULL)
      return (NULL);
  test = write_in_str(rest, &str, fd);
  if (test == -1)
    return (NULL);
  else if (test == 0)
    if (read_line(&str, fd) == -1)
      return (NULL);
  if ((rest = write_in_rest(rest, &str, fd)) == NULL)
    return (NULL);
  free(str.buffer);
  str.str[str.i] = '\n';
  return (str.str);
}

int	read_line(t_str *str, const int fd)
{
  int	r;

  while ((r = read(fd, str->buffer, READ_SIZE)) > 0)
    {
      str->j = 0;
      while (str->j != READ_SIZE)
	{
	  if (str->buffer[str->j] == '\n' || str->buffer[str->j] == '\0')
	    return (0);
	  str->str[str->i++] = str->buffer[str->j++];
	}
      if (str->buffer[0] == '\n' || str->buffer[0] == '\0')
	return (0);
      str->buffer = vide_buffer(str->buffer);
      if ((str->str = my_realloc(str->str, str->i + READ_SIZE)) == NULL)
	return (-1);
    }
  return (-1);
}

char	*vide_buffer(char *str)
{
  int	i;

  i = 0;
  while (i != READ_SIZE)
    str[i++] = '\0';
  return (str);
}

int	write_in_str(t_gnl *rest, t_str *str, int fd)
{
  str->str = vide_buffer(str->str);
  if (rest->rest == NULL || fd != rest->fd || fd == 0)
    return (0);
  str->i = ( str->j = 0);
  while (rest->rest[str->i] && rest->rest[str->i] != '\n')
    {
      str->str[str->j++] = rest->rest[str->i++];
    }
  if (rest->rest[str->i] == '\n')
    {
      str->j = 0;
      while (rest->rest[str->i])
	str->buffer[str->j++] = rest->rest[str->i++];
      return (1);
    }
  if ((str->str = my_realloc(str->str, rest->irest + READ_SIZE)) == NULL)
    return (-1);
  return (0);
}

t_gnl	*write_in_rest(t_gnl *rest, t_str *str, int fd)
{
  rest->fd = fd;
  if ((rest->rest = malloc(sizeof(char) * READ_SIZE)) == NULL)
    return (NULL);
  rest->irest = 0;
  str->j = 0;
  while (str->buffer[str->j] != '\n' && str->buffer[str->j])
    str->j++;
  str->j++;
  while (str->buffer[str->j])
    {
      rest->rest[rest->irest++] = str->buffer[str->j++];
    }
  return (rest);
}
