/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:27:18 by mneves-l          #+#    #+#             */
/*   Updated: 2023/05/02 15:52:46 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	line = NULL;
	i = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		i = -1;
		if (fd >= 0 && fd <= FOPEN_MAX)
			while (buffer[fd][++i])
				buffer[fd][i] = 0;
		return (NULL);
	}
	while (i > 0)
	{
		if (!buffer[fd][0])
			i = read(fd, buffer[fd], BUFFER_SIZE);
		if (i > 0)
			line = ft_newline(line, buffer[fd]);
		if (ft_check_buffer(buffer[fd]) > 0)
			break ;
	}
	return (line);
}
