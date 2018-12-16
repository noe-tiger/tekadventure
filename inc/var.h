/*
** var.h for tekad in /home/viktouille/MUL/tekadventure
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Sun May 28 16:03:17 2017 Victor CHAU
** Last update Mon May 29 21:54:59 2017 Noé
*/

#ifndef VAR_H_
# define VAR_H_

# include "cursor.h"
# include "player.h"
# include "file_prop.h"

typedef struct			s_var
{
  struct s_sprite		**sprites;
  struct s_sprite		**obj;
  sfSprite			*inventory;
  sfSprite			*curs;
  sfEvent			event;
  struct s_player		player;
  sfVector2f			pos;
  struct s_file_prop		*buffer;
  char				*room;
  struct s_map			map[8];
  int				val;
  sfSprite			*avertisment;
}				t_var;

t_var	zar;

#endif /* !VAR_H_ */
