/*
** put.c for  in /home/noe/tekadventure
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Sat May 27 11:37:47 2017 Noé
** Last update Sat May 27 11:43:19 2017 Noé
*/

#include <unistd.h>
#include "function.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str, 0));
}
