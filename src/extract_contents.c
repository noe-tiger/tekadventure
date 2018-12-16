/*
** extract_contents.c for tekad in /home/viktouille/MUL/tekadventure
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Fri May 26 17:16:34 2017 Victor CHAU
** Last update Sat May 27 09:05:39 2017 Victor CHAU
*/

#include <SFML/Graphics.h>
#include "file_prop.h"
#include "function.h"
#include <stdlib.h>

static int	extract_nbr(char *contents, sfVector2i *begin, sfVector2i *end)
{
  int		i;

  i = 0;
  if (((*begin).x = my_getnbr(contents)) == -1)
    return (-1);
  while ('0' <= contents[i] && contents[i] <= '9')
    ++i;
  if (contents[i] == '\0' ||
      ((*begin).y = my_getnbr(&contents[++i])) == - 1)
    return (-1);
  while ('0' <= contents[i] && contents[i] <= '9')
    ++i;
  if (contents[i] == '\0' ||
      ((*end).x= my_getnbr(&contents[++i])) == -1)
    return (-1);
  while ('0' <= contents[i] && contents[i] <= '9')
    ++i;
  if (contents[i] == '\0' ||
      ((*end).y = my_getnbr(&contents[++i])) == - 1)
    return (-1);
  return (0);
}

static t_file_prop	*extract_room_prop(t_file_prop *files, char *contents)
{
  int			i;
  char			*wallpaper;
  sfVector2i		begin;
  sfVector2i		end;

  i = 0;
  while (contents[i] != '\0' &&
	 my_strncmp(&contents[i], "Collision map:\n", 14) != 0 &&
	 my_strncmp(&contents[i], "Map:\n", 5) != 0)
    {
      if ((wallpaper = my_dupline(&contents[i],
				  my_strlen(&contents[i], ' ') - 1)) == NULL)
	return (NULL);
      i = i + my_strlen(&contents[i], ' ');
      if (extract_nbr(&contents[i], &begin, &end) == -1 ||
	  (files = my_put_rooms_in_files_list(files, wallpaper,
					      begin, end)) == NULL)
	return (NULL);
      i = i + my_strlen(&contents[i], '\n');
    }
  return (files);
}

static t_file_prop	*extract_collision_map(t_file_prop *files,
					       char *contents)
{
  int			i;
  char			*buf;
  char			*map;

  i = 0;
  if ((map = malloc(sizeof(char))) == NULL)
    return (NULL);
  map[0] = '\0';
  while (contents[i] != '\0' &&
	 my_strncmp(&contents[i], "Linked rooms:\n", 13) != 0 &&
	 my_strncmp(&contents[i], "Map:\n", 5) != 0)
    {
      if ((buf = my_dupline(&contents[i],
			    my_strlen(&contents[i], '\n'))) == NULL ||
	  (map = my_strcat_free(map, buf)) == NULL)
	return (NULL);
      i = i + my_strlen(&contents[i], '\n');
      free(buf);
    }
  if (my_str_isbinary(map) != 0 ||
      (files->collision_map = manage_my_tab(map, '\n')) == NULL)
    return (NULL);
  return (files);
}

t_file_prop	*extract_content(t_file_prop *files, char *cnt)
{
  int		i;

  i = -1;
  while (cnt[++i] != '\0')
    {
      if (my_strncmp(&cnt[i], "Linked rooms:\r\n", 15) == 0 ||
	  my_strncmp(&cnt[i], "Collision map:\r\n", 16) == 0 ||
	  my_strncmp(&cnt[i], "Map:\r\n", 6) == 0)
	{
	  if (my_strncmp(&cnt[i], "Linked rooms:\r\n", 15) == 0)
	    if ((files = extract_room_prop
		 (files, &cnt[i += my_strlen(&cnt[i], '\n')])) == NULL)
		return (NULL);
	  if (my_strncmp(&cnt[i], "Collision map:\r\n", 16) == 0)
	    if ((files = extract_collision_map
		 (files, &cnt[i += my_strlen(&cnt[i], '\n')])) == NULL)
	      return (NULL);
	  if (my_strncmp(&cnt[i], "Map:\r\n", 6) == 0 &&
	      (i += my_strlen(&cnt[i], '\n')) > 0)
	    if ((files->wallpaper = my_dupline
		 (&cnt[i], my_strlen(&cnt[i], '\n') - 2)) == NULL)
	      return (NULL);
	}
    }
  return (files);
}
