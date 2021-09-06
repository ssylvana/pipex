#include"../includes/pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == (NULL))
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

char	*path_finder(char **path, char ***paths)
{
	while (**paths)
		(*paths)++;
	(*paths)--;
	while (*(*paths))
		free(*(*paths)--);
	(*paths)++;
	free(*paths);
	return (*path);
}
