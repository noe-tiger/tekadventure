/*
** my_put_in_list.c for tekad in /home/viktouille/MUL/tekadventure
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Fri May 26 17:26:04 2017 Victor CHAU
** Last update Fri May 26 22:40:44 2017 Victor CHAU
*/

#include <SFML/Graphics.h>
#include "file_prop.h"
#include <stdlib.h>

t_file_prop	*my_put_files_in_list(t_file_prop *files, char *file_name)
{
  t_file_prop	*new;
  t_file_prop	*tmp;

  if (files == NULL)
    {
      if ((files = malloc(sizeof(t_file_prop))) == NULL)
	return (NULL);
      files->room = NULL;
      files->next = NULL;
      files->file_name = file_name;
    }
  else
    {
      tmp = files;
      if ((new = malloc(sizeof(t_file_prop))) == NULL)
	return (NULL);
      new->room = NULL;
      new->next = NULL;
      new->file_name = file_name;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
  return (files);
}

t_file_prop	*my_put_rooms_in_files_list(t_file_prop *files,
					    char *wallpaper,
					    sfVector2i begin, sfVector2i end)
{
  t_room_prop	*new;
  t_room_prop	*tmp;

  tmp = files->room;
  if ((new = malloc(sizeof(t_room_prop))) == NULL || wallpaper == NULL ||
      begin.x == -1 || begin.y == -1 || end.x == -1 || end.y == -1)
    return (NULL);
  new->wallpaper = wallpaper;
  new->begin = begin;
  new->end = end;
  new->next = NULL;
  if (tmp == NULL)
    files->room = new;
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
  return (files);
}
