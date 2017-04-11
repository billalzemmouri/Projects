/*
** functions_p.c for  in /home/zemmou_b/rendu/PSU_2015_minishell2
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Sun Dec 20 23:28:40 2015 Billal Zemmouri
** Last update Sun Dec 20 23:28:50 2015 Billal Zemmouri
*/

#include <unistd.h>
#include "./include/minishell2.h"

int	my_put_in_list(t_env **list, char *str)
{
  t_env *elem;
  
  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->env = str;
  elem->next = *list;
  *list = elem;
  
  return (0);
}

void	my_show_list(t_env *list)
{
  t_env	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->env);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

t_env	*set_env(char **env)
{
  t_env	*list;
  int	i;

  i = 0;
  list = malloc(sizeof(list));
  list = NULL;
  while (env[i] != NULL)
    {
      my_put_in_list(&list, env[i]);
      i = i + 1;
    }
  return (list);
}

char	*set_path(t_env *list)
{
  char	*path;
  int	i;
  int	j;

  i = 5;
  j = 0;
  while (list->env[0] != 'P' || list->env[1] != 'A'
         || list->env[2] != 'T' || list->env[3] != 'H')
    {
      list = list->next;
    }
  path = malloc(sizeof(char) *(my_strlen(list->env) - 4));
  while (list->env[i] != 0)
    {
      path[j] = list->env[i];
      i = i + 1;
      j = j + 1;
    }
  path[j] = 0;
  return (path);
}

char	*check_path(char **env, char *buff)
{
char	*path;
int	i;

 i = 0;
 while (env[i] != NULL)
   {
     env[i] = my_realloc(env[i], my_strlen(buff));
     env[i] = my_strcat(env[i], buff);
     i = i + 1;
   }
 i = 0;
 while (env[i] != NULL)
   {
     if (access(env[i], X_OK) == 0)
       {
	 return (env[i]);
       }
     i = i + 1;
   }
 return (NULL);
}
