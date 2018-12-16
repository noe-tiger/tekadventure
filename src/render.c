/*
** render.c for tekadventure in /home/tahery_b/rendu/tekadventure/src
** 
** Made by Alexandre Tahery
** Login   <tahery_b@epitech.net>
** 
** Started on  Sun May 28 17:40:00 2017 Alexandre Tahery
** Last update Sun May 28 17:40:16 2017 Alexandre Tahery
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "function.h"
#include "cursor.h"

void		render_objects(t_sprite **sprites, sfRenderWindow *window,
			       char *room, t_player *player)
{
  static int	togg = 0;
  int		i;

  i = 0;
  if (!sfMouse_isButtonPressed(sfMouseLeft))
    togg = 0;
  if (sfMouse_isButtonPressed(sfMouseLeft) && togg == 0)
    {
      get_redbull(sprites, window, room, player);
      get_money(sprites, window, room, player);
      get_kinder(sprites, window, room, player);
      togg = 1;
    }
  while (sprites[i])
    {
      sfRenderWindow_drawSprite(window, sprites[i]->sprite, NULL);
      i++;
    }
}

void	render_sprites(t_sprite **sprites, sfRenderWindow *window, char *room)
{
  int	i;

  i = -1;
  if (my_strcmp(room, "sm24.png") == 0)
    i = 0;
  if (my_strcmp(room, "couloir_wc.png") == 0)
    i = 1;
  if (my_strcmp(room, "sm25.png") == 0)
    i = 2;
  if (i >= 0)
    sfRenderWindow_drawSprite(window, sprites[i]->sprite, NULL);
}
