/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaduan- <apaduan-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:51:55 by apaduan-          #+#    #+#             */
/*   Updated: 2021/07/26 04:18:03 by apaduan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	change_t(char **t, int size, char *buf) //t, size, buf
{
	char	*p; 

	if (!*t && size > 0)
		*t = ft_strdup(buf);
	else if (*t && size > 0)
	{
		p = ft_strdup(*t);
		free (*t);
		*t = ft_strjoin(p, buf);
		free (p);
	}
}

char *has_break(char **t)
{
	char *p[3];

	p[2] = ft_strchr(*t, '\n');
	p[0] = ft_substr(*t, 0, (p[2] - *t + 1));
	p[1] = ft_substr(*t, (p[2] - *t + 1), (ft_strlen(*t) + 1));
	free (*t);
	*t = ft_strdup(p[1]);
	free(p[1]);
	p[1] = 0;
	return (p[0]);
}

char	*get_next_line(int fd)
{
	char		*p[3];
	static char	*t;
	char		buf[BUFFER_SIZE + 1];
	int			size;

	size = 1;
	while (size > 0)
	{
		if (ft_strlen(t))
			if (ft_strchr(t, '\n'))
				return(has_break(&t));
		size = read (fd, buf, BUFFER_SIZE);
		buf[size] = 0;
		change_t(&t, size, buf);
		if (size == 0 && ft_strlen(t))
		{
			p[0] = ft_strdup(t);
			free (t);
			t = 0;
			return (p[0]);
		}
	}
	free(t);
	t = 0;
	return (NULL);
}
