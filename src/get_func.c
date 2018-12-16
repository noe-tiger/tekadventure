/*
** get_func.c for tekadventure in /home/tahery_b/rendu/tekadventure/src
** 
** Made by Alexandre Tahery
** Login   <tahery_b@epitech.net>
** 
** Started on  Sun May 28 17:56:56 2017 Alexandre Tahery
** Last update Sun May 28 23:28:58 2017 Victor CHAU
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "function.h"
#include "cursor.h"

void		get_redbull(t_sprite **sprites, sfRenderWindow *window,
			    char *room, t_player *player)
{
  sfSprite	*dialog;
  static int	can = 0;
  sfMusic	*music;

  if (my_strcmp("sm26.png", room) == 0 && can == 0
      && sfMouse_getPosition((sfWindow *) window).x > 485
      && sfMouse_getPosition((sfWindow *) window).x < 554
      && sfMouse_getPosition((sfWindow *) window).y > 210
      && sfMouse_getPosition((sfWindow *) window).y < 286)
    {
      can = 1;
      my_putstr("Canette de Redbull : Nom d'une feuille ! Tu m'as trouvé !\n");
      music = sfMusic_createFromFile("Resources/Texts/redbull_canet.wav");
      sfMusic_play(music);
      dialog = get_sprite("Resources/Texts/nom_dune_feuille.png");
      sfSprite_setPosition(dialog, (sfVector2f) {311, 420});
      sfRenderWindow_drawSprite(window, dialog, NULL);
      sfRenderWindow_display(window);
      clock_redbull(music);
      sfMusic_stop(music);
      sfSprite_destroy(dialog);
      get_into_inventory(sprites[3], player);
    }
}

void	get_money(t_sprite **sprites, sfRenderWindow *window,
		  char *room, t_player *player)
{
  if (my_strcmp("sm24.png", room) == 0
      && sfMouse_getPosition((sfWindow *) window).x > 100
      && sfMouse_getPosition((sfWindow *) window).x < 200
      && sfMouse_getPosition((sfWindow *) window).y > 100
      && sfMouse_getPosition((sfWindow *) window).y < 400)
    {
      if (player->slot[0])
	{
	  if (my_strcmp(player->slot[0]->name, sprites[3]->name) == 0)
	    print_money(sprites, window, player);
	  else
	    alex_fail(window);
	}
      else
	alex_fail(window);
    }
}

void	get_kinder(t_sprite **sprites, sfRenderWindow *window, char *room,
		   t_player *player)
{
  if (my_strcmp("sm25.png", room) == 0
      && sfMouse_getPosition((sfWindow *) window).x > 700
      && sfMouse_getPosition((sfWindow *) window).x < 820
      && sfMouse_getPosition((sfWindow *) window).y > 200
      && sfMouse_getPosition((sfWindow *) window).y < 420)
    {
      if (player->slot[0])
	{
	  if (my_strcmp(player->slot[0]->name, sprites[2]->name) == 0)
	    print_kinder(sprites, window, player);
	  else
	    victor_fail(window);
	}
      else
	victor_fail(window);
    }
}
