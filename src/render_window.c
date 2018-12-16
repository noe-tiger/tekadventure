/*
** render_window.c for tekad in /home/viktouille/MUL/tekadventure
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Fri May 26 17:56:56 2017 Victor CHAU
** Last update Fri May 26 17:59:09 2017 Victor CHAU
*/

#include <SFML/Graphics.h>

void	render_window(sfRenderWindow *window, sfSprite *wallpaper,
		      sfSprite *leo, sfSprite *button)
{
  sfRenderWindow_drawSprite(window, wallpaper, NULL);
  sfRenderWindow_drawSprite(window, leo, NULL);
  sfRenderWindow_drawSprite(window, button, NULL);
}
