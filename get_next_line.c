/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:26:25 by mneves-l          #+#    #+#             */
/*   Updated: 2023/05/02 13:43:12 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	line = NULL;
	i = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		i = -1;
		while (buffer[++i])
			buffer[i] = 0;
		return (NULL);
	}
	while (i > 0)
	{
		if (!buffer[0])
			i = read(fd, buffer, BUFFER_SIZE);
		if (i > 0)
			line = ft_newline(line, buffer);
		if (ft_check_buffer(buffer) > 0)
			break ;
	}
	return (line);
}
