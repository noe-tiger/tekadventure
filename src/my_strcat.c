/*
** my_strcat.c for tekad in /home/viktouille/MUL/tekadventure
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Fri May 26 17:21:03 2017 Victor CHAU
** Last update Fri May 26 17:44:35 2017 Victor CHAU
*/

#include "function.h"
#include <stdlib.h>

char	*my_strcat(char *str1, char *str2)
{
  char	*str;
  int	tot;
  int	i;
  int	j;

  i = 0;
  j = 0;
  tot = my_strlen(str1, '\0') + my_strlen(str2, '\0');
  if ((str = malloc(sizeof(char) * (tot + 1))) == NULL)
    return (NULL);
  while (str1[i++] != '\0')
    str[j++] = str1[i - 1];
  i = 0;
  while (str2[i++] != '\0')
    str[j++] = str2[i - 1];
  str[j] = '\0';
  return (str);
}

char	*my_strcat_free(char *str1, char *str2)
{
  char	*str;
  int	tot;
  int	i;
  int	j;

  i = 0;
  j = 0;
  tot = my_strlen(str1, '\0') + my_strlen(str2, '\0');
  if ((str = malloc(sizeof(char) * (tot + 1))) == NULL)
    return (NULL);
  while (str1[i++] != '\0')
    str[j++] = str1[i - 1];
  i = 0;
  while (str2[i++] != '\0')
    str[j++] = str2[i - 1];
  str[j] = '\0';
  free(str1);
  return (str);
}
