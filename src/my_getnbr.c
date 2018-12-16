/*
** my_getnbr.c for tekad in /home/viktouille/MUL/tekadventure
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Fri May 26 17:22:00 2017 Victor CHAU
** Last update Fri May 26 17:22:24 2017 Victor CHAU
*/

#include <stdlib.h>

int	my_getnbr(char *str)
{
  int	i;
  int	total;

  i = 0;
  total = 0;
  if (str == NULL)
    return (-1);
  if ('0' <= str[i] && str[i] <= '9')
    while ('0' <= str[i] && str[i] <= '9')
      {
	total = (str[i] - 48) + (10 * total);
	++i;
	if (str[i] > '9' || '0' > str[i])
	  return (total);
      }
  return (-1);
}
