/*
** my_strlen.c for tekad in /home/viktouille/MUL/tekadventure
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Fri May 26 17:19:08 2017 Victor CHAU
** Last update Sun May 28 20:39:11 2017 Victor CHAU
*/

int	my_strlen(char *str, char end)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != end)
    ++i;
  if (str[i] != '\0')
    ++i;
  return (i);
}
