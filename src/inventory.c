/*
** inventory.c for  in /home/noe/tekadventure/src_nono
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Mon Apr 24 15:25:36 2017 Noé
** Last update Sun May 28 17:40:20 2017 samuel
*/

#include "cursor.h"
#include "function.h"

void	get_into_inventory(t_sprite *sprites, t_player *inv)
{
  int	slot;

  slot = 1;
  if (sprites)
    {
      if (inv->slot[0] == NULL && (slot = 1))
	grab_sprite(&inv->slot[0], sprites, 1);
      else if (inv->slot[1] == NULL && (slot = 2))
	grab_sprite(&inv->slot[1], sprites, 2);
      else if (inv->slot[2] == NULL && (slot = 3))
	grab_sprite(&inv->slot[2], sprites, 3);
      else if (inv->slot[3] == NULL && (slot = 4))
	grab_sprite(&inv->slot[3], sprites, 4);
      else if (inv->slot[4] == NULL && (slot = 5))
	grab_sprite(&inv->slot[4], sprites, 5);
      else if (inv->slot[5] == NULL && (slot = 6))
	grab_sprite(&inv->slot[5], sprites, 6);
    }
  sprites->pos.x = 10 + (120 * (slot - 1));
  sprites->pos.y = 580;
  sfSprite_setPosition(sprites->sprite, sprites->pos);
}

void		delete_sprite(t_player *inv, int slot)
{
  sfVector2f	del;

  if (inv->slot[slot - 1] == NULL)
    return ;
  del.x = 10000;
  del.y = 10000;
  sfSprite_setPosition(inv->slot[slot - 1]->sprite, del);
  inv->slot[slot - 1]->pos = del;
  inv->slot[slot - 1]->size.x = 10000;
  inv->slot[slot - 1]->size.y = 10000;
  inv->slot[slot - 1] = NULL;
}
