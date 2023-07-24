/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadzic <ahadzic@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:38:45 by ahadzic           #+#    #+#             */
/*   Updated: 2022/09/21 14:39:17 by ahadzic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left_line;
	char		*return_line;
	char		*readed;
	int			size;

	readed = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	size = read(fd, readed, BUFFER_SIZE);
	readed[size] = '\0';
	if (size > 0)
		left_line = ft_strjoin(left_line, readed);
	while (size > 0 && !ft_newline(readed))
	{
		size = read(fd, readed, BUFFER_SIZE);
		readed[size] = 0;
		left_line = ft_strjoin(left_line, readed);
	}
	free(readed);
	return_line = ft_substr(left_line);
	left_line = ft_get_left_line(left_line);
	return (return_line);
}
