/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:59:41 by hprudhom          #+#    #+#             */
/*   Updated: 2021/01/13 14:03:25 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
