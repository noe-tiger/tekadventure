/*
** inventory_actions.c for inventory_actions in /home/samuel/MUL/tekadventure
** 
** Made by samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Sun May 28 17:36:58 2017 samuel
** Last update Sun May 28 17:41:02 2017 samuel
*/

#include "cursor.h"
#include "function.h"

void	wich_slot(t_sprite **sprites, t_player *inv,
		  int i, int slot)
{
  if (sprites[i])
    {
      while (inv->slot[slot])
	{
	  if (inv->slot[0] == NULL)
	    {
	      grab_sprite(&inv->slot[slot], sprites[i], 1);
	      break ;
	    }
	  slot++;
	}
    }
}

void	get_inventory(t_sprite **sprites, sfVector2i pos, t_player *inv)
{
  int	i;
  int	slot;

  i = 0;
  slot = 0;
  while (sprites[i])
    {
      if ((pos.x + 100 > sprites[i]->pos.x && pos.y + 250 > sprites[i]->pos.y
	   && pos.x + 100 < (int)sprites[i]->size.x
	   && pos.y + 250 < (int)sprites[i]->size.y)
	  || (pos.x > sprites[i]->pos.x && pos.y > sprites[i]->pos.y
	      && pos.x < (int)sprites[i]->size.x
	      && pos.y  < (int)sprites[i]->size.y)
	  || (pos.x + 200 > sprites[i]->pos.x &&
	      pos.y + 350 > sprites[i]->pos.y
	      && pos.x + 200 < (int)sprites[i]->size.x
	      && pos.y + 350 < (int)sprites[i]->size.y))
	break ;
      i++;
    }
  wich_slot(sprites, inv, i, slot);
}

void		grab_sprite(t_sprite **inv, t_sprite *image, int slot)
{
  sfVector2u	size;

  *inv = image;
  size.x = image->size.x - (unsigned int)image->pos.x;
  size.y = image->size.y - (unsigned int)image->pos.y;
  image->size.x = (10 + (120 * (slot - 1))) + size.x;
  image->size.y = 580 + size.y;
  image->pos.x = 10 + (120 * (slot - 1));
  image->pos.y = 580;
  sfSprite_setPosition(image->sprite, image->pos);
}

int	use_inventory(sfVector2i pos, t_player *inv)
{
  inv = inv;
  if (pos.x > 10 && pos.x < 130 && pos.y > 580 && pos.y < 720)
    return (-1);
  else if (pos.x > 130 && pos.x < 250 && pos.y > 580 && pos.y < 720)
    return (-2);
  else if (pos.x > 250 && pos.x < 370 && pos.y > 580 && pos.y < 720)
    return (-3);
  else if (pos.x > 370 && pos.x < 490 && pos.y > 580 && pos.y < 720)
    return (-4);
  else if (pos.x > 490 && pos.x < 510 && pos.y > 580 && pos.y < 720)
    return (-5);
  else if (pos.x > 510 && pos.x < 630 && pos.y > 580 && pos.y < 720)
    return (-6);
  return (0);
}

int	give_inventory(sfVector2i pos)
{
  if (pos.x > 10 && pos.x < 130 && pos.y > 580 && pos.y < 720)
    return (1);
  else if (pos.x > 130 && pos.x < 250 && pos.y > 580 && pos.y < 720)
    return (2);
  else if (pos.x > 250 && pos.x < 370 && pos.y > 580 && pos.y < 720)
    return (3);
  else if (pos.x > 370 && pos.x < 490 && pos.y > 580 && pos.y < 720)
    return (4);
  else if (pos.x > 490 && pos.x < 510 && pos.y > 580 && pos.y < 720)
    return (5);
  else if (pos.x > 510 && pos.x < 630 && pos.y > 580 && pos.y < 720)
    return (6);
  return (0);
}
