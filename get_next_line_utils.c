#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char *str;

	str = (unsigned char*)s;
	while (n--)
	{
		*str = '\0';
		str++;
	}
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*str;

	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	ft_strcpy(str, s);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		x;
	int		y;

	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	x = 0;
	y = 0;
	while (s1[x])
	{
		str[y] = s1[x];
		y++;
		x++;
	}
	x = 0;
	while (s2[x])
	{
		str[y] = s2[x];
		y++;
		x++;
	}
	str[y] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		x;
	char				*dst;
	size_t				len_s;

	len_s = len;
	if (start > (unsigned int)ft_strlen(s) - 1)
	{
		if (!(dst = malloc(sizeof(char))))
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	if ((size_t)start + len > (size_t)ft_strlen(s))
		len_s = (size_t)ft_strlen(s) - (size_t)start;
	if (!(dst = malloc(sizeof(char) * (len_s + 1))))
		return (NULL);
	x = 0;
	while (x < len_s)
	{
		dst[x] = s[start];
		x++;
		start++;
	}
	dst[x] = '\0';
	return (dst);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t i;

	i = ft_strlen(src);
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (dst - i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char*)s);
	return (NULL);
}

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
		ft_memdel((void**)as);
}

////

// char	*ft_strsub(char const *s, unsigned int start, size_t len)
// {
// 	char	*subs;
// 	size_t	i;

// 	if (s == NULL)
// 		return (NULL);
// 	subs = ft_strnew(len);
// 	if (subs == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		subs[i] = s[start + i];
// 		i++;
// 	}
// 	return (subs);
// }

// void	ft_memdel(void **ap)
// {
// 	if (ap != NULL)
// 	{
// 		free(*ap);
// 		*ap = NULL;
// 	}
// }

// char	*ft_strcpy(char *dst, const char *src)
// {
// 	int i;

// 	i = 0;
// 	while (src[i] != '\0')
// 	{
// 		dst[i] = src[i];
// 		i += 1;
// 	}
// 	dst[i] = src[i];
// 	return (dst);
// }

// char	*ft_strcat(char *dst, const char *src)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (dst[i] != '\0')
// 		i++;
// 	while (src[j] != '\0')
// 	{
// 		dst[i] = src[j];
// 		i++;
// 		j++;
// 	}
// 	dst[i] = '\0';
// 	return (dst);
// }

// size_t	ft_strlen(const char *str)
// {
// 	int	size;

// 	size = 0;
// 	while (str[size] != '\0')
// 	{
// 		size += 1;
// 	}
// 	return (size);
// }

// char	*ft_strnew(size_t size)
// {
// 	char	*str;
// 	size_t	i;

// 	i = 0;
// 	str = (char *)malloc(sizeof(*str) * size + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	while (i <= size)
// 	{
// 		str[i] = '\0';
// 		i++;
// 	}
// 	return (str);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*s == c)
// 			return ((char*)s);
// 		s++;
// 	}
// 	if (*s == c)
// 		return ((char*)s);
// 	return (NULL);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		strlen;
// 	char	*str;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	strlen = ft_strlen(s1) + ft_strlen(s2);
// 	str = ft_strnew(strlen);
// 	if (str == NULL)
// 		return (NULL);
// 	ft_strcpy(str, s1);
// 	ft_strcat(str, s2);
// 	return (str);
// }

// void	ft_strdel(char **as)
// {
// 	if (as != NULL && *as != NULL)
// 		ft_memdel((void**)as);
// }

// char	*ft_strdup(const char *s1)
// {
// 	int		i;
// 	int		size;
// 	char	*str;

// 	i = 0;
// 	size = 0;
// 	while (s1[size])
// 		size += 1;
// 	str = (char*)malloc(sizeof(*str) * size + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	while (i < size)
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	str[size] = '\0';
// 	return (str);
// }