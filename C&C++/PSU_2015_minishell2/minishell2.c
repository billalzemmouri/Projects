/*
** minishell2.c for  in /home/zemmou_b/rendu/PSU_2015_minishell2
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Sun Dec 20 23:28:00 2015 Billal Zemmouri
** Last update Sun Dec 20 23:38:40 2015 Billal Zemmouri
*/

#include <unistd.h>
#include "./include/minishell2.h"

char **add_slash(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      tab[i] = my_realloc(tab[i], 2);
      tab[i][my_strlen(tab[i])] = '/';
      tab[i][(my_strlen(tab[i]) + 1)] = 0;
      i = i + 1;
    }
  return (tab);
}

int my_execute(char **tabbuff, char **tab, t_env *env)
{
  char	*path;
  pid_t	pid;
  
  if (tabbuff[0] != NULL &&(path = check_path(tab, tabbuff[0])) == NULL)
    {
      my_putstr("Error: unknown command\n");
      return (0);
    }
  pid = fork();
  if(pid == 0)
    {
      execve(path,tabbuff, (char **)(env));
    }
  else
    wait(NULL);
}

char *my_getenv(t_env *list, char *str)
{
  int	i;
  int	y;
  int	a;
  char	*elem;
  
  i = 0;
  a = 0;
  while (list->env != NULL)
    {
      y = 0;
      
      while (list->env[y] == str[y])
	{   
	  y = y + 1;
	  if (list->env[y] == '=')
	    {
	      elem = malloc(sizeof(char) * my_strlen(list->env));
	      y += 1;
	      while (list->env[y] != 0)
		{
		  elem[a] = list->env[y];
		  a += 1;
		  y += 1;
		}
	      elem[a] = 0;
	    return (elem);
	    }
	}
      list = list->next;
    }
  return (NULL);
}

int	builtin(char **tabbuff, char **built, char **tab, t_env *env)
{ 
  int	i;

  i = 0;
  while (built[i] != NULL)
    {
      if (my_strcmp(tabbuff[0],built[i]) == 0)
	{
	  if (i == 5)
	    return (-1);
	  else
	    {
	      my_sh_functions(tabbuff, tab, env, i);
	      return (0);
	    }
	}
      i += 1;
    }
  my_execute(tabbuff, tab, env);
  return (0);
}

int	my_sh_functions(char **tabbuff, char **tab, t_env *env, int i)
{
  int (*builtin[8])(char **,char **,t_env *);
  builtin[0] = &my_cd;
  builtin[1] = &my_cd;
  builtin[2] = &my_env;
  builtin[3] = &my_setenv;
  (*builtin[i])(tabbuff, tab, env);
}

int	main(int ac, char **av, char **env)
{
  char buff[4096];
  char **tab;
  char **tabbuff;
  t_env	*list;
  static  char  *built[7] = {"cd",
                             "cd..",
			     "env",
                             "setenv",
                             "ensetenv",
                             "exit"};
  
  while (42)
    {
      my_putstr(">");
      list = set_env(env);
      tab = add_slash(my_str_to_wordtab(set_path(list)));
      my_resetbuff(buff);
      if (read(0, buff, 4096) > 1)
	{
	  tabbuff = my_str_to_wordtab(buff);
	  if (builtin(tabbuff, built, tab, list) == -1)
	    return (0);
	}
    }
}
