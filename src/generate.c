/*
** generate.c for tekadventure in /home/tahery_b/rendu/tekadventure/src
** 
** Made by Alexandre Tahery
** Login   <tahery_b@epitech.net>
** 
** Started on  Sun May 28 17:42:48 2017 Alexandre Tahery
** Last update Sun May 28 18:08:29 2017 Alexandre Tahery
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "function.h"
#include "cursor.h"

void		generate_maps(t_map *map)
{
  map[0].name = "couloir_25_26.png";
  map[0].sprite = get_sprite("Resources/Level/couloir_25_26.png");
  map[1].name = "couloir_wc.png";
  map[1].sprite = get_sprite("Resources/Level/couloir_wc.png");
  map[2].name = "machine_cafe.png";
  map[2].sprite = get_sprite("Resources/Level/machine_cafe.png");
  map[3].name = "sm24.png";
  map[3].sprite = get_sprite("Resources/Level/sm24.png");
  map[4].name = "sm25.png";
  map[4].sprite = get_sprite("Resources/Level/sm25.png");
  map[5].name = "sm26_bin.png";
  map[5].sprite = get_sprite("Resources/Level/sm26_bin.png");
  map[6].name = "sm26.png";
  map[6].sprite = get_sprite("Resources/Level/sm26.png");
  map[7].name = NULL;
}

t_sprite	**generate_sprites()
{
  t_sprite	**sprites;

  my_putstr("PNJ generation...\n");
  if ((sprites = malloc(sizeof(t_sprite *) * 4)) == NULL)
    return (NULL);
  sprite_gen_alex(sprites);
  sprite_gen_noe(sprites);
  sprite_gen_victor(sprites);
  sprites[3] = NULL;
  my_putstr("PNJ generated !\n");
  return (sprites);
}

t_sprite	**generate_items()
{
  t_sprite	**sprites;

  my_putstr("objects generation...\n");
  if ((sprites = malloc(sizeof(t_sprite *) * 5)) == NULL)
    return (NULL);
  sprite_gen_cofee(sprites);
  sprite_gen_kinder(sprites);
  sprite_gen_money(sprites);
  sprite_gen_redbull(sprites);
  sprites[4] = NULL;
  my_putstr("objects generated !\n");
  return (sprites);
}
