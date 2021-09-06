#include "../includes/pipex.h"

void	call_execve(char **cmd, char **envp)
{
	char	*path;

	path = get_path(envp, cmd);
	if (path == NULL || execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd("Command not found\n", 2);
		ft_putstr_fd(path, 2);
		exit(0);
	}
}

int	open_file(char *file_name, char **envp, int flags, int mode)
{
	char	*new_path;
	int		fd;

	while (*envp)
	{
		if (ft_strncmp("PWD=", *envp, 4) == 0)
		{
			new_path = ft_strjoin(*envp + 4, file_name);
			break ;
		}
		else
			envp++;
	}
	if ((flags == (O_RDWR | O_CREAT | O_TRUNC)) || ft_access(new_path))
	{
		if (mode)
			fd = open(new_path, flags, S_IREAD | S_IWRITE);
		else
			fd = open(new_path, flags, S_IREAD);
		free(new_path);
		return (fd);
	}
	free(new_path);
	return (-1);
}

static void	ft_pipex(char **argv, char **envp)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
	{
		ft_putstr_fd("Pipe failed\n", 2);
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Fork failed\n", 2);
		exit (1);
	}
	cf(p_fd, argv, envp, pid);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage : ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (0);
	}
	ft_pipex(argv, envp);
	return (0);
}
