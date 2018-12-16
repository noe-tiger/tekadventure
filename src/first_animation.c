/*
** first_animation.c for tekad in /home/viktouille/MUL/tekadventure/src_victor
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Tue Apr 11 16:13:54 2017 Victor CHAU
** Last update Wed Apr 19 14:42:55 2017 Victor CHAU
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "function.h"
#include "macro.h"

int		animation(sfRenderWindow *window)
{
  sfEvent	event;
  sfSprite	*sprite;

  sprite = NULL;
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfBlack);
      while (sfRenderWindow_pollEvent(window, &event))
	if ((event.type == sfEvtClosed) ||
	    (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
	  sfRenderWindow_close(window);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
  return (0);
}
