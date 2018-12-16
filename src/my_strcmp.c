/*
** my_strcmp.c for tekadventure in /home/tahery_b/rendu/tekadventure/src
** 
** Made by Alexandre Tahery
** Login   <tahery_b@epitech.net>
** 
** Started on  Sat May 27 04:39:29 2017 Alexandre Tahery
** Last update Sat May 27 11:20:47 2017 Alexandre Tahery
*/

#include "function.h"

int		my_strcmp(char *str1, char *str2)
{
  int		count;

  count = 0;
  if (my_strlen(str1, '\0') != my_strlen(str2, '\0'))
    return (-1);
  while (str1[count] != '\0')
    {
      if (str1[count] != str2[count])
	return (-1);
      count += 1;
    }
  return (0);
}
