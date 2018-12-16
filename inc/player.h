/*
** player.h for  in /home/noe/tekadventure
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Mon May 22 14:11:30 2017 Noé
** Last update Mon May 29 21:54:40 2017 Noé
*/

#ifndef PLAYER_H_
# define PLAYER_H_

#include <SFML/System.h>

# define NO_MOVE_LEFT	"Resources/Leo/LP.png"
# define MOVE_1_LEFT	"Resources/Leo/LW1.png"
# define MOVE_2_LEFT	"Resources/Leo/LW2.png"
# define NO_MOVE_RIGHT	"Resources/Leo/RP.png"
# define MOVE_1_RIGHT	"Resources/Leo/RW1.png"
# define MOVE_2_RIGHT	"Resources/Leo/RW2.png"
# define NO_MOVE_FRONT	"Resources/Leo/FP.png"
# define MOVE_1_FRONT	"Resources/Leo/FW1.png"
# define MOVE_2_FRONT	"Resources/Leo/FW2.png"
# define NO_MOVE_BACK	"Resources/Leo/BP.png"
# define MOVE_1_BACK	"Resources/Leo/BW1.png"
# define MOVE_2_BACK	"Resources/Leo/BW2.png"

typedef struct	s_sprite
{
  char		*name;
  int		room;
  int		right;
  sfVector2f	pos;
  sfVector2u	size;
  sfSprite	*sprite;
}		t_sprite;

typedef struct	s_moves
{
  sfSprite	*no_mov;
  sfSprite	*mov_1;
  sfSprite	*mov_2;
}		t_moves;

typedef struct	s_player
{
  t_moves	side[4];
  sfVector2i	pos;
  int		direction;
  t_sprite	*slot[6];
  float		scale;
  sfVector2i	dest;
  int		reset;
}		t_player;

int	print_wich_action(int *, t_sprite **, sfVector2i, t_player *);
void	get_action(int *, sfVector2i);
void	print_player(sfRenderWindow *, t_player *);
void	init_sprites_player(t_player *);
void	print_step(sfRenderWindow *, t_player *);
void	print_leo(t_player *, sfVector2f *, sfRenderWindow *, t_sprite **);
void	print_static(t_player *, sfVector2f, sfVector2f *, sfRenderWindow *);
void	print_leo_mov_right(t_player *, sfVector2f, sfVector2f *,
			    sfRenderWindow *);
void	print_leo_mov_left(t_player *, sfVector2f, sfVector2f *,
			   sfRenderWindow *);
void	update_pos(sfVector2f *, sfVector2i *, int *);
int	what_to_do(sfRenderWindow *, sfVector2i *, t_player *, int *);


#endif /* !PLAYER_H_*/
