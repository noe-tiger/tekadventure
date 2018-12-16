/*
** credits.c for credits in /home/samuel/Mul/tekadventure
** 
** Made by samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Wed Apr 19 18:17:44 2017 samuel
** Last update Mon May 29 23:17:18 2017 samuel
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

void	re_render(sfRenderWindow *window, sfSprite *sprite, sfVector2f pos)
{
  sfSprite_setPosition(sprite, pos);
  sfRenderWindow_clear(window, sfBlack);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfRenderWindow_display(window);
}

int		move_credits(sfRenderWindow *window, sfVector2f pos,
			     sfMusic *music, sfSprite *sprite)
{
  sfEvent	event;

  while (pos.y > -3940)
    {
      while (sfRenderWindow_pollEvent(window, &event))
	if (event.type == sfEvtClosed)
	  {
	    sfMusic_stop(music);
	    sfRenderWindow_close(window);
	    return (-1);
	  }
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	return (-1);
      pos.y -= 0.1;
      re_render(window, sprite, pos);
    }
  return (0);
}

void		credits(sfRenderWindow *window, char *mode)
{
  sfTexture	*texture;
  sfSprite	*sprite;
  sfVector2f	pos;
  sfClock	*clock;
  sfMusic	*music;

  pos.x = 0;
  pos.y = 0;
  sprite = sfSprite_create();
  texture = sfTexture_createFromFile("Resources/Level/Credits/Credits.png",
				     NULL);
  sfSprite_setTexture(sprite, texture, sfTrue);
  re_render(window, sprite, pos);
  clock = sfClock_create();
  music = sfMusic_createFromFile(mode);
  sfMusic_play(music);
  while (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) < 3000);
  if (move_credits(window, pos, music, sprite) == -1)
    return ;
  sfClock_restart(clock);
  while (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) < 5000);
  sfMusic_stop(music);
  sfRenderWindow_close(window);
}
