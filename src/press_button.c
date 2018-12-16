/*
** press_button.c for tekad in /home/viktouille/MUL/tekadventure/src_victor
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Fri May 26 17:51:26 2017 Victor CHAU
** Last update Fri May 26 17:53:43 2017 Victor CHAU
*/

#include <SFML/Graphics.h>

int		exit_button(sfRenderWindow *window)
{
  sfVector2i	pos;

  pos = sfMouse_getPosition((sfWindow *)window);
  if (sfMouse_isButtonPressed(sfMouseLeft) == 1
      && pos.x > 1120 && pos.x < 1220
      && pos.y > 400 && pos.y < 430)
    return (1);
  return (0);
}

int		start_button(sfRenderWindow *window)
{
  sfVector2i	pos;

  pos = sfMouse_getPosition((sfWindow *)window);
  if (sfMouse_isButtonPressed(sfMouseLeft) == 1
      && pos.x > 1115 && pos.x < 1220
      && pos.y > 310 && pos.y < 335)
    return (1);
  return (0);
}
