/*
** minishell1.h for  in /home/zemmou_b/rendu/PSU_2015_minishell1/include
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Mon Nov 30 16:37:00 2015 Billal Zemmouri
** Last update Fri Dec 18 16:11:01 2015 Billal Zemmouri
*/

#ifndef MINISHELL1_H_
# define MINISHELL1_H_

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

typedef struct s_list
{
  char *env;

  struct s_list *next;
}t_env;

int	my_put_in_list(t_env **list, char *str);
void	my_show_list(t_env *list);
t_env	*set_env(char **env);
char	*set_path(t_env *list);
int	my_sizem(char *str, int a);
char	*my_realloc(char *old, int size);
char	*my_resetbuff(char *buff);
char	*get_next_line(const int fd);
char	*check_path(char **env, char *buff);
char	**add_slash(char **tab);
int	my_worden(char *str);
int	strlen2(int c, char *str);
char	**my_str_to_wordtab(char *str);
char	*my_getenv(t_env *list, char *str);
int	my_cd(char **tabbuff, char **tab, t_env *list);
int	my_cdnext(char **tabbuff, t_env *list, char *pwd);
int	my_cdprev(char **tabbuff, t_env *list , char *pwd);
int	my_env(char **tabbuff, char **tab, t_env *list);
int	my_setenv(char **tabbuff, char **tab, t_env *list);

#endif /* !MINISHELL_H_ */
