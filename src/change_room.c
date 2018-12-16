/*
** change_room.c for change_room in /home/samuel/MUL/tekadventure
** 
** Made by samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Sat May 27 03:21:00 2017 samuel
** Last update Sun May 28 20:28:27 2017 Victor CHAU
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "file_prop.h"
#include "function.h"

char		*check_room(t_file_prop *prop, char *current_room,
			    sfVector2i pos)
{
  t_room_prop	*tmp;

  while (prop != NULL)
    {
      tmp = prop->room;
      if (my_strncmp(prop->wallpaper, current_room,
		     my_strlen(current_room, '\n')) == 0)
	{
	  while (tmp != NULL)
	    {
	      if (pos.x >= tmp->begin.x && pos.x <= tmp->end.x &&
		  pos.y >= tmp->begin.y && pos.y <= tmp->end.y)
		return (tmp->wallpaper);
	      tmp = tmp->next;
	    }
	  return (NULL);
	}
      prop = prop->next;
    }
  return (NULL);
}

char	*change_room(sfVector2i pos, t_file_prop *prop, char *current_room)
{
  char	*new_room;

  if (!current_room)
    return (NULL);
  if ((new_room = check_room(prop, current_room, pos)) != NULL)
    return (new_room);
  else
    return (NULL);
}
