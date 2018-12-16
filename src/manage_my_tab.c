/*
** manage_my_tab.c for tekad in /home/viktouille/PSU/PSU_2016_minishell2/src
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Fri May 26 10:39:15 2017 Victor CHAU
** Last update Fri May 26 16:59:51 2017 Victor CHAU
*/

#include <stdlib.h>
#include <unistd.h>

static char	**mem_alloc_array_enhanced(int nb_cols, char *buffer,
					   char separator)
{
  char		**tab;
  int		i;
  int		rows;
  int		malloc_size;

  i = 0;
  rows = 0;
  malloc_size = 0;
  if ((tab = malloc(sizeof(char*) * (nb_cols + 2))) == NULL)
    return (NULL);
  while (buffer[i] != '\0')
    {
      malloc_size++;
      if (buffer[i] == separator || buffer[i + 1] == '\0')
	{
	  if ((tab[rows++] = malloc(sizeof(char) * (malloc_size + 3))) == NULL)
	    return (NULL);
	  malloc_size = 0;
	}
      i++;
    }
  return (tab);
}

static char	**my_str_to_wordtab(char *buffer, char **tab, char separator)
{
  int		rows;
  int		cols;
  int		i;

  if (tab == NULL && write(2, "malloc error\n", 13))
    return (NULL);
  rows = 0;
  cols = 0;
  i = 0;
  while (buffer[i] != '\0')
    {
      tab[rows][cols] = buffer[i++];
      if (buffer[i - 1] == separator || buffer[i] == '\0')
	{
	  tab[rows][cols] = '\0';
	  cols = -1;
	  rows++;
	}
      cols++;
    }
  tab[rows] = NULL;
  return (tab);
}

char		**manage_my_tab(char *buffer, char separator)
{
  char		**tab;
  int		cols;
  int		i;

  cols = 0;
  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == separator)
	cols++;
      i++;
    }
  tab = mem_alloc_array_enhanced((cols + 1), buffer, separator);
  tab = my_str_to_wordtab(buffer, tab, separator);
  return (tab);
}
