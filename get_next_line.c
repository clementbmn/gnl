/*
** get_next_line.c for get_next_line in /home/clementbmn/Documents/Epitech/Elementary_Programming_in_C/CPE_2016_getnextline
**
** Made by Clement
** Login   <clement.baumann@epitech.eu@epitech.net>
**
** Started on  Sun Jan  1 02:01:22 2017 Clement
** Last update Thu Jan 12 18:38:21 2017 Clement
*/

# include "get_next_line.h"

char	*my_realloc(char *str)
{
  int	len;
  char	*new;
  int	i;

  i = 0;
  len = 0;
  while (str[len])
    len = len + 1;
  if ((new = malloc(len + 2)) == 0)
    return (0);
  new[0] = 0;
  while (str[i])
    {
      new[i] = str[i];
      i = i + 1;
    }
  new[i] = 0;
  free(str);
  return (new);
}

void	add_c(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  str[i] = c;
  str[i + 1] = 0;
}

char	*update_buffer(char buffer[], char *str, int o)
{
  int	i;

  i = 0;
  if (o)
    add_c(str, buffer[0]);
  while (buffer[i + 1] != '\0')
    {
      buffer[i] = buffer[i + 1];
      i = i + 1;
    }
  buffer[i] = '\0';
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE + 1] = "\0";
  char		*str;
  int		lus;

  if (READ_SIZE > 2000000000 || READ_SIZE <= 0 || !(str = malloc(2)))
    return (0);
  str[0] = 0;
  while (buffer[0] != '\n')
    {
      if (buffer[0] == 0)
	{
	  if ((lus = read(fd, buffer, READ_SIZE)) < 1)
	    return ((str[0]) ? str : 0);
	  buffer[lus] = '\0';
	}
      if ((str = my_realloc(str)) == 0)
	return (0);
      if (buffer[0] == '\n')
	return (update_buffer(buffer, str, 0));
      update_buffer(buffer, str, 1);
    }
  update_buffer(buffer, str, 0);
  return (str);
}
