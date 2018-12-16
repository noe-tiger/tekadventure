/*
** my_dupline.c for tekad in /home/viktouille/MUL/tekadventure
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Fri May 26 17:25:18 2017 Victor CHAU
** Last update Sat May 27 07:02:04 2017 Victor CHAU
*/

#include "function.h"
#include <stdlib.h>

char	*my_dupline(char *str, int end)
{
  int	i;
  char	*dup;

  i = 0;
  if ((dup = malloc(sizeof(char) * (my_strlen(str, '\0') + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0' && i < end)
    {
      dup[i] = str[i];
      ++i;
    }
  dup[i] = '\0';
  return (dup);
}
