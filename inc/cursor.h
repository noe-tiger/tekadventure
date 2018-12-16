/*
** cursor.h for  in /home/noe/tekadventure
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Mon Apr 10 16:01:30 2017 Noé
** Last update Sun May 28 20:24:57 2017 Victor CHAU
*/

#ifndef		CURSOR_H_
# define	CURSOR_H_

# include <SFML/Window.h>
# include <SFML/Graphics.h>
# include <stdio.h>
# include "player.h"
# include "file_prop.h"

typedef struct	s_map
{
  char		*name;
  sfSprite	*sprite;
}		t_map;

sfSprite	*get_sprite(char *);
void		cursor(sfRenderWindow *, sfSprite *);
void		player(sfRenderWindow *, sfSprite *);
t_sprite	**generate_sprites();
t_sprite	**generate_items();
void		get_inventory(t_sprite **, sfVector2i, t_player *);
int		give_inventory(sfVector2i);
int		use_inventory(sfVector2i, t_player *);
void		render_sprites(t_sprite **, sfRenderWindow *, char *);
void		render_objects(t_sprite **, sfRenderWindow *,
			       char *, t_player *);
void		delete_sprite(t_player *, int);
void		print_action(sfWindow *, t_sprite **, t_player *);
void		generate_maps(t_map *);
void		print_maps(t_map *, char *, sfRenderWindow *);
sfVector2f	move(sfRenderWindow *, int *, int *, t_player *);
void		get_into_inventory(t_sprite *, t_player *);

#endif		/* !CURSOR_H_ */
