#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
int		ft_access(char *path);
char	*path_finder(char **path, char ***paths);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	cf(int *p, char **argv, char **envp, pid_t pid);
char	*get_path(char **envp, char **cmd);
void	call_execve(char **cmd, char **envp);
int		open_file(char *file_name, char **envp, int flags, int mode);
void	do_split_call_execve(char **argv, char **envp, pid_t pid);

#endif
