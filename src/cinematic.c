/*
** cinematic.c for tekadventure in /home/samuel/MUL/tekadventure
** 
** Made by samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Wed May 24 17:19:45 2017 samuel
** Last update Wed May 24 17:22:10 2017 samuel
*/

#include <SFML/Graphics.h>

static void	render(sfRenderWindow *window, sfSprite *sprite)
{
  sfRenderWindow_clear(window, sfBlack);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfRenderWindow_display(window);
}

void		cinematic(sfRenderWindow *window, sfSprite *sprite, char *path)
{
  sfTexture	*texture;

  texture = sfTexture_createFromFile(path, NULL);
  sfSprite_setTexture(sprite, texture, sfTrue);
  render(window, sprite);
}
