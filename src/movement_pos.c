/*
** movement_pos.c for  in /home/noe/test/tekadventure/src
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Mon May 29 21:15:05 2017 Noé
** Last update Mon May 29 21:15:06 2017 Noé
*/

#include <SFML/Graphics.h>
#include "function.h"
#include "player.h"

sfVector2f	reset_pos(t_player *player, sfVector2i *curs, sfVector2f *pos)
{
  if (player->reset == 1)
    {
      player->reset = 0;
      pos->y = 260;
      pos->x = 540;
      curs->y = 260;
      curs->x = 540;
      player->pos.y = 260;
      player->pos.x = 540;
      return (*pos);
    }
  return (*pos);
}

sfVector2f		move(sfRenderWindow *window, int *dir, int *action,
			     t_player *player)
{
  static sfVector2i	curs = {540, 260};
  static sfVector2f	pos = {540, 260};
  static int		togg = 0;

  if (player->reset == 1)
    return (reset_pos(player, &curs, &pos));
  if (curs.x != pos.x || curs.y != pos.y)
    update_pos(&pos, &curs, dir);
  if (*dir < 0 || *dir > 3)
    *dir = 2;
  if (!sfMouse_isButtonPressed(sfMouseLeft))
    {
      togg = 0;
      return (pos);
    }
  if (togg == 1)
    return (pos);
  if (sfMouse_isButtonPressed(sfMouseLeft) && togg == 0)
    togg = what_to_do(window, &curs, player, action);
  player->dest.x = curs.x + 100;
  player->dest.y = curs.y + 250;
  return (pos);
}
