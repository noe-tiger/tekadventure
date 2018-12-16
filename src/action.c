/*
** action.c for  in /home/noe/tekadventure/src_nono
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Sun Apr 23 14:50:25 2017 Noé
** Last update Sat May 27 11:36:57 2017 Noé
*/

#include <stdio.h>
#include "cursor.h"
#include "function.h"
#include "macro.h"

int	print_wich_action(int *action, t_sprite **sprites,
			  sfVector2i pos, t_player *inv)
{
  if (*action == 1 && pos.y < 580)
    my_putstr("User is going to Look\n");
  if (*action == 2 && pos.y > 580 && pos.x < 730)
    return (use_inventory(pos, inv));
  if (*action == 3 && pos.y < 580)
    my_putstr("User is going to Talk\n");
  if (*action == 4 && pos.y < 580)
    get_inventory(sprites, pos, inv);
  if (*action == 5 && pos.y > 580 && pos.x < 730)
    return (give_inventory(pos));
  if (*action == 6 && pos.y < 580)
    my_putstr("User is going to Insult someone\n");
  return (0);
}

void	get_action(int *action, const sfVector2i pos)
{
  if (pos.x > 730 && pos.x < 900 && pos.y > 580 && pos.y < 650)
    *action = 1;
  if (pos.x > 730 && pos.x < 900 && pos.y > 650 && pos.y < 700)
    *action = 2;
  if (pos.x > 900 && pos.x < 1075 && pos.y > 580 && pos.y < 650)
    *action = 3;
  if (pos.x > 900 && pos.x < 1075 && pos.y > 650 && pos.y < 700)
    *action = 4;
  if (pos.x > 1075 && pos.x < 1250 && pos.y > 580 && pos.y < 650)
    *action = 5;
  if (pos.x > 1075 && pos.x < 1250 && pos.y > 650 && pos.y < 700)
    *action = 6;
}
