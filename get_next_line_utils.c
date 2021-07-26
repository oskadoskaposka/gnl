/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaduan- <apaduan-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:51:49 by apaduan-          #+#    #+#             */
/*   Updated: 2021/07/26 02:57:09 by apaduan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const char *src, unsigned int len)
{
	char	*cdest;
	char	*csrc;

	if (!dest && !src)
		return (dest);
	cdest = (char *)dest;
	csrc = (char *)src;
	while (len > 0)
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
		len--;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;
	size_t	size;

	i = 0;
	dest = malloc ((len + 1) * sizeof(char));
	if (!dest || !s)
		return (NULL);
	size = ft_strlen(s);
	while (((start + i) < size) && (s[start + i] != '\0') && (i < len))
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	if (!*s || !c)
		return (NULL);
	while (*s != (unsigned char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strdup(const char *str)
{
	int		len;
	char	*dest;

	len = ft_strlen(str) + 1;
	dest = malloc(len);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, str, len);
	return (dest);
}
