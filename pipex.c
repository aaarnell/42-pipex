#include "pipex.h"

void	ft_exit(int err, char *str)
{
	if (str)
	{
		write(2, "ERROR: ", 7);
		write(2, str, ft_strlen(str));
		write(2, "\n", 2);
	}
	else
		perror("ERROR");
	exit(err);
}

static char	*search_path(char *s_path, char *cmd)
{
	char	*res;
	char	*res2;
	char	**path;
	int		j;

	j = 0;
	path = ft_split(s_path, ':');
	while (path[j])
	{
		res = ft_strjoin(path[j], "/");
		res2 = ft_strjoin(res, cmd);
		if (access(res2, 0) == 0)
		{
			free(res);
			ft_frmtrx(path);
			return (res2);
		}
		free(res);
		free(res2);
		j++;
	}
	if (path)
		ft_frmtrx(path);
	return (NULL);
}

static char	*get_path(char **envp, char *cmd)
{
	int		i;
	char	*rs;

	i = 0;
	while (envp[i] && cmd[0] != '/' && cmd[0] != '.')
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			rs = search_path(envp[i] + 5, cmd);
			if (rs)
				return (rs);
		}
		i++;
	}
	if (cmd[0] == '/')
		if (access(cmd, 0) == 0)
			return (cmd);
	return (NULL);
}

void	call_father(int *fd, int out, char **argv, char **envp)
{
	char	**cmd;
	char	*path;

	wait(0);
	close(fd[1]);
	if (dup2(fd[0], 0) == -1 || dup2(out, 1) == -1)
		ft_exit(errno, NULL);
	cmd = ft_split(argv[3], ' ');
	path = get_path(envp, cmd[0]);
	if (!path)
	{
		ft_frmtrx(cmd);
		ft_exit(0, "The path to execute the parent command was not found.");
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_frmtrx(cmd);
		ft_exit(errno, NULL);
	}
	free(path);
	ft_frmtrx(cmd);
	close(fd[0]);
	close(out);
}

void	call_child(int *fd, int in, char **argv, char **envp)
{
	char	**cmd;
	char	*path;

	close(fd[0]);
	if (dup2(fd[1], 1) == -1 || dup2(in, 0) == -1)
		ft_exit(errno, NULL);
	cmd = ft_split(argv[2], ' ');
	path = get_path(envp, cmd[0]);
	if (!path)
	{
		ft_frmtrx(cmd);
		ft_exit(0, "The path to execute the desc. command was not found.");
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		ft_frmtrx(cmd);
		ft_exit(errno, NULL);
	}
	free(path);
	ft_frmtrx(cmd);
	close(fd[1]);
	close(in);
}
