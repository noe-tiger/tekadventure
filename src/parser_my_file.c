/*
** parser_my_file.c for tekad in /home/viktouille/MUL/tekadventure/src_victor
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Thu May 25 14:42:59 2017 Victor CHAU
** Last update Sun May 28 18:10:14 2017 Noé
*/

#include <stdlib.h>
#include "function.h"
#include "file_prop.h"
#include "macro.h"

static t_file_prop	*open_and_manage_my_file(t_file_prop *files)
{
  char			*name_buffer;
  char			*contents;
  t_file_prop		*tmp;

  tmp = files;
  while (tmp != NULL)
    {
      if ((name_buffer = my_strcat(PATH, tmp->file_name)) == NULL)
	return (NULL);
      contents = get_file_content(name_buffer);
      if (contents != NULL && (tmp = extract_content(tmp, contents)) == NULL)
	{
	  free(contents);
	  return (NULL);
	}
      else if (contents == NULL)
	return (NULL);
      tmp = tmp->next;
      free(contents);
      free(name_buffer);
    }
  return (files);
}

t_file_prop	*parse_my_file(void)
{
  int		i;
  char		*all_tka;
  char		**tka_in_wordtab;
  t_file_prop	*files;

  i = 0;
  files = NULL;
  if ((all_tka = get_file_content("init.tka")) == NULL ||
      (tka_in_wordtab = manage_my_tab(all_tka, '\n')) == NULL)
    return (NULL);
  while (tka_in_wordtab[i] != NULL)
    if (verif_extension(tka_in_wordtab[i++]) == 0)
      if ((files = my_put_files_in_list(files, tka_in_wordtab[i - 1])) == NULL)
	return (NULL);
  if ((files = open_and_manage_my_file(files)) == NULL)
    return (NULL);
  return (files);
}
