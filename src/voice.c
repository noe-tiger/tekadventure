/*
** voice.c for wait_voices in /home/samuel/MUL/tekadventure
** 
** Made by samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Wed May 24 17:13:04 2017 samuel
** Last update Sun May 28 17:16:05 2017 Victor CHAU
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

void		play_voice(char *name, sfRenderWindow *window)
{
  sfClock	*clock;
  sfMusic	*voice;
  sfEvent	event;

  voice = sfMusic_createFromFile(name);
  sfMusic_play(voice);
  clock = sfClock_create();
  while (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) <
	 sfTime_asMilliseconds(sfMusic_getDuration(voice)))
    while (sfRenderWindow_pollEvent(window, &event))
      if (event.type == sfEvtClosed)
	{
	  sfMusic_stop(voice);
	  sfRenderWindow_close(window);
	}
  sfMusic_stop(voice);
}

void		wait_voices(char *first, char *second,
			    int time, sfRenderWindow *window)
{
  sfClock	*clock;
  sfEvent	event;

  if (first != NULL)
    play_voice(first, window);
  clock = sfClock_create();
  while (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) < time)
    while (sfRenderWindow_pollEvent(window, &event))
      if (event.type == sfEvtClosed)
	sfRenderWindow_close(window);
  if (second != NULL)
    play_voice(second, window);
}
