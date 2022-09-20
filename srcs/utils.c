#include "../incs/so_long.h"
/*
char	*ft_strstr(const char *haystack, const char *needle)
{
	ssize_t	i;
	ssize_t	j;
	i = -1;
	if (!needle || !haystack)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (*(haystack + ++i))
	{
		j = -1;
		while (*(haystack + i + ++j) == *(needle + j))
		{
			if (*(needle + j + 1) == '\0')
				return ((char *)(haystack + i));
		}
	}
	return (NULL);
}

void	*ft_memset(void *b, int c, size_t len)
{
	while (len)
		*(unsigned char *)(b + --len) = (unsigned char)c;
	return ((char *)b);
}*/

int		ft_strrnchr(const char *str, int c, size_t len)
{
	size_t	str_len;

	str_len = ft_strlen(str) - 1;
	if (len > str_len)
		len = str_len;
	while (*(str + str_len) && len--)
	{
		if (*(str + str_len--) == (unsigned char)c)
			return (1);
	}
	return (0);
}

int		ft_strnchr(const char *str, int c, size_t len)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	if (len > str_len)
		len = str_len;
	while (*str && len--)
	{
		if (*str++ == (unsigned char)c)
			return (1);
	}
	return (0);
}

size_t	ft_get_height(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return  (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}