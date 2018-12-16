/*
** sprite_gen_obj.c for tekadventure in /home/tahery_b/rendu/tekadventure/src
** 
** Made by Alexandre Tahery
** Login   <tahery_b@epitech.net>
** 
** Started on  Sun May 28 18:00:25 2017 Alexandre Tahery
** Last update Sun May 28 18:00:39 2017 Alexandre Tahery
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "function.h"
#include "cursor.h"

void	sprite_gen_cofee(t_sprite **sprites)
{
  if ((sprites[0] = malloc(sizeof(t_sprite))) == NULL)
    return ;
  sprites[0]->sprite = get_sprite("Resources/Item/Item_coffee.png");
  sprites[0]->name = "Resources/Item/Item_coffee.png";
  sprites[0]->pos.x = -100;
  sprites[0]->pos.y = 100;
  sprites[0]->size = sfTexture_getSize
    (sfTexture_createFromFile("Resources/Item/Item_coffee.png", NULL));
  sprites[0]->size.x += sprites[0]->pos.x;
  sprites[0]->size.y += sprites[0]->pos.y;
  sfSprite_setPosition(sprites[0]->sprite, sprites[0]->pos);
}

void	sprite_gen_kinder(t_sprite **sprites)
{
  if ((sprites[1] = malloc(sizeof(t_sprite))) == NULL)
    return ;
  sprites[1]->sprite = get_sprite("Resources/Item/Item_kinder.png");
  sprites[1]->name = "Resources/Item/Item_kinder.png";
  sprites[1]->pos.x = -200;
  sprites[1]->pos.y = 100;
  sprites[1]->size = sfTexture_getSize
    (sfTexture_createFromFile("Resources/Item/Item_kinder.png", NULL));
  sprites[1]->size.x += sprites[1]->pos.x;
  sprites[1]->size.y += sprites[1]->pos.y;
  sfSprite_setPosition(sprites[1]->sprite, sprites[1]->pos);
}

void	sprite_gen_money(t_sprite **sprites)
{
  if ((sprites[2] = malloc(sizeof(t_sprite))) == NULL)
    return ;
  sprites[2]->sprite = get_sprite("Resources/Item/Item_money.png");
  sprites[2]->name = "Resources/Item/Item_money.png";
  sprites[2]->pos.x = -300;
  sprites[2]->pos.y = 100;
  sprites[2]->size = sfTexture_getSize
    (sfTexture_createFromFile("Resources/Item/Item_money.png", NULL));
  sprites[2]->size.x += sprites[2]->pos.x;
  sprites[2]->size.y += sprites[2]->pos.y;
  sfSprite_setPosition(sprites[2]->sprite, sprites[2]->pos);
}

void	sprite_gen_redbull(t_sprite **sprites)
{
  if ((sprites[3] = malloc(sizeof(t_sprite))) == NULL)
    return ;
  sprites[3]->sprite = get_sprite("Resources/Item/Item_redbull.png");
  sprites[3]->name = "Resources/Item/Item_redbull.png";
  sprites[3]->pos.x = -400;
  sprites[3]->pos.y = 100;
  sprites[3]->size = sfTexture_getSize
    (sfTexture_createFromFile("Resources/Item/Item_redbull.png", NULL));
  sprites[3]->size.x += sprites[3]->pos.x;
  sprites[3]->size.y += sprites[3]->pos.y;
  sfSprite_setPosition(sprites[3]->sprite, sprites[3]->pos);
}
