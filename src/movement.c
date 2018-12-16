/*
** movement.c for  in /home/noe/test/tekadventure/src
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Mon May 29 21:14:41 2017 Noé
** Last update Mon May 29 23:03:25 2017 Victor CHAU
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "var.h"
#include "function.h"
#include "macro.h"
#include "cursor.h"

void		get_curs(sfVector2i *curs, t_player *player,
			 sfRenderWindow *window)
{
  t_file_prop	*map;

  map = zar.buffer;
  while (my_strcmp(map->wallpaper, zar.room) != 0 && map->next)
    map = map->next;
  if (sfMouse_getPosition((sfWindow *)window).y > 0 &&
      sfMouse_getPosition((sfWindow *)window).x > 0)
    {
      if (map->collision_map[sfMouse_getPosition((sfWindow *)window).y]
	  [sfMouse_getPosition((sfWindow *)window).x] != '1'
	  && !change_room(sfMouse_getPosition((sfWindow *)window),
			  zar.buffer, zar.room))
	return ;
      *curs = sfMouse_getPosition((sfWindow *)window);
      if (player->scale < 0.8f)
	{
	  curs->y = curs->y - 125;
	  curs->x = curs->x - 50;
	}
      else
	{
	  curs->y = curs->y - 250;
	  curs->x = curs->x - 100;
	}
    }
}

int	what_to_do(sfRenderWindow *window, sfVector2i *curs,
		   t_player *player, int *action)
{
  if (sfMouse_getPosition((sfWindow *)window).y < 570)
    get_curs(curs, player, window);
  else
    get_action(action, sfMouse_getPosition((sfWindow *)window));
  return (1);
}

void	set_scale(sfVector2f *scale, t_player *player)
{
  if (player->pos.y < 160)
    player->scale = 0.5;
  else if (player->pos.y < 300 && player->pos.y >= 160)
    player->scale = 1.0f;
  else
    player->scale = 2.0f;
  scale->x = player->scale;
  scale->y = player->scale;
}

void	use_inv(int *action, int *object, sfRenderWindow *window,
		t_player *player)
{
  if (*action == 2)
    {
      if (sfMouse_isButtonPressed(sfMouseLeft))
	*object = use_inventory(sfMouse_getPosition((sfWindow *)window),
				player);
      if (*object != 0)
	{
	  *object = 0;
	  *action = 0;
	}
    }
  if (*action == 5)
    {
      if (sfMouse_isButtonPressed(sfMouseLeft))
	*object = give_inventory(sfMouse_getPosition((sfWindow *)window));
      if (*object != 0)
	{
	  delete_sprite(player, *object);
	  *object = 0;
	  *action = 0;
	}
    }
}

void		print_leo(t_player *player, sfVector2f *pos,
			  sfRenderWindow *window,
			  t_sprite **sprites)
{
  sfVector2f	old;
  sfVector2f	scale;
  static int	action = 0;
  static int	object = 0;

  old = *pos;
  use_inv(&action, &object, window, player);
  *pos = move(window, &player->direction, &action, player);
  set_scale(&scale, player);
  if (pos->x == old.x && pos->y == old.y)
    {
      print_static(player, scale, pos, window);
      if (action != 0)
	object = print_wich_action(&action, sprites, player->pos, player);
      if (action == 1 || action == 3 || action == 4 || action == 6)
	action = 0;
    }
  else
    print_move(player, pos, window, scale);
  player->pos.x = pos->x;
  player->pos.y = pos->y;
}
