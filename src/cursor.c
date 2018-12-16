/*
** cursor.c for  in /home/noe/tekadventure/src_nono
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Mon Apr 10 15:54:29 2017 Noé
** Last update Sat May 27 03:14:20 2017 Alexandre Tahery
*/

#include "function.h"
#include "cursor.h"

sfSprite	*get_sprite(char *name)
{
  sfSprite	*sprite;
  sfTexture	*texture;
  sfVector2f	pos;

  pos.x = 0;
  pos.y = 0;
  sprite = sfSprite_create();
  texture = sfTexture_createFromFile(name, NULL);
  sfSprite_setTexture(sprite, texture, sfTrue);
  sfSprite_setPosition(sprite, pos);
  return (sprite);
}

void		cursor(sfRenderWindow *window, sfSprite *sprite)
{
  sfVector2i	position;
  sfVector2f	position_f;

  position = sfMouse_getPosition((sfWindow *)window);
  position_f.x = position.x - 15;
  position_f.y = position.y - 15;
  sfSprite_setPosition(sprite, position_f);
}
