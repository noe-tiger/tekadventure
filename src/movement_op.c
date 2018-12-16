/*
** movement_op.c for  in /home/noe/test/tekadventure/src
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Mon May 29 21:14:54 2017 Noé
** Last update Mon May 29 23:03:49 2017 Victor CHAU
*/

#include <SFML/Graphics.h>
#include "function.h"
#include "player.h"

void	update_pos(sfVector2f *pos, sfVector2i *curs, int *dir)
{
  if (pos->x > curs->x)
    {
      pos->x -= 1;
      *dir = 0;
    }
  if (pos->x < curs->x)
    {
      pos->x += 1;
      *dir = 1;
    }
  if (pos->y > curs->y)
    {
      pos->y -= 1;
      *dir = 3;
    }
  if (pos->y < curs->y)
    {
      pos->y += 1;
      *dir = 2;
    }
}

void		print_move(t_player *player, sfVector2f *pos,
			   sfRenderWindow *window, sfVector2f scale)
{
  static int	i = 0;

  i++;
  if (i % 100 < 50)
    print_leo_mov_left(player, scale, pos, window);
  else
    print_leo_mov_right(player, scale, pos, window);
}

void		print_leo_mov_right(t_player *player, sfVector2f scale,
				    sfVector2f *pos, sfRenderWindow *window)
{
  sfSprite_setScale(player->side[player->direction].mov_2, scale);
  sfSprite_setPosition(player->side[player->direction].mov_2, *pos);
  sfRenderWindow_drawSprite(window, player->side[player->direction].mov_2,
			    NULL);
  sfSprite_setPosition(player->side[player->direction].no_mov,
		       (sfVector2f) {10000, 10000});
  sfRenderWindow_drawSprite(window, player->side[player->direction].no_mov,
			    NULL);
  sfSprite_setPosition(player->side[player->direction].mov_1,
		       (sfVector2f) {10000, 10000});
  sfRenderWindow_drawSprite(window, player->side[player->direction].mov_1,
			    NULL);
}

void		print_leo_mov_left(t_player *player, sfVector2f scale,
				   sfVector2f *pos, sfRenderWindow *window)
{
  sfSprite_setScale(player->side[player->direction].mov_1, scale);
  sfSprite_setPosition(player->side[player->direction].mov_1, *pos);
  sfRenderWindow_drawSprite(window, player->side[player->direction].mov_1,
			    NULL);
  sfSprite_setPosition(player->side[player->direction].no_mov,
		       (sfVector2f) {10000, 10000});
  sfRenderWindow_drawSprite(window, player->side[player->direction].no_mov,
			    NULL);
  sfSprite_setPosition(player->side[player->direction].mov_2,
		       (sfVector2f) {10000, 10000});
  sfRenderWindow_drawSprite(window, player->side[player->direction].mov_2,
			    NULL);
}

void		print_static(t_player *player, sfVector2f scale,
			     sfVector2f *pos, sfRenderWindow *window)
{
  sfSprite_setScale(player->side[player->direction].no_mov, scale);
  sfSprite_setPosition(player->side[player->direction].no_mov, *pos);
  sfRenderWindow_drawSprite(window, player->side[player->direction].no_mov,
			    NULL);
  sfSprite_setPosition(player->side[player->direction].mov_1,
		       (sfVector2f) {10000, 10000});
  sfRenderWindow_drawSprite(window, player->side[player->direction].mov_1,
			    NULL);
  sfSprite_setPosition(player->side[player->direction].mov_2,
		       (sfVector2f) {10000, 10000});
  sfRenderWindow_drawSprite(window, player->side[player->direction].mov_2,
			    NULL);
}
