/*
** get_next_line.h for get_next_line in /home/mineshot03/Documents/projets/tetriminos
**
** Made by Mineshot03
** Login   <mineshot03@epitech.net>
**
** Started on  Thu Mar 10 14:22:44 2016 Mineshot03
** Last update Thu Mar 24 16:07:18 2016 guillaume
*/

#ifndef READ_SIZE
# define READ_SIZE (10)
#endif /* !READ_SIZE */

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

typedef struct  s_gnl
{
  int		fd;
  char          *rest;
  int           irest;
  struct s_gnl  *next;
}               t_gnl;

typedef struct  s_str
{
  char          *str;
  char          *buffer;
  int           i;
  int           j;
}               t_str;

char		*gnl(const int fd);
int		read_line(t_str *str, const int fd);
char		*vide_buffer(char *str);
t_gnl		*write_in_rest(t_gnl *rest, t_str *str, int fd);
char		*my_realloc(char *str, int size);
int		write_in_str(t_gnl *rest, t_str *str, int fd);

#endif /* !GET_NEXT_LINE_H_ */
