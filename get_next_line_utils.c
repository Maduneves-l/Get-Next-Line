/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:39:06 by mneves-l          #+#    #+#             */
/*   Updated: 2023/05/02 13:44:29 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_line_size(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

char	*ft_newline(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(ft_line_size(s1) + ft_line_size(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	free(s1);
	return (str);
}

int	ft_check_buffer(char *buffer)
{
	int	i;
	int	j;
	int	new_buffer;

	i = 0;
	j = 0;
	new_buffer = 0;
	while (buffer[i] != 0 && buffer[i] != '\n')
		buffer[i++] = '\0';
	if (buffer[i] == '\n')
	{
		new_buffer = 1;
		buffer[i++] = '\0';
		while (buffer[i] != 0)
		{
			buffer[j++] = buffer[i];
			buffer[i++] = '\0';
		}
	}
	return (new_buffer);
}
