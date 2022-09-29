#include "../incs/so_long.h"

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

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

void	ft_putunbr(int n)
{
	if (n > 9)
		ft_putunbr(n / 10);
	ft_putchar(n % 10 + 48);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}