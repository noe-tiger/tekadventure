/*
** player.c for  in /home/noe/tekadventure
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Tue Apr 11 15:40:39 2017 Noé
** Last update Sun May 28 20:41:12 2017 Victor CHAU
*/

#include "macro.h"
#include "function.h"
#include <math.h>

void			player(sfRenderWindow *window,
			       sfSprite *sprite)
{
  static sfVector2f	position = {10, 10};
  sfVector2i		pos;

  if (sfMouse_isButtonPressed(sfMouseLeft) == 1)
    {
      pos = sfMouse_getPosition((sfWindow *)window);
      position.x = pos.x - 15;
      position.y = pos.y - 15;
      if (position.x < 0.0f)
	position.x = 0.0f;
      if (position.y < 0.0f)
	position.y = 0.0f;
      if (position.y > (float)HEIGHT - 40.0f)
	position.y = (float)HEIGHT - 40.0f;
      if (position.x > (float)WIDTH - 40.0f)
	position.x = (float)WIDTH - 40.0f;
    }
  sfSprite_setPosition(sprite, position);
}
