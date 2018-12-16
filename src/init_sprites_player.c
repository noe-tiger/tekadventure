/*
** init_sprites_player.c for  in /home/noe/tekadventure
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Mon May 22 14:14:04 2017 Noé
** Last update Sun May 28 16:57:19 2017 Victor CHAU
*/

#include "cursor.h"
#include "player.h"
#include "function.h"

void	init_slots(t_player *player)
{
  int	i;

  i = 0;
  while (i < 6)
    {
      player->slot[i] = NULL;
      i++;
    }
}

void	init_sprites_player(t_player *player)
{
  my_putstr("loading left sprites...\n");
  player->side[0].no_mov = get_sprite(NO_MOVE_LEFT);
  player->side[0].mov_1 = get_sprite(MOVE_1_LEFT);
  player->side[0].mov_2 = get_sprite(MOVE_2_LEFT);
  my_putstr("loading right sprites...\n");
  player->side[1].no_mov = get_sprite(NO_MOVE_RIGHT);
  player->side[1].mov_1 = get_sprite(MOVE_1_RIGHT);
  player->side[1].mov_2 = get_sprite(MOVE_2_RIGHT);
  my_putstr("loading front sprites...\n");
  player->side[2].no_mov = get_sprite(NO_MOVE_FRONT);
  player->side[2].mov_1 = get_sprite(MOVE_1_FRONT);
  player->side[2].mov_2 = get_sprite(MOVE_2_FRONT);
  my_putstr("loading back sprites...\n");
  player->side[3].no_mov = get_sprite(NO_MOVE_BACK);
  player->side[3].mov_1 = get_sprite(MOVE_1_BACK);
  player->side[3].mov_2 = get_sprite(MOVE_2_BACK);
  player->pos.x = 590;
  player->pos.y = 360;
  player->direction = 1;
  init_slots(player);
  my_putstr("player sprites done !\n");
}
