/*
** print_maps.c for  in /home/noe/tekadventure
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Sat May 27 04:36:46 2017 Noé
** Last update Sat May 27 07:13:03 2017 Victor CHAU
*/

#include "function.h"
#include "cursor.h"

void	print_maps(t_map *map, char *room, sfRenderWindow *window)
{
  int	i;

  i = 0;
  while (map[i].name && room)
    {
      if (my_strcmp(map[i].name, room) == 0 && map[i].sprite)
	{
	  sfRenderWindow_drawSprite(window, map[i].sprite, NULL);
	  break ;
	}
      i++;
    }
}
