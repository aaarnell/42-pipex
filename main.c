#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		in;
	int		out;
	int		err;
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		ft_exit(0, "Invalid number of arguments.\n");
	in = open(argv[1], O_RDONLY);
	out = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, S_IWRITE | S_IREAD);
	err = pipe(fd);
	pid = fork();
	if (in == -1 || out == -1 || err == -1 || pid == -1)
		ft_exit(errno, NULL);
	if (pid)
		call_father(fd, out, argv, envp);
	else
		call_child(fd, in, argv, envp);
	return (0);
}
