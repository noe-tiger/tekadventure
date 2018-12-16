/*
** sprites.c for  in /home/noe/tekadventure/src_nono
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Mon Apr 24 16:02:27 2017 Noé
** Last update Sun May 28 20:43:15 2017 Victor CHAU
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "function.h"
#include "cursor.h"

void		alex_fail(sfRenderWindow *window)
{
  sfSprite	*dialog;

  my_putstr("Alexandre : Hé toi la bas, j'ai perdu mon Red Bull"\
	    ", Aide moi a le retrouver, je te donnerai "\
	    "... Des pieces d'or !\n");
  dialog = get_sprite("Resources/Texts/Alex_1.png");
  sfSprite_setPosition(dialog, (sfVector2f) {140, 0});
  sfRenderWindow_drawSprite(window, dialog, NULL);
  sfRenderWindow_display(window);
  while (sfMouse_isButtonPressed(sfMouseLeft));
  while (!sfMouse_isButtonPressed(sfMouseLeft));
  sfSprite_destroy(dialog);
}

void		victor_fail(sfRenderWindow *window)
{
  sfSprite	*dialog;

  my_putstr("Victor : Non, tu n'aura pas ton Kinder, paye moi, et on verra\n");
  dialog = get_sprite("Resources/Texts/Victor_1.png");
  sfSprite_setPosition(dialog, (sfVector2f) {680, 80});
  sfRenderWindow_drawSprite(window, dialog, NULL);
  sfRenderWindow_display(window);
  while (sfMouse_isButtonPressed(sfMouseLeft));
  while (!sfMouse_isButtonPressed(sfMouseLeft));
  sfSprite_destroy(dialog);
}

void		clock_redbull(sfMusic *music)
{
  sfClock	*clock;

  clock = sfClock_create();
  while (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) <
	 sfTime_asMilliseconds(sfMusic_getDuration(music)));
  while (sfMouse_isButtonPressed(sfMouseLeft));
  while (!sfMouse_isButtonPressed(sfMouseLeft));
}
