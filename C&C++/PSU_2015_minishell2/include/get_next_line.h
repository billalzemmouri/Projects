/*
** get_next_line.h for  in /home/zemmou_b/rendu/CPE_2015_get_next_line
** 
** Made by Billal Zemmouri
** Login   <zemmou_b@epitech.net>
** 
** Started on  Sat Nov 28 17:30:51 2015 Billal Zemmouri
** Last update Sun Dec  6 23:04:14 2015 Billal Zemmouri
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

# define BUFF_SIZE (4096)

int	my_sizem(char *str, int a);
char	*my_realloc(char *old, int size);
char	*my_resetbuff(char *buff);
char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
