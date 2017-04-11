/*
** main.c for  in /home/zemmou_b/rendu/CPE_2015_get_next_line
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Tue Nov 24 14:04:07 2015 Billal Zemmouri
** Last update Sun Nov 29 23:25:53 2015 Billal Zemmouri
*/
#include "./include/get_next_line.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      i = i + 1;
    }
  return (i);
}

int	my_sizem(char *str, int a)
{
  int	i;

  if (a == BUFF_SIZE)
    return (0);
  i = a;
  while (str[i] != '\n' && str[i] != '\0' && i != BUFF_SIZE)
    i = i + 1;
  return (i);
}

char	*my_realloc(char *old, int size)
{
  char	*newstr;
  int	i;

  i = 0;
  if ((newstr = malloc(sizeof(char) * (my_strlen(old) + size + 1))) == NULL)
    return (NULL);
  while (old[i] != '\0')
    {
      newstr[i] = old[i];
      i = i + 1;
    }
  newstr[i] = '\0';
  free(old);
  return (newstr);
}

char	*my_resetbuff(char *buff)
{
  int	i;

  i = 0;
  if (my_strlen(buff) == 0)
    return (NULL);
  while (buff[i] != '\0')
    {
      buff[i] = '\0';
      i = i + 1;
    }
  return (buff);
}

char	*get_next_line(const int fd)
{
  static char	buff[BUFF_SIZE];
  static int	a;
  static int resread;
  char	*str;
  int	i;

  i = 0;
  if (buff[0] == '\0')
    resread =read(fd, buff, BUFF_SIZE);
  if (resread == 0 || buff[a] == '\0')
    return (NULL);
  if ((str = malloc(sizeof(char) * (my_sizem(buff, a) + 1))) == NULL)
    return (NULL);
  if (a > 0 || buff[0] == '\n')
    a = a + 1;
  while (my_sizem(buff, a) == BUFF_SIZE || a != my_sizem(buff , a))
    {
      while (buff[a] != '\0' && buff[a] != '\n' && a <= BUFF_SIZE)
	str[i++] = buff[a++];
      str[i] = '\0';
      if (a == BUFF_SIZE && buff[a] != '\n')
	{
	  a = 0;
	  resread = read(fd, my_resetbuff(buff), BUFF_SIZE);
	  str = my_realloc(str, my_sizem(buff, a));
	}
    }
  return (str);
}
