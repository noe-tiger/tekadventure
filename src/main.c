/*
** main.c for main in /home/samuel/Rush/scroller
** 
** Made by samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Fri Mar 31 20:48:18 2017 samuel
** Last update Mon May 29 23:09:45 2017 Victor CHAU
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "function.h"
#include "macro.h"
#include "cursor.h"
#include "var.h"

static t_var	*init_loop(sfRenderWindow *window, t_var *var)
{
  var->avertisment = get_sprite("Resources/Confirmation_joffrey.png");
  my_putstr("generating maps...\n");
  generate_maps(var->map);
  my_putstr("maps successfully generated !\n");
  var->room = "couloir_25_26.png";
  my_putstr("parsing the tka files...\n");
  if ((var->buffer = parse_my_file()) == NULL)
    return (NULL);
  my_putstr("tka files successfully parsed !\n");
  init_sprites_player(&(var)->player);
  var->curs = get_sprite("Resources/cursor.png");
  var->inventory = get_sprite("Resources/Level/Inv.png");
  my_putstr("generating PNJ's sprites...\n");
  var->sprites = generate_sprites();
  my_putstr("generating objects's sprites...\n");
  var->obj = generate_items();
  my_putstr("game begin !\n");
  if (menu(window, var->curs) == 2)
    return (NULL);
  var->player.reset = 0;
  return (var);
}

static void	loop_me(t_var *var, sfRenderWindow *window)
{
  while (sfRenderWindow_hasFocus(window) == 0)
    ;
  cursor(window, var->curs);
  sfRenderWindow_clear(window, sfBlack);
  while (sfRenderWindow_pollEvent(window, &(var)->event))
    if ((var->event.type == sfEvtClosed)
	|| (var->event.type == sfEvtKeyPressed &&
	    var->event.key.code == sfKeyEscape))
      sfRenderWindow_close(window);
  print_maps(var->map, var->room, window);
  render_sprites(var->sprites, window, var->room);
  print_leo(&(var)->player, &(var)->pos, window, var->obj);
  if (change_room((sfVector2i) {var->player.pos.x + 100,
	  var->player.pos.y + 250}
      , var->buffer, var->room) != NULL)
    {
      var->player.reset = 1;
      var->room = change_room((sfVector2i) {var->player.pos.x + 100,
	    var->player.pos.y + 250}
	, var->buffer, var->room);
      var->val = 2;
      move(window, &(var)->val, 0, &(var)->player);
    }
  var->val = 0;
}

static char	*main_loop(sfRenderWindow *window)
{
  if (init_loop(window, &zar) == NULL)
    return (NULL);
  intro(window);
  while (sfRenderWindow_isOpen(window))
    {
      loop_me(&zar, window);
      if ((zar.val = last_choice(zar.room, &(zar).player, window,
				 zar.avertisment)) == 0)
	return (NULL);
      if (zar.val == 42)
	zar.room = "sm24.png";
      sfRenderWindow_drawSprite(window, zar.inventory, NULL);
      render_objects(zar.obj, window, zar.room, &(zar).player);
      sfRenderWindow_drawSprite(window, zar.curs, NULL);
      sfRenderWindow_display(window);
    }
  return (NULL);
}

int			main()
{
  sfVideoMode		mode = {WIDTH, HEIGHT, BIT_PER_PIXEL};
  sfRenderWindow	*window;
  int			i;

  i = 0;
  window = sfRenderWindow_create(mode, "The Legend of Leo - Breath of the Tek",
				 sfResize | sfClose, NULL);
  if (!window)
    return (EXIT_WINDOW_FAILURE);
  sfWindow_setMouseCursorVisible((sfWindow *)window, 0);
  while (i < 50)
    {
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_drawSprite(window, get_sprite
				("Resources/Loading.png"), NULL);
      sfRenderWindow_display(window);
      i++;
    }
  if (main_loop(window) == NULL)
    return (-1);
  return (EXIT_SUCCESS);
}
