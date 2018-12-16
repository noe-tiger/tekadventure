/*
** print_obj.c for tekadventure in /home/tahery_b/rendu/tekadventure/src
** 
** Made by Alexandre Tahery
** Login   <tahery_b@epitech.net>
** 
** Started on  Sun May 28 18:04:36 2017 Alexandre Tahery
** Last update Sun May 28 20:41:38 2017 Victor CHAU
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "function.h"
#include "cursor.h"

void		print_money(t_sprite **sprites, sfRenderWindow *window,
			    t_player *player)
{
  sfSprite	*dialog;

  my_putstr("Alexandre : Merci Aventurier, Comme promis voici ta " \
	    "récompense !\nUne somme dérisoire d'argent, juste as"\
	    "sez pour un Kinder !\n");
  delete_sprite(player, 1);
  dialog = get_sprite("Resources/Texts/Alex_2.png");
  sfSprite_setPosition(dialog, (sfVector2f) {140, 0});
  sfRenderWindow_drawSprite(window, dialog, NULL);
  sfRenderWindow_display(window);
  while (sfMouse_isButtonPressed(sfMouseLeft));
  while (!sfMouse_isButtonPressed(sfMouseLeft));
  sfSprite_destroy(dialog);
  get_into_inventory(sprites[2], player);
}

void		print_kinder(t_sprite **sprites, sfRenderWindow *window,
			     t_player *player)
{
  sfSprite	*dialog;

  my_putstr("Victor : Tu as mon fric ? Ah ! Bon, tiens, voici ton Kinder !\n");
  delete_sprite(player, 1);
  dialog = get_sprite("Resources/Texts/Victor_2.png");
  sfSprite_setPosition(dialog, (sfVector2f) {680, 80});
  sfRenderWindow_drawSprite(window, dialog, NULL);
  sfRenderWindow_display(window);
  while (sfMouse_isButtonPressed(sfMouseLeft));
  while (!sfMouse_isButtonPressed(sfMouseLeft));
  sfSprite_destroy(dialog);
  get_into_inventory(sprites[1], player);
}
