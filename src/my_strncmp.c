/*
** my_strncmp.c for tekad in /home/viktouille/MUL/tekadventure
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Fri May 26 17:20:11 2017 Victor CHAU
** Last update Fri May 26 17:20:41 2017 Victor CHAU
*/

int	my_strncmp(char *str1, char *str2, int n)
{
  int	i;

  i = 0;
  while (str1[i] != '\0' && i < n)
    {
      if (str1[i] != str2[i])
	return (1);
      ++i;
    }
  return (0);
}
