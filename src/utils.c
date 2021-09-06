#include "../includes/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	int		c;
	char	*s3;

	a = ft_strlen((char *)s1);
	b = ft_strlen((char *)s2);
	s3 = malloc((a + b + 2) * sizeof(char));
	if (!(s3))
		return (NULL);
	a = 0;
	while (s1[a] != '\0')
	{
		s3[a] = s1[a];
		a++;
	}
	s3[a++] = '/';
	c = 0;
	while (s2[c] != '\0')
	{
		s3[a++] = s2[c];
		c++;
	}
	s3[a] = '\0';
	return (s3);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned int	i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] && n > i)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	while (str2[i] && n > i)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while ((src[i]) && dstsize - 1 > 0)
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

int	ft_access(char *path)
{
	if (access(path, F_OK) == -1 || access(path, R_OK) == -1
		|| access(path, W_OK) == -1)
	{
		ft_putstr_fd("File error\n", 2);
		return (0);
	}
	return (1);
}
