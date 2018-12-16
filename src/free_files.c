/*
** free_files.c for tekad in /home/viktouille/MUL/tekadventure
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Fri May 26 17:28:23 2017 Victor CHAU
** Last update Fri May 26 17:38:26 2017 Victor CHAU
*/

#include <stdlib.h>
#include "file_prop.h"

void		free_files(t_file_prop *files)
{
  t_file_prop	*tmp_file;
  t_room_prop	*tmp_room1;
  t_room_prop	*tmp_room2;
  int		i;

  i = 0;
  while (files != NULL)
    {
      tmp_file = files;
      tmp_room1 = files->room;
      free(files->wallpaper);
      while (tmp_room1 != NULL)
	{
	  tmp_room2 = tmp_room1;
	  free(tmp_room1->wallpaper);
	  tmp_room1 = tmp_room1->next;
	  free(tmp_room2);
	}
      while (files->collision_map[i] != NULL)
	free(files->collision_map[i++]);
      free(files->collision_map);
      files = files->next;
      free(tmp_file);
    }
}
