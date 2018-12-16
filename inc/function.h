/*
** function.h for  in /home/noe/test/tekadventure/src
** 
** Made by Noé
** Login   <noe@epitech.net>
** 
** Started on  Mon May 29 21:15:23 2017 Noé
** Last update Mon May 29 21:15:23 2017 Noé
*/

#ifndef FUNCTION_H_
# define FUNCTION_H_

# include <SFML/Graphics.h>
# include <SFML/Audio.h>
# include "cursor.h"
# include "file_prop.h"

void		victor_fail(sfRenderWindow *);
void		print_money(t_sprite **, sfRenderWindow *, t_player *);
void		alex_fail(sfRenderWindow *);
void		wich_slot(t_sprite **, t_player *, int, int);
void		get_inventory(t_sprite **, sfVector2i, t_player *);
void		grab_sprite(t_sprite **, t_sprite *, int);
int		use_inventory(sfVector2i, t_player *);
int		give_inventory(sfVector2i);
t_file_prop	*extract_content(t_file_prop *, char *);
char		*get_file_content(char *);
char		**manage_my_tab(char *, char);
char		*my_dupline(char *, int);
t_file_prop	*parse_my_file(void);
t_file_prop	*my_put_files_in_list(t_file_prop *, char *);
t_file_prop	*my_put_rooms_in_files_list(t_file_prop *,
					    char *, sfVector2i, sfVector2i);
char		*change_room(sfVector2i, t_file_prop *, char *);
int		my_getnbr(char *);
int		my_strlen(char *, char);
char		*my_strcat(char *, char *);
char		*my_strcat_free(char *, char *);
int		my_strncmp(char *, char *, int);
int		my_str_isbinary(char *);
int		verif_extension(char *);

void		print_static(t_player *, sfVector2f,
			     sfVector2f *, sfRenderWindow *);
void		print_leo_mov_left(t_player *, sfVector2f,
				   sfVector2f *, sfRenderWindow *);
void		print_leo_mov_right(t_player *, sfVector2f,
				    sfVector2f *, sfRenderWindow *);
void		print_move(t_player *, sfVector2f *,
			   sfRenderWindow *, sfVector2f);
int		what_to_do(sfRenderWindow *, sfVector2i *, t_player *, int *);
void		update_pos(sfVector2f *, sfVector2i *, int *);

int		exit_button(sfRenderWindow *);
int		start_button(sfRenderWindow *);
void		free_files(t_file_prop *);
void		bad_ending(sfRenderWindow *);
void		intro(sfRenderWindow *);
void		cinematic(sfRenderWindow *, sfSprite *, char *);
void		credits(sfRenderWindow *, char *);
int		menu(sfRenderWindow *, sfSprite *);
void		true_ending(sfRenderWindow *);
void		wait_voices(char *, char *, int, sfRenderWindow *);
void		render_window(sfRenderWindow *, sfSprite *,
			      sfSprite *, sfSprite *);
int		my_strcmp(char *, char *);
void		my_putstr(char *);
int		last_choice(char *, t_player *,
			    sfRenderWindow *, sfSprite *);
void		get_redbull(t_sprite **, sfRenderWindow *, char *,
			    t_player *);
void		get_money(t_sprite **, sfRenderWindow *,
		  char *, t_player *);
void		get_kinder(t_sprite **, sfRenderWindow *, char *,
		   t_player *);
t_sprite	**generate_sprites();
t_sprite	**generate_items();
void		generate_maps(t_map *);
void		sprite_gen_money(t_sprite **);
void		sprite_gen_kinder(t_sprite **);
void		sprite_gen_redbull(t_sprite **);
void		sprite_gen_cofee(t_sprite **);
void		sprite_gen_victor(t_sprite **);
void		sprite_gen_noe(t_sprite **);
void		sprite_gen_alex(t_sprite **);
void		print_kinder(t_sprite **, sfRenderWindow *,
			     t_player *);
void		clock_redbull(sfMusic *);

#endif /*  FUNCTION_H_  */
