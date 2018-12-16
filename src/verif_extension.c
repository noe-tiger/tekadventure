/*
** verif_extension.c for tekad in /home/viktouille/MUL/tekadventure
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Fri May 26 17:23:37 2017 Victor CHAU
** Last update Fri May 26 17:40:30 2017 Victor CHAU
*/

#include "function.h"

int	verif_extension(char *file_name)
{
  int	i;

  if ((i = my_strlen(file_name, '\0')) <= 4)
    return (1);
  if (file_name[i - 4] == '.' &&
      file_name[i - 3] == 't' &&
      file_name[i - 2] == 'k' &&
      file_name[i - 1] == 'a')
    return (0);
  return (1);
}
