/*
** my_str_to_wordtab.c for  in /home/zemmou_b/rendu/PSU_2015_minishell1
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Sun Dec  6 23:23:33 2015 Billal Zemmouri
** Last update Sun Dec  6 23:29:00 2015 Billal Zemmouri
*/
#include <stdlib.h>

int	my_worden(char *str)
{
  int	i;
  int	j;
  int	nb;
  
  nb = 0;
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] != ':' && str[i] != ' ' && str[i] != '\n')
        nb = nb + 1;
      i = i + 1;
    }
  return (nb);
}

int	strlen2(int c, char *str)
{
  int	b;
  
  b = 0;
  while (str[c] != 0 && str[c] != ':' && str[c] != ' ' && str[c] != '\n')
    {
      b = b + 1;
      c = c + 1;
    }
  return (b);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	a;
  int	b;

  i = 0;
  j = -1;
  tab = malloc(sizeof(char *) * my_worden(str) + 1);
  while (str[i] != 0)
    {
      a = 0;
      b = strlen2(i, str);
      if (b != 0)
	{
	  j = j + 1;
	  tab[j] = malloc(b);
	  tab[j][b] = '\0';
	}
      while (str[i] != ':' && str[i] != ' ' && str[i] != 0 && str[i] != '\n')
	{
	  tab[j][a] = str[i];
	  i = i + 1;
	  a = a + 1;
	}
      if (str[i] == 0)
	i = i - 1;
      i = i + 1;
    }
  tab[j + 1] = NULL;
  return (tab);
}
