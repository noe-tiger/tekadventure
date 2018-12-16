/*
** get_file_content.c for tekad in /home/viktouille/MUL/tekadventure
** 
** Made by Victor CHAU
** Login   <viktouille@epitech.net>
** 
** Started on  Fri May 26 17:27:35 2017 Victor CHAU
** Last update Fri May 26 23:17:42 2017 Victor CHAU
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char		*get_file_content(char *name)
{
  struct stat	buf;
  int		fd;
  char		*buffer;

  if (stat(name, &buf) == -1 ||
      (fd = open(name, O_RDONLY)) == -1 ||
      (buffer = malloc(sizeof(char) * (buf.st_size + 2))) == NULL ||
      read(fd, buffer, buf.st_size) == -1)
    return (NULL);
  (buffer[buf.st_size - 1] != '\n') ?
    ((buffer[buf.st_size] = '\n') && (buffer[buf.st_size + 1] = '\0')) :
    (buffer[buf.st_size] = '\0');
  close(fd);
  return (buffer);
}
