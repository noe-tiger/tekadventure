/*
** intro.c for intro in /home/samuel/Mul/tekadventure
** 
** Made by samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Mon Apr 24 17:10:33 2017 samuel
** Last update Sun May 28 23:29:31 2017 Victor CHAU
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "function.h"

void	intro_1(sfRenderWindow *window, sfSprite *sprite)
{
  cinematic(window, sprite, "Resources/Level/Intro/Intro-1-1.png");
  wait_voices(NULL, NULL, 3000, window);
  cinematic(window, sprite, "Resources/Level/Intro/Intro-1-2.png");
  wait_voices("Resources/Level/Intro/intro1.wav", NULL, 1000, window);
  cinematic(window, sprite, "Resources/Level/Intro/Intro-1-3.png");
  wait_voices("Resources/Level/Intro/intro2.wav",
	      "Resources/Level/Intro/intro3.wav", 1000, window);
}

void	intro_2(sfRenderWindow *window, sfSprite *sprite)
{
  cinematic(window, sprite, "Resources/Level/Intro/Intro-2-1.png");
  wait_voices("Resources/Level/Intro/intro4.wav", NULL, 1000, window);
  cinematic(window, sprite, "Resources/Level/Intro/Intro-2-2.png");
  wait_voices("Resources/Level/Intro/intro5.wav", NULL, 1000, window);
  cinematic(window, sprite, "Resources/Level/Intro/Intro-2-3.png");
  wait_voices("Resources/Level/Intro/intro6.wav",
	      "Resources/Level/Intro/intro7.wav", 500, window);
}

void	intro_3(sfRenderWindow *window, sfSprite *sprite)
{
  cinematic(window, sprite, "Resources/Level/Intro/Intro-3-1.png");
  wait_voices(NULL, NULL, 3000, window);
  cinematic(window, sprite, "Resources/Level/Intro/Intro-3-2.png");
  wait_voices("Resources/Level/Intro/intro8.wav",
	      "Resources/Level/Intro/intro9.wav", 500, window);
}

void		intro(sfRenderWindow *window)
{
  sfSprite	*sprite;

  sprite = sfSprite_create();
  intro_1(window, sprite);
  intro_2(window, sprite);
  intro_3(window, sprite);
}
