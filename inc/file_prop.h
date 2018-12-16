/*
** file_prop.h for tekad in /home/viktouille/MUL/tekadventure/src_victor
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Thu May 25 14:44:41 2017 Victor CHAU
** Last update Mon May 29 22:08:03 2017 Noé
*/

#ifndef FILE_PROP_H_
# define FILE_PROP_H_

# include <SFML/Graphics.h>

typedef struct		s_room_prop
{
  char			*wallpaper;
  sfVector2i		begin;
  sfVector2i		end;
  struct s_room_prop	*next;
}			t_room_prop;

typedef struct		s_file_prop
{
  char			*file_name;
  char			*wallpaper;
  struct s_room_prop	*room;
  char			**collision_map;
  struct s_file_prop	*next;
}			t_file_prop;

#endif /* !FILE_PROP_H_ */
