/*
** functions.c for  in /home/zemmou_b/rendu/PSU_2015_minishell2
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Sun Dec 20 23:28:25 2015 Billal Zemmouri
** Last update Sun Dec 20 23:40:00 2015 Billal Zemmouri
*/

#include "./include/minishell2.h"
#include <unistd.h>

int	my_cd(char **tabbuff, char **tab, t_env *list)
{
  char  *pwd;

  pwd = my_getenv(list,"PWD");
  if (tabbuff[0][2] == '.' && tabbuff[0][3] == '.')
    {
      my_cdprev(tabbuff, list, pwd);
    }
  else if (tabbuff[1] == NULL)
    return (0);
  else
    my_cdnext(tabbuff, list, pwd);
}

int	my_cdprev(char **tabbuff, t_env *list , char *pwd)
{
  int   i;
  int   j;
  
  
  i = my_strlen(pwd);
  while (my_strncmp(list->env,"PWD",2) != 0)
    list = list->next;
  j = my_strlen(list->env);
  while (pwd[i] != '/'&& i > 5)
    {
      list->env[j] = 0;
      pwd[i] = 0;
      i -= 1;
      j -= 1;
    }
    list->env[j] = 0;
    pwd[i] = 0;
    chdir(pwd);
}

int	my_cdnext(char **tabbuff, t_env *list, char *pwd)
{
  int   i;
  int   j;
  int   a;
  
  i = my_strlen(pwd);
  while (my_strncmp(list->env,"PWD",2) != 0)
    list = list->next;
  j = my_strlen(list->env);
  pwd = my_realloc(pwd,(my_strlen(tabbuff[1]) + 2));
  if (tabbuff[1][0] != '/')
    {
      pwd[i] = '/';
      list->env[j] = '/';
      j = j + 1;
      i = i + 1;
    }
  a = 0;
  while (tabbuff[1][a] != 0)
    {
      list->env[j] = tabbuff[1][a];
      pwd[i] = tabbuff[1][a];
      i += 1;
      a += 1;
      j += 1;
    }
  list->env[j] = 0;
  pwd[i] = 0;
  if (chdir(pwd) == -1)
    my_putstr("No such file or directory\n");
}

int	my_env(char **tabbuff, char **tab, t_env *list)
{
  my_show_list(list);
  return (0);
}

int	remplace_env(t_env **list, char *tabbuff)
{
  int	i;

  i = 0;
  (*list)->env = malloc(sizeof(char) * my_strlen(tabbuff));
  while (tabbuff[i] != 0)
    {
      (*list)->env[i] = tabbuff[i];
      i = i + 1;
    }
  return (0);
}

int my_setenv(char **tabbuff, char **tab, t_env *list)
{
  int	i;
  
  i = 0;
  while (tabbuff[1][i] != '=' && tabbuff[1][i] != 0)
    i = i + 1;
  while (list != NULL)
    {
      if (my_strncmp(list->env, tabbuff[1], i) != -1)
	{
	  remplace_env(&list, tabbuff[1]);
	  my_putstr(list->env);
	  return (0);
	}
      if (list->next == NULL)
	{
	  my_put_in_list(&list,tabbuff[1]);
	  return (0);
	}
      list = list->next;
    }
}
