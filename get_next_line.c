/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaduan- <apaduan-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:51:55 by apaduan-          #+#    #+#             */
/*   Updated: 2021/07/24 22:40:01 by apaduan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*print;
	static char	*temp;
	static int	pass;
	char		*buffer[BUFFER_SIZE + 1];
	int			size;

	
	size = 1;
	while (size > 0)
	{
		if (temp > 0)
		{
			//procura '\n'
				//achou
					//print = print + começo da temp ate o '\n'
					//limpa temp
					//temp = substr (depois do '/n' até o final da temp)
					//pass += pass
					//return print
				//n achou
					//print = strjoin(print + temp)
		}
		size = read (fd, buffer, BUFFER_SIZE);
		buffer[size] = '\0';
		if (!temp && size > 0)
			//temp = strdup(buffer)
			//volta la pra cima
		else if (temp && size > 0)
			//temp = strjoin(temp + buffer)
		if (size == 0 && print > 0 && pass > 0)
			//print = strjoin (print, "\n")


	}
	
	
}	