/*
** my_str_isbinary.c for tekad in /home/viktouille/MUL/tekadventure
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Fri May 26 17:24:12 2017 Victor CHAU
** Last update Sun May 28 20:38:59 2017 Victor CHAU
*/

int	my_str_isbinary(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] !=  '0' && str[i] != '1' &&
	  str[i] != '\0' && str[i] != '\n' &&
	  str[i] != '\r')
	return (1);
      ++i;
    }
  return (0);
}
