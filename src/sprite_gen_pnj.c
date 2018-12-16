/*
** sprite_gen_pnj.c for tekadventure in /home/tahery_b/rendu/tekadventure/src
** 
** Made by Alexandre Tahery
** Login   <tahery_b@epitech.net>
** 
** Started on  Sun May 28 17:52:02 2017 Alexandre Tahery
** Last update Sun May 28 20:42:37 2017 Victor CHAU
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "function.h"
#include "cursor.h"

void	sprite_gen_alex(t_sprite **sprites)
{
  if ((sprites[0] = malloc(sizeof(t_sprite))) == NULL)
    return ;
  sprites[0]->sprite = get_sprite("Resources/Npc/npc_alexandre.png");
  sprites[0]->name = "Resources/Npc/npc_alexandre.png";
  sprites[0]->pos.x = 100;
  sprites[0]->pos.y = 100;
  sprites[0]->size = sfTexture_getSize
    (sfTexture_createFromFile("Resources/Npc/npc_alexandre.png", NULL));
  sprites[0]->size.x += sprites[0]->pos.x;
  sprites[0]->size.y += sprites[0]->pos.y;
  sfSprite_setPosition(sprites[0]->sprite, sprites[0]->pos);
}

void	sprite_gen_noe(t_sprite **sprites)
{
  if ((sprites[1] = malloc(sizeof(t_sprite))) == NULL)
    return ;
  sprites[1]->sprite = get_sprite("Resources/Npc/npc_noe.png");
  sprites[1]->name = "Resources/Npc/npc_noe.png";
  sprites[1]->pos.x = 700;
  sprites[1]->pos.y = 200;
  sprites[1]->size = sfTexture_getSize
    (sfTexture_createFromFile("Resources/Npc/npc_noe.png", NULL));
  sprites[1]->size.x += sprites[1]->pos.x;
  sprites[1]->size.y += sprites[1]->pos.y;
  sfSprite_setPosition(sprites[1]->sprite, sprites[1]->pos);
}

void	sprite_gen_victor(t_sprite **sprites)
{
  if ((sprites[2] = malloc(sizeof(t_sprite))) == NULL)
    return ;
  sprites[2]->sprite = get_sprite("Resources/Npc/npc_victor.png");
  sprites[2]->name = "Resources/Npc/npc_victor.png";
  sprites[2]->pos.x = 700;
  sprites[2]->pos.y = 200;
  sprites[2]->size = sfTexture_getSize
    (sfTexture_createFromFile("Resources/Npc/npc_victor.png", NULL));
  sprites[2]->size.x += sprites[2]->pos.x;
  sprites[2]->size.y += sprites[2]->pos.y;
  sfSprite_setPosition(sprites[2]->sprite, sprites[2]->pos);
}
