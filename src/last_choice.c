/*
** last_choise.c for tekadventure in /home/tahery_b/rendu/tekadventure
** 
** Made by Alexandre Tahery
** Login   <tahery_b@epitech.net>
** 
** Started on  Sat May 27 01:42:40 2017 Alexandre Tahery
** Last update Sun May 28 16:56:08 2017 Victor CHAU
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "function.h"
#include "macro.h"
#include "cursor.h"

int		kinder_permission(t_player *player)
{
  int		count;

  count = 0;
  while (count != 6)
    {
      if (player->slot[count] != NULL &&
	  my_strcmp(player->slot[count]->name,
		    "Resources/Item/Item_kinder.png") == 0)
	return (0);
      count += 1;
    }
  return (1);
}

void		go_behind(t_file_prop *buffer, t_player *player,
			    sfRenderWindow *window)
{
  int		val;
  sfVector2i	pos_l;

  pos_l.x = player->pos.x + 100;
  pos_l.y = player->pos.y + 250;
  if (change_room(pos_l, buffer->next,
		  buffer->next->file_name) != NULL)
    {
      player->reset = 1;
      change_room(pos_l, buffer->next, buffer->next->file_name);
      val = 2;
      move(window, &val, 0, player);
    }
}

int		ending_choice(t_player *player, sfRenderWindow *window)
{
  if (kinder_permission(player) == 0)
    true_ending(window);
  else
    bad_ending(window);
  return (0);
}

int		last_choice(char *str, t_player *player,
			    sfRenderWindow *window, sfSprite *aver)
{
  sfVector2i	pos_m;
  sfVector2f	pos_w;
  int		val;

  val = 2;
  if (my_strcmp(str, "couloir_wc.png") == -1 || str == NULL)
    return (-1);
  pos_w.x = WIDTH / 4;
  pos_w.y = HEIGHT / 4;

  pos_m = sfMouse_getPosition((sfWindow *)window);
  if (sfMouse_isButtonPressed(sfMouseLeft) == 1 &&
      (pos_m.x >= 440 && pos_m.x <= 504) && (pos_m.y >= 430 && pos_m.y <= 477))
    return (ending_choice(player, window));
  else if (sfMouse_isButtonPressed(sfMouseLeft) == 1 &&
	   (pos_m.x >= 760 && pos_m.x <= 830) &&
	   (pos_m.y >= 430 && pos_m.y <= 477))
    {
      move(window, &val, 0, player);
      return (42);
    }
  sfSprite_setPosition(aver, pos_w);
  sfRenderWindow_drawSprite(window, aver, NULL);
  return (1);
}
