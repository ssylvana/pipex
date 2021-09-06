#include "../includes/pipex.h"

char	*get_path(char **envp, char **cmd)
{
	char	**paths;
	char	*path;

	while (*envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
		{
			paths = ft_split(*envp + 5, ':');
			while (*paths)
			{
				path = ft_strjoin(*paths, *cmd);
				if (access(path, F_OK) == 0)
					return (path_finder(&path, &paths));
				free(path);
				paths++;
			}
			return (NULL);
		}
		else
			envp++;
	}
	return (NULL);
}

void	cf(int *p, char **argv, char **envp, pid_t pid)
{
	int		in;
	int		out;

	if (pid == 0)
	{
		close(p[0]);
		dup2(p[1], 1);
		close(p[1]);
		in = open_file(argv[1], envp, O_RDONLY, 0);
		if (in == -1)
			exit(0);
		dup2(in, 0);
		do_split_call_execve(argv, envp, pid);
	}
	else
	{
		out = open_file(argv[4], envp, O_RDWR | O_CREAT | O_TRUNC, 1);
		wait(0);
		close(p[1]);
		dup2(p[0], 0);
		close(p[0]);
		dup2(out, 1);
		do_split_call_execve(argv, envp, pid);
	}
}

void	do_split_call_execve(char **argv, char **envp, pid_t pid)
{
	char	**cmd;

	cmd = NULL;
	if (pid == 0)
	{
		cmd = ft_split(argv[2], ' ');
		call_execve(cmd, envp);
	}
	else
	{
		cmd = ft_split(argv[3], ' ');
		call_execve(cmd, envp);
	}
}
