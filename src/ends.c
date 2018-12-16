/*
** ends.c for ends in /home/samuel/MUL/tekadventure
** 
** Made by samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Wed May 24 01:33:35 2017 samuel
** Last update Sun May 28 17:00:58 2017 Victor CHAU
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "function.h"

void		bad_ending(sfRenderWindow *window)
{
  sfSprite	*sprite;

  sprite = sfSprite_create();
  cinematic(window, sprite, "Resources/Level/Bad Ending/Fin-B1.png");
  wait_voices("Resources/Level/Bad Ending/toctoc.wav",
	      "Resources/Level/Bad Ending/Fin-b1.wav", 0, window);
  cinematic(window, sprite, "Resources/Level/Bad Ending/Fin-B2.png");
  wait_voices("Resources/Level/Bad Ending/Fin-b2.wav",
	      "Resources/Level/Bad Ending/Fin-b3.wav", 0, window);
  credits(window, "Resources/Level/Credits/Sad_Violin.wav");
}

void		true_ending(sfRenderWindow *window)
{
  sfSprite	*sprite;

  sprite = sfSprite_create();
  cinematic(window, sprite, "Resources/Level/True Ending/Fin-T1.png");
  wait_voices("Resources/Level/True Ending/toctoc.wav",
	      "Resources/Level/True Ending/Fin_t1.wav", 0, window);
  cinematic(window, sprite, "Resources/Level/True Ending/Fin-T2.png");
  wait_voices(NULL, NULL, 3000, window);
  cinematic(window, sprite, "Resources/Level/True Ending/Fin-T3.png");
  wait_voices("Resources/Level/True Ending/Fin_t2.wav",
	      "Resources/Level/True Ending/Fin_t3.wav", 0, window);
  credits(window, "Resources/Level/Credits/Back_in_Black.wav");
}
