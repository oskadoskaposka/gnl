/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaduan- <apaduan-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:51:55 by apaduan-          #+#    #+#             */
/*   Updated: 2021/07/26 01:18:37 by apaduan-         ###   ########.fr       */
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

void	*ft_memcpy (void *dest, const char *src, unsigned int len)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	dest = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}


char	*get_next_line(int fd)
{
	char		*print[3]; 
	static char	*temp;
	char		buf[BUFFER_SIZE + 1];
	int			size;

	size = 1;
	print[0] = 0;
	while (size > 0)
	{
		if (ft_strlen(temp))
		{
			print[2] = ft_strchr(temp, '\n');
			if (print[2]) 
			{
				print[0] = ft_substr(temp, 0, (print[2] - temp + 1)); 
				print[1] = ft_substr(temp, (print[2] - temp + 1), (ft_strlen(temp) + 1)); 
				free (temp); 
				temp = ft_strdup(print[1]); 
				free(print[1]);
				print[1] = 0;
				return (print[0]); 
			}
			else
			{
				print[0] = ft_strdup(temp); 
			}
		}
		size = read (fd, buf, BUFFER_SIZE);
		buf[size] = 0;
		if (!temp && size > 0)
		{
			temp = ft_strdup(buf); 
		}
		else if (temp && size > 0)
		{
			print[1] = ft_strdup(temp);
			free (temp);
			temp = ft_strjoin(print[1], buf); //temp = strjoin(temp + buffer)
			free (print[1]);
		}
		if (size == 0 && ft_strlen(print[0]) > 0)
		{
			free (temp);
			temp = 0;
			return (print[0]);
		}
	}
	free(temp);
	temp = 0;
	return (NULL);
	
}	