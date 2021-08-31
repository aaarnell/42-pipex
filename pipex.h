#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

void	ft_exit(int err, char *str);
void	call_father(int *fd, int out, char **argv, char **envp);
void	call_child(int *fd, int in, char **argv, char **envp);

#endif
