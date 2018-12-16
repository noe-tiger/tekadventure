/*
** menu.c for tekad in /home/viktouille/MUL/tekadventure
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Wed Apr 19 14:32:18 2017 Victor CHAU
** Last update Sun May 28 17:18:15 2017 Victor CHAU
*/

#include <SFML/Graphics.h>
#include "function.h"
#include "menu.h"
#include "macro.h"
#include "cursor.h"

static void	put_sprite(sfRenderWindow *window, sfSprite *wallpaper,
			   sfSprite *leo, sfSprite *button)
{
  sfVector2f	wallpaper_pos;
  sfVector2f	leo_pos;
  sfVector2f	button_pos;
  sfVector2i	mouse_pos;

  mouse_pos = sfMouse_getPosition((sfWindow *)window);
  wallpaper_pos.x = mouse_pos.x / 128 - 15;
  wallpaper_pos.y = mouse_pos.y / 72 - 15;
  sfSprite_setPosition(wallpaper, wallpaper_pos);
  leo_pos.x = mouse_pos.x / 256 - 1280 / 3;
  leo_pos.y = mouse_pos.y / 144 - 720 / 3 + 10;
  sfSprite_setPosition(leo, leo_pos);
  button_pos.x = 920;
  button_pos.y = 0;
  sfSprite_setPosition(button, button_pos);
}

static int	put_texture(t_menu *menu)
{
  sfTexture	*texture;
  sfVector2f	zoom;

  (*menu).wallpaper = sfSprite_create();
  (*menu).leo = sfSprite_create();
  (*menu).button = sfSprite_create();
  texture = sfTexture_createFromFile(WALLPAPER, NULL);
  if (texture == NULL || (*menu).leo == NULL || (*menu).wallpaper == NULL)
    return (-1);
  zoom.x = 1.1;
  zoom.y = 1.1;
  sfSprite_setTexture((*menu).wallpaper, texture, sfTrue);
  sfSprite_scale((*menu).wallpaper, zoom);
  if ((texture = sfTexture_createFromFile(LEO, NULL)) == NULL)
    return (-1);
  zoom.x = 1.4;
  zoom.y = 1.4;
  sfTexture_setSmooth(texture, sfTrue);
  sfSprite_setTexture((*menu).leo, texture, sfTrue);
  sfSprite_scale((*menu).leo, zoom);
  if ((texture = sfTexture_createFromFile(BUTTON, NULL)) == NULL)
    return (-1);
  sfSprite_setTexture((*menu).button, texture, sfTrue);
  return (0);
}

static void	selector(sfRenderWindow *window, sfSprite *select)
{
  sfVector2i	pos;
  sfVector2f	pos_start;
  sfVector2f	pos_end;
  sfVector2f	pos_useless;
  sfVector2f	invisible;

  pos = sfMouse_getPosition((sfWindow *)window);
  pos_start.x = 1000;
  pos_start.y = 250;
  pos_end.x = 1010;
  pos_end.y = 345;
  pos_useless.x = 960;
  pos_useless.y = 300;
  invisible.x = -200;
  invisible.y = -200;
  if (pos.x > 1115 && pos.x < 1220 && pos.y > 310 && pos.y < 335)
    sfSprite_setPosition(select, pos_start);
  else if (pos.x > 1120 && pos.x < 1220 && pos.y > 400 && pos.y < 430)
    sfSprite_setPosition(select, pos_end);
  else if (pos.x > 1075 && pos.x < 1200 && pos.y > 360 && pos.y < 380)
    sfSprite_setPosition(select, pos_useless);
  else
    sfSprite_setPosition(select, invisible);
}

static void	ping_event(sfRenderWindow *window, t_menu menu,
			   sfSprite *sprite_cursor, sfSprite *select)
{
  cursor(window, sprite_cursor);
  put_sprite(window, menu.wallpaper, menu.leo, menu.button);
  sfRenderWindow_clear(window, sfBlack);
  if (menu.wallpaper != NULL && menu.leo != NULL && menu.button != NULL)
    render_window(window, menu.wallpaper, menu.leo, menu.button);
  sfRenderWindow_drawSprite(window, sprite_cursor, NULL);
  sfRenderWindow_drawSprite(window, select, NULL);
  sfRenderWindow_display(window);
}

int		menu(sfRenderWindow *window, sfSprite *sprite_cursor)
{
  sfEvent	event;
  t_menu	menu;
  sfSprite	*select;

  select = get_sprite("Resources/Level/Main Menu/Selector.png");
  if (put_texture(&menu) == -1)
    return (84);
  while (sfRenderWindow_isOpen(window))
    {
      ping_event(window, menu, sprite_cursor, select);
      while (sfRenderWindow_pollEvent(window, &event))
	if ((event.type == sfEvtClosed)
	    || (event.type == sfEvtKeyPressed &&
		event.key.code == sfKeyEscape))
	  return (2);
      if (exit_button(window) == 1)
	return (2);
      if (start_button(window) == 1)
	return (1);
      selector(window, select);
    }
  return (0);
}
